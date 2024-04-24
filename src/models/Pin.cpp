#include <traQ/models/Pin.h>
#include "../Helper.h"

namespace traQApi {

Pin::operator Json::Value() const {
    return this->toJson();
}
Pin::Pin(const Json::Value& __value) {
    this->fromJson(__value);
}

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
};
