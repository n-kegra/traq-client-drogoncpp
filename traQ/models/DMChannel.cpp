#include <traQ/models/DMChannel.h>

namespace traQApi {

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
template <> traQApi::DMChannel Json::Value::as<traQApi::DMChannel>() const {
    return traQApi::DMChannel(*this);
}
