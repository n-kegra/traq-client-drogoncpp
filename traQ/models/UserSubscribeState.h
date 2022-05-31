#ifndef TRAQ_UserSubscribeState_H
#define TRAQ_UserSubscribeState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ChannelSubscribeLevel.h>

namespace traQApi {

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
template <> inline traQApi::UserSubscribeState Json::Value::as<traQApi::UserSubscribeState>() const {
    return traQApi::UserSubscribeState(*this);
};

#endif
