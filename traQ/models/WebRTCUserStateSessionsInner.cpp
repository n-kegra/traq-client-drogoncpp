#include <traQ/models/WebRTCUserStateSessionsInner.h>

namespace traQApi {

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
template <> traQApi::WebRTCUserStateSessionsInner Json::Value::as<traQApi::WebRTCUserStateSessionsInner>() const {
    return traQApi::WebRTCUserStateSessionsInner(*this);
}
