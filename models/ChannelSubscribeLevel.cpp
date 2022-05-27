#include "ChannelSubscribeLevel.h"

namespace traQAPI {

Json::Value ChannelSubscribeLevel::toJson() const {
    switch(this->value) {
    case Value::e0:
        return Json::Value(0);
    case Value::e1:
        return Json::Value(1);
    case Value::e2:
        return Json::Value(2);
    case Value::Unknown:
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
template <> traQAPI::ChannelSubscribeLevel Json::Value::as<traQAPI::ChannelSubscribeLevel>() const {
    return traQAPI::ChannelSubscribeLevel(*this);
}
