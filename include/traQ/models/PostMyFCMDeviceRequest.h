#ifndef TRAQ_PostMyFCMDeviceRequest_H
#define TRAQ_PostMyFCMDeviceRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// FCMデバイス登録リクエスト
struct PostMyFCMDeviceRequest {
    std::string token;

    PostMyFCMDeviceRequest() = default;
    operator Json::Value() const;
    PostMyFCMDeviceRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostMyFCMDeviceRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostMyFCMDeviceRequest Json::Value::as<traQApi::PostMyFCMDeviceRequest>() const;

#endif
