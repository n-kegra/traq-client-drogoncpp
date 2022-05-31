#ifndef TRAQ_WebRTCUserState_H
#define TRAQ_WebRTCUserState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/WebRTCUserStateSessionsInner.h>
#include <vector>

namespace traQApi {

// WebRTC状態
struct WebRTCUserState {
    std::string userId;
    std::string channelId;
    std::vector<WebRTCUserStateSessionsInner> sessions;

    WebRTCUserState() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    WebRTCUserState(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["userId"] = (userId);
        _json["channelId"] = (channelId);
        _json["sessions"] = __Helper::toJson(sessions);
        return _json;
    }
    WebRTCUserState& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        channelId = _json["channelId"].as<std::string>();
        for (auto _it = _json["sessions"].begin(); _it != _json["sessions"].end(); _it++) {
            sessions.emplace_back((*_it));    
        }
        return *this;
    }
};

}
template <> inline traQApi::WebRTCUserState Json::Value::as<traQApi::WebRTCUserState>() const {
    return traQApi::WebRTCUserState(*this);
};

#endif
