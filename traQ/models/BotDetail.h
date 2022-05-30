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

    Json::Value toJson() const;
    BotDetail& fromJson(const Json::Value& _json);
};

}
template <> traQApi::BotDetail Json::Value::as<traQApi::BotDetail>() const;

#endif
