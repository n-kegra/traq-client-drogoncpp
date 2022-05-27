#include "MessagePin.h"

namespace traQAPI {

Json::Value MessagePin::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["pinnedAt"] = (pinnedAt);
    return _json;
}
MessagePin& MessagePin::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    pinnedAt = _json["pinnedAt"].as<std::string>();
    return *this;
}

}
template <> traQAPI::MessagePin Json::Value::as<traQAPI::MessagePin>() const {
    return traQAPI::MessagePin(*this);
}
