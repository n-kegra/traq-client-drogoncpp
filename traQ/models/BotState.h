#ifndef TRAQ_BotState_H
#define TRAQ_BotState_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// BOT状態 0: 停止 1: 有効 2: 一時停止
struct BotState {
    enum class Value {
        e0,
        e1,
        e2,
        Unknown,
    } value;
    BotState();
    operator Json::Value() const;
    BotState(const Json::Value& __value);
    BotState(const Value __value);

    Json::Value toJson() const;
    BotState& fromJson(const Json::Value& _json);
};

}
template <> traQApi::BotState Json::Value::as<traQApi::BotState>() const;

#endif
