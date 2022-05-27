#ifndef _WebRTCUserState_H
#define _WebRTCUserState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/WebRTCUserStateSessionsInner.h"
#include <vector>

namespace traQ {

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
        _json["sessions"] = Helper::toJson(sessions);
        return _json;
    }
    WebRTCUserState& fromJson(const Json::Value& _json) {
        userId = _json["userId"].as<std::string>();
        channelId = _json["channelId"].as<std::string>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            sessions.emplace_back((*_it));    
        }
        return *this;
    }
};

}
template <> traQ::WebRTCUserState Json::Value::as<traQ::WebRTCUserState>() const { return traQ::WebRTCUserState(*this); }

#endif
