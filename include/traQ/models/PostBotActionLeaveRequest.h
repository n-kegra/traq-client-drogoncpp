#ifndef TRAQ_PostBotActionLeaveRequest_H
#define TRAQ_PostBotActionLeaveRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// BOTチャンネル退出リクエスト
struct PostBotActionLeaveRequest {
    std::string channelId;

    PostBotActionLeaveRequest() = default;
    operator Json::Value() const;
    PostBotActionLeaveRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostBotActionLeaveRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostBotActionLeaveRequest Json::Value::as<traQApi::PostBotActionLeaveRequest>() const;

#endif
