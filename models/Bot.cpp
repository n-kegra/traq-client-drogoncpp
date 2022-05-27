#include "Bot.h"

namespace traQ {

Json::Value Bot::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["botUserId"] = (botUserId);
    _json["description"] = (description);
    _json["developerId"] = (developerId);
    _json["subscribeEvents"] = Helper::toJson(subscribeEvents);
    _json["mode"] = (mode);
    _json["state"] = (state);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    return _json;
}
Bot& Bot::fromJson(const Json::Value& _json) {
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
    return *this;
}

}
template <> traQ::Bot Json::Value::as<traQ::Bot>() const {
    return traQ::Bot(*this);
}