#ifndef _PostWebRTCAuthenticateRequest_H
#define _PostWebRTCAuthenticateRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

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
template <> traQAPI::PostWebRTCAuthenticateRequest Json::Value::as<traQAPI::PostWebRTCAuthenticateRequest>() const;

#endif
