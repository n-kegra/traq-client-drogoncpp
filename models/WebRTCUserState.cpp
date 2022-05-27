#include "WebRTCUserState.h"

namespace traQAPI {

Json::Value WebRTCUserState::toJson() const {
    Json::Value _json;
    _json["userId"] = (userId);
    _json["channelId"] = (channelId);
    _json["sessions"] = Helper::toJson(sessions);
    return _json;
}
WebRTCUserState& WebRTCUserState::fromJson(const Json::Value& _json) {
    userId = _json["userId"].as<std::string>();
    channelId = _json["channelId"].as<std::string>();
    for (auto _it = _json["sessions"].begin(); _it != _json["sessions"].end(); _it++) {
        sessions.emplace_back((*_it));    
    }
    return *this;
}

}
template <> traQAPI::WebRTCUserState Json::Value::as<traQAPI::WebRTCUserState>() const {
    return traQAPI::WebRTCUserState(*this);
}
