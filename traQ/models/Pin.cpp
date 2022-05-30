#include <traQ/models/Pin.h>

namespace traQApi {

Json::Value Pin::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["pinnedAt"] = (pinnedAt);
    _json["message"] = (message.toJson());
    return _json;
}
Pin& Pin::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    pinnedAt = _json["pinnedAt"].as<std::string>();
    message.fromJson(_json["message"]);
    return *this;
}

}
template <> traQApi::Pin Json::Value::as<traQApi::Pin>() const {
    return traQApi::Pin(*this);
}
