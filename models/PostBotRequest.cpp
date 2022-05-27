#include "PostBotRequest.h"

namespace traQAPI {

Json::Value PostBotRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["displayName"] = (displayName);
    _json["description"] = (description);
    _json["mode"] = (mode);
    _json["endpoint"] = (endpoint);
    return _json;
}
PostBotRequest& PostBotRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    displayName = _json["displayName"].as<std::string>();
    description = _json["description"].as<std::string>();
    mode = _json["mode"].as<BotMode>();
    endpoint = _json["endpoint"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostBotRequest Json::Value::as<traQAPI::PostBotRequest>() const {
    return traQAPI::PostBotRequest(*this);
}
