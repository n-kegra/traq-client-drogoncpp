#include <traQ/models/BotState.h>
#include "../Helper.h"

namespace traQApi {

BotState::BotState() { value = Value::Unknown; };
BotState::operator Json::Value() const {
    return this->toJson();
}
BotState::BotState(const Json::Value& __value) {
    this->fromJson(__value);
}
BotState::BotState(const Value __value) : value(__value) {}

Json::Value BotState::toJson() const {
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
BotState& BotState::fromJson(const Json::Value& _json) {
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
template <> traQApi::BotState Json::Value::as<traQApi::BotState>() const {
    return traQApi::BotState(*this);
};
