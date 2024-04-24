#ifndef TRAQ_UserSubscribeState_H
#define TRAQ_UserSubscribeState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <traQ/models/ChannelSubscribeLevel.h>

namespace traQApi {

// ユーザーのチャンネル購読状態
struct UserSubscribeState {
    std::string channelId;
    ChannelSubscribeLevel level;

    UserSubscribeState() = default;
    operator Json::Value() const;
    UserSubscribeState(const Json::Value& __value);

    Json::Value toJson() const;
    UserSubscribeState& fromJson(const Json::Value& _json);
};

}
template <> traQApi::UserSubscribeState Json::Value::as<traQApi::UserSubscribeState>() const;

#endif
