#ifndef TRAQ_PostBotActionJoinRequest_H
#define TRAQ_PostBotActionJoinRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// BOTチャンネル参加リクエスト
struct PostBotActionJoinRequest {
    std::string channelId;

    PostBotActionJoinRequest() = default;
    operator Json::Value() const;
    PostBotActionJoinRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostBotActionJoinRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostBotActionJoinRequest Json::Value::as<traQApi::PostBotActionJoinRequest>() const;

#endif
