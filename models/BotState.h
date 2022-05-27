#ifndef _BotState_H
#define _BotState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// BOT状態 0: 停止 1: 有効 2: 一時停止
struct BotState {
    enum class Value {
        e0,
        e1,
        e2,
        Unknown,
    } value;
    BotState() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    BotState(const Json::Value& __value) {
        this->fromJson(__value);
    }
    BotState(const Value __value) : value(__value) {}

    Json::Value toJson() const;
    BotState& fromJson(const Json::Value& _json);
};

}
template <> traQ::BotState Json::Value::as<traQ::BotState>() const;

#endif
