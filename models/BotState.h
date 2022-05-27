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

    Json::Value toJson() const {
        switch(this->value) {
        case Value::e0:
            return Json::Value(0);
        case Value::e1:
            return Json::Value(1);
        case Value::e2:
            return Json::Value(2);
        case Value::Unknown:
            return Json::Value(Json::nullValue);
        }
    }
    BotState& fromJson(const Json::Value& _json) {
        auto s = _json.asLargestInt();
        if (s == 0) {
            this->value = Value::e0;
        } else
        if (s == 1) {
            this->value = Value::e1;
        } else
        if (s == 2) {
            this->value = Value::e2;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> traQ::BotState Json::Value::as<traQ::BotState>() const { return traQ::BotState(*this); }

#endif
