#ifndef _UserSubscribeState_H
#define _UserSubscribeState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ChannelSubscribeLevel.h"

namespace traQ {

// ユーザーのチャンネル購読状態
struct UserSubscribeState {
    std::string channelId;
    ChannelSubscribeLevel level;

    UserSubscribeState() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    UserSubscribeState(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    UserSubscribeState& fromJson(const Json::Value& _json);
};

}
template <> traQ::UserSubscribeState Json::Value::as<traQ::UserSubscribeState>() const;

#endif
