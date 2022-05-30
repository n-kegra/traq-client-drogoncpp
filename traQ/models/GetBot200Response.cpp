#include <traQ/models/GetBot200Response.h>

namespace traQApi {

Json::Value GetBot200Response::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["botUserId"] = (botUserId);
    _json["description"] = (description);
    _json["developerId"] = (developerId);
    _json["subscribeEvents"] = __Helper::toJson(subscribeEvents);
    _json["mode"] = (mode);
    _json["state"] = (state);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    _json["tokens"] = (tokens.toJson());
    _json["endpoint"] = (endpoint);
    _json["privileged"] = (privileged);
    _json["channels"] = __Helper::toJson(channels);
    return _json;
}
GetBot200Response& GetBot200Response::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    botUserId = _json["botUserId"].as<std::string>();
    description = _json["description"].as<std::string>();
    developerId = _json["developerId"].as<std::string>();
    for (auto _it = _json["subscribeEvents"].begin(); _it != _json["subscribeEvents"].end(); _it++) {
        subscribeEvents.emplace_back((*_it).as<std::string>());    
    }
    mode = _json["mode"].as<BotMode>();
    state = _json["state"].as<BotState>();
    createdAt = _json["createdAt"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    tokens.fromJson(_json["tokens"]);
    endpoint = _json["endpoint"].as<std::string>();
    privileged = _json["privileged"].as<bool>();
    for (auto _it = _json["channels"].begin(); _it != _json["channels"].end(); _it++) {
        channels.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQApi::GetBot200Response Json::Value::as<traQApi::GetBot200Response>() const {
    return traQApi::GetBot200Response(*this);
}
