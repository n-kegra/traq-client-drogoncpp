#include "BotState.h"

namespace traQ {

Json::Value BotState::toJson() const {
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
template <> traQ::BotState Json::Value::as<traQ::BotState>() const {
    return traQ::BotState(*this);
}
