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

    operator Json::Value() const {
        return this->toJson();
    }
    BotEventResult(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    BotEventResult& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
