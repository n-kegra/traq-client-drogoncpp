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

    Json::Value toJson() const {
        Json::Value _json;
        _json["botId"] = (botId);
        _json["requestId"] = (requestId);
        _json["event"] = (event);
        _json["result"] = (result);
        _json["code"] = (code);
        _json["datetime"] = (datetime);
        return _json;
    }
    BotEventLog& fromJson(const Json::Value& _json) {
        botId = _json["botId"].as<std::string>();
        requestId = _json["requestId"].as<std::string>();
        event = _json["event"].as<std::string>();
        result = _json["result"].as<BotEventResult>();
        code = _json["code"].as<int32_t>();
        datetime = _json["datetime"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::BotEventLog Json::Value::as<traQApi::BotEventLog>() const {
    return traQApi::BotEventLog(*this);
};

#endif
