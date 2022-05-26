#ifndef _PostMyFCMDeviceRequest_H
#define _PostMyFCMDeviceRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// FCMデバイス登録リクエスト
struct PostMyFCMDeviceRequest {
    std::string token;

    operator Json::Value() const {
        return this->toJson();
    }
    PostMyFCMDeviceRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["token"] = (token);
        return _json;
    }
    PostMyFCMDeviceRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        token = _json["token"].as<std::string>();
        return *this;
    }
};

}

#endif
