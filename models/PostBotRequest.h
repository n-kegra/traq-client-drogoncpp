#ifndef _PostBotRequest_H
#define _PostBotRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/BotMode.h"

namespace traQ {

// BOT作成リクエスト
struct PostBotRequest {
    std::string name;
    std::string displayName;
    std::string description;
    BotMode mode;
    std::string endpoint;

    PostBotRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostBotRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostBotRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PostBotRequest Json::Value::as<traQ::PostBotRequest>() const;

#endif
