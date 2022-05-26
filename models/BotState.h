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

    operator Json::Value() const {
        return this->toJson();
    }
    BotState(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    BotState& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
