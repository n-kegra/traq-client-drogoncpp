#ifndef TRAQ_BotEventLog_H
#define TRAQ_BotEventLog_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/BotEventResult.h>

namespace traQApi {

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
template <> traQApi::BotEventLog Json::Value::as<traQApi::BotEventLog>() const;

#endif
