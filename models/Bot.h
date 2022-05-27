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

namespace traQAPI {

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

    Json::Value toJson() const;
    Bot& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::Bot Json::Value::as<traQAPI::Bot>() const;

#endif
