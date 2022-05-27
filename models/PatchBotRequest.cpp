#include "PatchBotRequest.h"

namespace traQAPI {

Json::Value PatchBotRequest::toJson() const {
    Json::Value _json;
    _json["displayName"] = (displayName);
    _json["description"] = (description);
    _json["privileged"] = (privileged);
    _json["mode"] = (mode);
    _json["endpoint"] = (endpoint);
    _json["developerId"] = (developerId);
    _json["subscribeEvents"] = Helper::toJson(subscribeEvents);
    return _json;
}
PatchBotRequest& PatchBotRequest::fromJson(const Json::Value& _json) {
    displayName = _json["displayName"].as<std::string>();
    description = _json["description"].as<std::string>();
    privileged = _json["privileged"].as<bool>();
    mode = _json["mode"].as<BotMode>();
    endpoint = _json["endpoint"].as<std::string>();
    developerId = _json["developerId"].as<std::string>();
    for (auto _it = _json["subscribeEvents"].begin(); _it != _json["subscribeEvents"].end(); _it++) {
        subscribeEvents.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQAPI::PatchBotRequest Json::Value::as<traQAPI::PatchBotRequest>() const {
    return traQAPI::PatchBotRequest(*this);
}
