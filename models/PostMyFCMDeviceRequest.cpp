#include "PostMyFCMDeviceRequest.h"

namespace traQ {

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
template <> traQ::PostMyFCMDeviceRequest Json::Value::as<traQ::PostMyFCMDeviceRequest>() const {
    return traQ::PostMyFCMDeviceRequest(*this);
}
