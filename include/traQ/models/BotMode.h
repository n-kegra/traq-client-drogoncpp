#ifndef TRAQ_BotMode_H
#define TRAQ_BotMode_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// BOT動作モード  HTTP: HTTP Mode WebSocket: WebSocket Mode
struct BotMode {
    enum class Value {
        eHTTP,
        eWebSocket,
        Unknown,
    } value;
    BotMode();
    operator Json::Value() const;
    BotMode(const Json::Value& __value);
    BotMode(const Value __value);

    Json::Value toJson() const;
    BotMode& fromJson(const Json::Value& _json);
};

}
template <> traQApi::BotMode Json::Value::as<traQApi::BotMode>() const;

#endif
