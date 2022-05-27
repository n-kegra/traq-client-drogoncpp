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
template <> traQ::PostMyFCMDeviceRequest Json::Value::as<traQ::PostMyFCMDeviceRequest>() const;

#endif
