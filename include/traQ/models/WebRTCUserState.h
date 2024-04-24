#ifndef TRAQ_WebRTCUserState_H
#define TRAQ_WebRTCUserState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <traQ/models/WebRTCUserStateSessionsInner.h>
#include <vector>

namespace traQApi {

// WebRTC状態
struct WebRTCUserState {
    std::string userId;
    std::string channelId;
    std::vector<WebRTCUserStateSessionsInner> sessions;

    WebRTCUserState() = default;
    operator Json::Value() const;
    WebRTCUserState(const Json::Value& __value);

    Json::Value toJson() const;
    WebRTCUserState& fromJson(const Json::Value& _json);
};

}
template <> traQApi::WebRTCUserState Json::Value::as<traQApi::WebRTCUserState>() const;

#endif
