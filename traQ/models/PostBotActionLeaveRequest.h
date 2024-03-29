#ifndef TRAQ_PostBotActionLeaveRequest_H
#define TRAQ_PostBotActionLeaveRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["channelId"] = (channelId);
        return _json;
    }
    PostBotActionLeaveRequest& fromJson(const Json::Value& _json) {
        channelId = _json["channelId"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PostBotActionLeaveRequest Json::Value::as<traQApi::PostBotActionLeaveRequest>() const {
    return traQApi::PostBotActionLeaveRequest(*this);
};

#endif
