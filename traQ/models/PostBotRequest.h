#ifndef TRAQ_PostBotRequest_H
#define TRAQ_PostBotRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/BotMode.h>

namespace traQApi {

// BOT作成リクエスト
struct PostBotRequest {
    std::string name;
    std::string displayName;
    std::string description;
    BotMode mode;
    std::string endpoint;

    PostBotRequest() = default;
    operator Json::Value() const;
    PostBotRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostBotRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostBotRequest Json::Value::as<traQApi::PostBotRequest>() const;

#endif
