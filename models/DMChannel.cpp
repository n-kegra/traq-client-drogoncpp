#include "DMChannel.h"

namespace traQAPI {

Json::Value DMChannel::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["userId"] = (userId);
    return _json;
}
DMChannel& DMChannel::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    userId = _json["userId"].as<std::string>();
    return *this;
}

}
template <> traQAPI::DMChannel Json::Value::as<traQAPI::DMChannel>() const {
    return traQAPI::DMChannel(*this);
}
