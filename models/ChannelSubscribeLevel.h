#ifndef _ChannelSubscribeLevel_H
#define _ChannelSubscribeLevel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// チャンネル購読レベル 0：無し 1：未読管理 2：未読管理+通知
struct ChannelSubscribeLevel {
    enum class Value {
        e0,
        e1,
        e2,
        Unknown,
    } value;
    ChannelSubscribeLevel() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelSubscribeLevel(const Json::Value& __value) {
        this->fromJson(__value);
    }
    ChannelSubscribeLevel(const Value __value) : value(__value) {}

    Json::Value toJson() const;
    ChannelSubscribeLevel& fromJson(const Json::Value& _json);
};

}
template <> traQ::ChannelSubscribeLevel Json::Value::as<traQ::ChannelSubscribeLevel>() const;

#endif
