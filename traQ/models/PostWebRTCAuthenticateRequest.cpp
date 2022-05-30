#include <traQ/models/PostWebRTCAuthenticateRequest.h>

namespace traQApi {

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
template <> traQApi::PostWebRTCAuthenticateRequest Json::Value::as<traQApi::PostWebRTCAuthenticateRequest>() const {
    return traQApi::PostWebRTCAuthenticateRequest(*this);
}