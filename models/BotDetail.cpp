#include "BotDetail.h"

namespace traQ {

Json::Value BotDetail::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["updatedAt"] = (updatedAt);
    _json["createdAt"] = (createdAt);
    _json["mode"] = (mode);
    _json["state"] = (state);
    _json["subscribeEvents"] = Helper::toJson(subscribeEvents);
    _json["developerId"] = (developerId);
    _json["description"] = (description);
    _json["botUserId"] = (botUserId);
    _json["tokens"] = (tokens.toJson());
    _json["endpoint"] = (endpoint);
    _json["privileged"] = (privileged);
    _json["channels"] = Helper::toJson(channels);
    return _json;
}
BotDetail& BotDetail::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    createdAt = _json["createdAt"].as<std::string>();
    mode = _json["mode"].as<BotMode>();
    state = _json["state"].as<BotState>();
    for (auto _it = _json["subscribeEvents"].begin(); _it != _json["subscribeEvents"].end(); _it++) {
        subscribeEvents.emplace_back((*_it).as<std::string>());    
    }
    developerId = _json["developerId"].as<std::string>();
    description = _json["description"].as<std::string>();
    botUserId = _json["botUserId"].as<std::string>();
    tokens.fromJson(_json["tokens"]);
    endpoint = _json["endpoint"].as<std::string>();
    privileged = _json["privileged"].as<bool>();
    for (auto _it = _json["channels"].begin(); _it != _json["channels"].end(); _it++) {
        channels.emplace_back((*_it).as<std::string>());    
    }
    return *this;
}

}
template <> traQ::BotDetail Json::Value::as<traQ::BotDetail>() const {
    return traQ::BotDetail(*this);
}
