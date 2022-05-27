#ifndef _BotEventResult_H
#define _BotEventResult_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// イベント配送結果
struct BotEventResult {
    enum class Value {
        eok,
        eng,
        ene,
        edp,
        Unknown,
    } value;
    BotEventResult() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    BotEventResult(const Json::Value& __value) {
        this->fromJson(__value);
    }
    BotEventResult(const Value __value) : value(__value) {}

    Json::Value toJson() const;
    BotEventResult& fromJson(const Json::Value& _json);
};

}
template <> traQ::BotEventResult Json::Value::as<traQ::BotEventResult>() const;

#endif
