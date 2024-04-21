#include <traQ/models/ChannelSubscribeLevel.h>

namespace traQApi {

ChannelSubscribeLevel::ChannelSubscribeLevel() { value = Value::Unknown; };
ChannelSubscribeLevel::operator Json::Value() const {
    return this->toJson();
}
ChannelSubscribeLevel::ChannelSubscribeLevel(const Json::Value& __value) {
    this->fromJson(__value);
}
ChannelSubscribeLevel::ChannelSubscribeLevel(const Value __value) : value(__value) {}

Json::Value ChannelSubscribeLevel::toJson() const {
    switch(this->value) {
    case Value::e0:
        return Json::Value(0);
    case Value::e1:
        return Json::Value(1);
    case Value::e2:
        return Json::Value(2);
    default:
        return Json::Value(Json::nullValue);
    }
}
ChannelSubscribeLevel& ChannelSubscribeLevel::fromJson(const Json::Value& _json) {
    auto s = _json.asLargestInt();
    if (s == 0) {
        this->value = Value::e0;
    } else
    if (s == 1) {
        this->value = Value::e1;
    } else
    if (s == 2) {
        this->value = Value::e2;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQApi::ChannelSubscribeLevel Json::Value::as<traQApi::ChannelSubscribeLevel>() const {
    return traQApi::ChannelSubscribeLevel(*this);
};
