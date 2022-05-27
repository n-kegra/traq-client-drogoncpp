#include "PostWebRTCAuthenticateRequest.h"

namespace traQ {

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
template <> traQ::PostWebRTCAuthenticateRequest Json::Value::as<traQ::PostWebRTCAuthenticateRequest>() const {
    return traQ::PostWebRTCAuthenticateRequest(*this);
}
