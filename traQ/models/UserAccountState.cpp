#include <traQ/models/UserAccountState.h>

namespace traQApi {

UserAccountState::UserAccountState() { value = Value::Unknown; };
UserAccountState::operator Json::Value() const {
    return this->toJson();
}
UserAccountState::UserAccountState(const Json::Value& __value) {
    this->fromJson(__value);
}
UserAccountState::UserAccountState(const Value __value) : value(__value) {}

Json::Value UserAccountState::toJson() const {
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
UserAccountState& UserAccountState::fromJson(const Json::Value& _json) {
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
template <> traQApi::UserAccountState Json::Value::as<traQApi::UserAccountState>() const {
    return traQApi::UserAccountState(*this);
};
