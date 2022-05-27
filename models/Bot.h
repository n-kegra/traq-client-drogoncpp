#ifndef _Bot_H
#define _Bot_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/BotMode.h"
#include "../models/BotState.h"
#include <vector>

namespace traQ {

// BOT情報
struct Bot {
    std::string id;
    std::string botUserId;
    std::string description;
    std::string developerId;
    std::vector<std::string> subscribeEvents;
    BotMode mode;
    BotState state;
    std::string createdAt;
    std::string updatedAt;

    Bot() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    Bot(const Json::Value& __value) {
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
        return _json;
    }
    Bot& fromJson(const Json::Value& _json) {
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
        return *this;
    }
};

}
template <> traQ::Bot Json::Value::as<traQ::Bot>() const { return traQ::Bot(*this); }

#endif
