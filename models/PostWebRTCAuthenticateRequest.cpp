#include "PostWebRTCAuthenticateRequest.h"

namespace traQAPI {

Json::Value PostWebRTCAuthenticateRequest::toJson() const {
    Json::Value _json;
    _json["peerId"] = (peerId);
    return _json;
}
PostWebRTCAuthenticateRequest& PostWebRTCAuthenticateRequest::fromJson(const Json::Value& _json) {
    peerId = _json["peerId"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostWebRTCAuthenticateRequest Json::Value::as<traQAPI::PostWebRTCAuthenticateRequest>() const {
    return traQAPI::PostWebRTCAuthenticateRequest(*this);
}
