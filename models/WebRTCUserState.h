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

    Json::Value toJson() const;
    WebRTCUserState& fromJson(const Json::Value& _json);
};

}
template <> traQ::WebRTCUserState Json::Value::as<traQ::WebRTCUserState>() const;

#endif
