#ifndef _PostBotActionJoinRequest_H
#define _PostBotActionJoinRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["channelId"] = (channelId);
        return _json;
    }
    PostBotActionJoinRequest& fromJson(const Json::Value& _json) {
        channelId = _json["channelId"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::PostBotActionJoinRequest Json::Value::as<traQ::PostBotActionJoinRequest>() const { return traQ::PostBotActionJoinRequest(*this); }

#endif
