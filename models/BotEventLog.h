#ifndef _BotEventLog_H
#define _BotEventLog_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/BotEventResult.h"

namespace traQAPI {

// BOTイベントログ
struct BotEventLog {
    std::string botId;
    std::string requestId;
    std::string event;
    BotEventResult result;
    int32_t code;
    std::string datetime;

    BotEventLog() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    BotEventLog(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    BotEventLog& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::BotEventLog Json::Value::as<traQAPI::BotEventLog>() const;

#endif
