#ifndef _BotDetail_H
#define _BotDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/BotMode.h"
#include "../models/BotState.h"
#include "../models/BotTokens.h"
#include <vector>

namespace traQ {

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
    BotDetail& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        createdAt = _json["createdAt"].as<std::string>();
        mode = _json["mode"].as<BotMode>();
        state = _json["state"].as<BotState>();
        subscribeEvents = _json["subscribeEvents"].as<std::vector<std::string>>();
        developerId = _json["developerId"].as<std::string>();
        description = _json["description"].as<std::string>();
        botUserId = _json["botUserId"].as<std::string>();
        tokens = _json["tokens"].as<BotTokens>();
        endpoint = _json["endpoint"].as<std::string>();
        privileged = _json["privileged"].as<bool>();
        channels = _json["channels"].as<std::vector<std::string>>();
        return *this;
    }
};

}

#endif
