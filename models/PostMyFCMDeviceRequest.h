#ifndef _PostMyFCMDeviceRequest_H
#define _PostMyFCMDeviceRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// FCMデバイス登録リクエスト
struct PostMyFCMDeviceRequest {
    std::string token;

    PostMyFCMDeviceRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostMyFCMDeviceRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostMyFCMDeviceRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostMyFCMDeviceRequest Json::Value::as<traQAPI::PostMyFCMDeviceRequest>() const;

#endif
