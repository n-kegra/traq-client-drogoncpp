#ifndef TRAQ_ChannelSubscribeLevel_H
#define TRAQ_ChannelSubscribeLevel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// チャンネル購読レベル 0：無し 1：未読管理 2：未読管理+通知
struct ChannelSubscribeLevel {
    enum class Value {
        e0,
        e1,
        e2,
        Unknown,
    } value;
    ChannelSubscribeLevel() { value = Value::Unknown; };
    operator Json::Value() const;
    ChannelSubscribeLevel(const Json::Value& __value);
    ChannelSubscribeLevel(const Value __value);

    Json::Value toJson() const;
    ChannelSubscribeLevel& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ChannelSubscribeLevel Json::Value::as<traQApi::ChannelSubscribeLevel>() const;

#endif
