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

    Json::Value toJson() const {
        Json::Value _json;
        _json["channelId"] = (channelId);
        _json["level"] = (level);
        return _json;
    }
    UserSubscribeState& fromJson(const Json::Value& _json) {
        channelId = _json["channelId"].as<std::string>();
        level = _json["level"].as<ChannelSubscribeLevel>();
        return *this;
    }
};

}
template <> traQ::UserSubscribeState Json::Value::as<traQ::UserSubscribeState>() const { return traQ::UserSubscribeState(*this); }

#endif
