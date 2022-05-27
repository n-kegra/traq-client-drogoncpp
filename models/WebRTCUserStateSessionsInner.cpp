#include "WebRTCUserStateSessionsInner.h"

namespace traQ {

Json::Value WebRTCUserStateSessionsInner::toJson() const {
    Json::Value _json;
    _json["state"] = (state);
    _json["sessionId"] = (sessionId);
    return _json;
}
WebRTCUserStateSessionsInner& WebRTCUserStateSessionsInner::fromJson(const Json::Value& _json) {
    state = _json["state"].as<std::string>();
    sessionId = _json["sessionId"].as<std::string>();
    return *this;
}

}
template <> traQ::WebRTCUserStateSessionsInner Json::Value::as<traQ::WebRTCUserStateSessionsInner>() const {
    return traQ::WebRTCUserStateSessionsInner(*this);
}
