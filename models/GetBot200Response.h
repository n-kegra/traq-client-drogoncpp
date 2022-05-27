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

    Json::Value toJson() const;
    GetBot200Response& fromJson(const Json::Value& _json);
};

}
template <> traQ::GetBot200Response Json::Value::as<traQ::GetBot200Response>() const;

#endif
