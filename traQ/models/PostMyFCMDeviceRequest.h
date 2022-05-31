#ifndef TRAQ_PostMyFCMDeviceRequest_H
#define TRAQ_PostMyFCMDeviceRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["token"] = (token);
        return _json;
    }
    PostMyFCMDeviceRequest& fromJson(const Json::Value& _json) {
        token = _json["token"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PostMyFCMDeviceRequest Json::Value::as<traQApi::PostMyFCMDeviceRequest>() const {
    return traQApi::PostMyFCMDeviceRequest(*this);
};

#endif
