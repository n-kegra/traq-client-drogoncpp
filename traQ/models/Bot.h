#ifndef TRAQ_Bot_H
#define TRAQ_Bot_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/BotMode.h>
#include <traQ/models/BotState.h>
#include <vector>

namespace traQApi {

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
        _json["subscribeEvents"] = __Helper::toJson(subscribeEvents);
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
        for (auto _it = _json["subscribeEvents"].begin(); _it != _json["subscribeEvents"].end(); _it++) {
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
template <> inline traQApi::Bot Json::Value::as<traQApi::Bot>() const {
    return traQApi::Bot(*this);
};

#endif
