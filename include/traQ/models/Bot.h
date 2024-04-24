#ifndef TRAQ_Bot_H
#define TRAQ_Bot_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

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
    operator Json::Value() const;
    Bot(const Json::Value& __value);

    Json::Value toJson() const;
    Bot& fromJson(const Json::Value& _json);
};

}
template <> traQApi::Bot Json::Value::as<traQApi::Bot>() const;

#endif
