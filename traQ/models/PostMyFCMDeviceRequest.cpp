#include <traQ/models/PostMyFCMDeviceRequest.h>

namespace traQApi {

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
template <> traQApi::PostMyFCMDeviceRequest Json::Value::as<traQApi::PostMyFCMDeviceRequest>() const {
    return traQApi::PostMyFCMDeviceRequest(*this);
}
