#include <traQ/models/PostWebRTCAuthenticateRequest.h>
#include "../Helper.h"

namespace traQApi {

PostWebRTCAuthenticateRequest::operator Json::Value() const {
    return this->toJson();
}
PostWebRTCAuthenticateRequest::PostWebRTCAuthenticateRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
};
