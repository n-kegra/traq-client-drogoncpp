#ifndef _BotMode_H
#define _BotMode_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        switch(this->value) {
        case Value::eHTTP:
            return Json::Value("HTTP");
        case Value::eWebSocket:
            return Json::Value("WebSocket");
        case Value::Unknown:
            return Json::Value(Json::nullValue);
        }
    }
    BotMode& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "HTTP") {
            this->value = Value::eHTTP;
        } else
        if (s == "WebSocket") {
            this->value = Value::eWebSocket;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> traQ::BotMode Json::Value::as<traQ::BotMode>() const { return traQ::BotMode(*this); }

#endif
