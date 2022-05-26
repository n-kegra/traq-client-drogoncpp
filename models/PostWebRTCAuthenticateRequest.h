#ifndef _PostWebRTCAuthenticateRequest_H
#define _PostWebRTCAuthenticateRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// skyway用認証リクエスト
struct PostWebRTCAuthenticateRequest {
    std::string peerId;

    operator Json::Value() const {
        return this->toJson();
    }
    PostWebRTCAuthenticateRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["peerId"] = (peerId);
        return _json;
    }
    PostWebRTCAuthenticateRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        peerId = _json["peerId"].as<std::string>();
        return *this;
    }
};

}

#endif
