#ifndef TRAQ_BotMode_H
#define TRAQ_BotMode_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// BOT動作モード  HTTP: HTTP Mode WebSocket: WebSocket Mode
struct BotMode {
    enum class Value {
        eHTTP,
        eWebSocket,
        Unknown,
    } value;
    BotMode() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    BotMode(const Json::Value& __value) {
        this->fromJson(__value);
    }
    BotMode(const Value __value) : value(__value) {}

    Json::Value toJson() const;
    BotMode& fromJson(const Json::Value& _json);
};

}
template <> traQApi::BotMode Json::Value::as<traQApi::BotMode>() const;

#endif
