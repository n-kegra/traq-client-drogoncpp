#include "WebRTCAuthenticateResult.h"

namespace traQ {

Json::Value WebRTCAuthenticateResult::toJson() const {
    Json::Value _json;
    _json["peerId"] = (peerId);
    _json["ttl"] = (ttl);
    _json["timestamp"] = (timestamp);
    _json["authToken"] = (authToken);
    return _json;
}
WebRTCAuthenticateResult& WebRTCAuthenticateResult::fromJson(const Json::Value& _json) {
    peerId = _json["peerId"].as<std::string>();
    ttl = _json["ttl"].as<int32_t>();
    timestamp = _json["timestamp"].as<int64_t>();
    authToken = _json["authToken"].as<std::string>();
    return *this;
}

}
template <> traQ::WebRTCAuthenticateResult Json::Value::as<traQ::WebRTCAuthenticateResult>() const {
    return traQ::WebRTCAuthenticateResult(*this);
}
