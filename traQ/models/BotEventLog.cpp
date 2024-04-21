#include <traQ/models/BotEventLog.h>

namespace traQApi {

BotEventLog::operator Json::Value() const {
    return this->toJson();
}
BotEventLog::BotEventLog(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::BotEventLog Json::Value::as<traQApi::BotEventLog>() const {
    return traQApi::BotEventLog(*this);
};
