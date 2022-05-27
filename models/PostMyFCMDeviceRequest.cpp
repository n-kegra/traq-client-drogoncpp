#include "PostMyFCMDeviceRequest.h"

namespace traQAPI {

Json::Value PostMyFCMDeviceRequest::toJson() const {
    Json::Value _json;
    _json["token"] = (token);
    return _json;
}
PostMyFCMDeviceRequest& PostMyFCMDeviceRequest::fromJson(const Json::Value& _json) {
    token = _json["token"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostMyFCMDeviceRequest Json::Value::as<traQAPI::PostMyFCMDeviceRequest>() const {
    return traQAPI::PostMyFCMDeviceRequest(*this);
}
