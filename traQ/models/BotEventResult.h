#ifndef TRAQ_BotEventResult_H
#define TRAQ_BotEventResult_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// イベント配送結果
struct BotEventResult {
    enum class Value {
        eOk,
        eNg,
        eNe,
        eDp,
        Unknown,
    } value;
    BotEventResult();
    operator Json::Value() const;
    BotEventResult(const Json::Value& __value);
    BotEventResult(const Value __value);

    Json::Value toJson() const;
    BotEventResult& fromJson(const Json::Value& _json);
};

}
template <> traQApi::BotEventResult Json::Value::as<traQApi::BotEventResult>() const;

#endif
