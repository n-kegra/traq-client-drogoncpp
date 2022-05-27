#ifndef _PostBotActionLeaveRequest_H
#define _PostBotActionLeaveRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// BOTチャンネル退出リクエスト
struct PostBotActionLeaveRequest {
    std::string channelId;

    PostBotActionLeaveRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostBotActionLeaveRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostBotActionLeaveRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostBotActionLeaveRequest Json::Value::as<traQAPI::PostBotActionLeaveRequest>() const;

#endif
