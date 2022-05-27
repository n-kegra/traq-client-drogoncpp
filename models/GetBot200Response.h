#ifndef _GetBot200Response_H
#define _GetBot200Response_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Bot.h"
#include "../models/BotDetail.h"
#include "../models/BotMode.h"
#include "../models/BotState.h"
#include "../models/BotTokens.h"
#include <vector>

namespace traQ {

struct GetBot200Response {
    std::string id;
    std::string botUserId;
    std::string description;
    std::string developerId;
    std::vector<std::string> subscribeEvents;
    BotMode mode;
    BotState state;
    std::string createdAt;
    std::string updatedAt;
    BotTokens tokens;
    std::string endpoint;
    bool privileged;
    std::vector<std::string> channels;

    GetBot200Response() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    GetBot200Response(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
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
        _json["tokens"] = (tokens.toJson());
        _json["endpoint"] = (endpoint);
        _json["privileged"] = (privileged);
        _json["channels"] = Helper::toJson(channels);
        return _json;
    }
    GetBot200Response& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        botUserId = _json["botUserId"].as<std::string>();
        description = _json["description"].as<std::string>();
        developerId = _json["developerId"].as<std::string>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            subscribeEvents.emplace_back((*_it).as<std::string>());    
        }
        mode = _json["mode"].as<BotMode>();
        state = _json["state"].as<BotState>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        tokens.fromJson(_json["tokens"]);
        endpoint = _json["endpoint"].as<std::string>();
        privileged = _json["privileged"].as<bool>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            channels.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> traQ::GetBot200Response Json::Value::as<traQ::GetBot200Response>() const { return traQ::GetBot200Response(*this); }

#endif
