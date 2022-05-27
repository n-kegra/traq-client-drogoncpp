#include "BotEventLog.h"

namespace traQ {

Json::Value BotEventLog::toJson() const {
    Json::Value _json;
    _json["botId"] = (botId);
    _json["requestId"] = (requestId);
    _json["event"] = (event);
    _json["result"] = (result);
    _json["code"] = (code);
    _json["datetime"] = (datetime);
    return _json;
}
BotEventLog& BotEventLog::fromJson(const Json::Value& _json) {
    botId = _json["botId"].as<std::string>();
    requestId = _json["requestId"].as<std::string>();
    event = _json["event"].as<std::string>();
    result = _json["result"].as<BotEventResult>();
    code = _json["code"].as<int32_t>();
    datetime = _json["datetime"].as<std::string>();
    return *this;
}

}
template <> traQ::BotEventLog Json::Value::as<traQ::BotEventLog>() const {
    return traQ::BotEventLog(*this);
}
