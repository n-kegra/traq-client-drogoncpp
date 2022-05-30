#ifndef TRAQ_GetBot200Response_H
#define TRAQ_GetBot200Response_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/Bot.h>
#include <traQ/models/BotDetail.h>
#include <traQ/models/BotMode.h>
#include <traQ/models/BotState.h>
#include <traQ/models/BotTokens.h>
#include <vector>

namespace traQApi {

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

    Json::Value toJson() const;
    GetBot200Response& fromJson(const Json::Value& _json);
};

}
template <> traQApi::GetBot200Response Json::Value::as<traQApi::GetBot200Response>() const;

#endif
