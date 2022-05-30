#ifndef TRAQ_PostWebRTCAuthenticateRequest_H
#define TRAQ_PostWebRTCAuthenticateRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// skyway用認証リクエスト
struct PostWebRTCAuthenticateRequest {
    std::string peerId;

    PostWebRTCAuthenticateRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostWebRTCAuthenticateRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostWebRTCAuthenticateRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostWebRTCAuthenticateRequest Json::Value::as<traQApi::PostWebRTCAuthenticateRequest>() const;

#endif
