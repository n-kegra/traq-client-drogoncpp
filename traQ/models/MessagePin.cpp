#include <traQ/models/MessagePin.h>

namespace traQApi {

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
template <> traQApi::MessagePin Json::Value::as<traQApi::MessagePin>() const {
    return traQApi::MessagePin(*this);
}
