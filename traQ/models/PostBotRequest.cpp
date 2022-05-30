#include <traQ/models/PostBotRequest.h>

namespace traQApi {

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
template <> traQApi::PostBotRequest Json::Value::as<traQApi::PostBotRequest>() const {
    return traQApi::PostBotRequest(*this);
}
