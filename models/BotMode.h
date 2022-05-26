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

    operator Json::Value() const {
        return this->toJson();
    }
    BotMode(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    BotMode& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
