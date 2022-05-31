#ifndef TRAQ_BotDetail_H
#define TRAQ_BotDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/BotMode.h>
#include <traQ/models/BotState.h>
#include <traQ/models/BotTokens.h>
#include <vector>

namespace traQApi {

// BOT詳細情報
struct BotDetail {
    std::string id;
    std::string updatedAt;
    std::string createdAt;
    BotMode mode;
    BotState state;
    std::vector<std::string> subscribeEvents;
    std::string developerId;
    std::string description;
    std::string botUserId;
    BotTokens tokens;
    std::string endpoint;
    bool privileged;
    std::vector<std::string> channels;

    BotDetail() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    BotDetail(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["updatedAt"] = (updatedAt);
        _json["createdAt"] = (createdAt);
        _json["mode"] = (mode);
        _json["state"] = (state);
        _json["subscribeEvents"] = __Helper::toJson(subscribeEvents);
        _json["developerId"] = (developerId);
        _json["description"] = (description);
        _json["botUserId"] = (botUserId);
        _json["tokens"] = (tokens.toJson());
        _json["endpoint"] = (endpoint);
        _json["privileged"] = (privileged);
        _json["channels"] = __Helper::toJson(channels);
        return _json;
    }
    BotDetail& fromJson(const Json::Value& _json) {
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
};

}
template <> inline traQApi::BotDetail Json::Value::as<traQApi::BotDetail>() const {
    return traQApi::BotDetail(*this);
};

#endif
