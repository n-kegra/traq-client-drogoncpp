#ifndef _PostBotActionJoinRequest_H
#define _PostBotActionJoinRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// BOTチャンネル参加リクエスト
struct PostBotActionJoinRequest {
    std::string channelId;

    PostBotActionJoinRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostBotActionJoinRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostBotActionJoinRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostBotActionJoinRequest Json::Value::as<traQAPI::PostBotActionJoinRequest>() const;

#endif
