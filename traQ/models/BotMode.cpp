#include <traQ/models/BotMode.h>

namespace traQApi {

BotMode::BotMode() { value = Value::Unknown; };
BotMode::operator Json::Value() const {
    return this->toJson();
}
BotMode::BotMode(const Json::Value& __value) {
    this->fromJson(__value);
}
BotMode::BotMode(const Value __value) : value(__value) {}

Json::Value BotMode::toJson() const {
    switch(this->value) {
    case Value::eHTTP:
        return Json::Value("HTTP");
    case Value::eWebSocket:
        return Json::Value("WebSocket");
    default:
        return Json::Value(Json::nullValue);
    }
}
BotMode& BotMode::fromJson(const Json::Value& _json) {
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

}
template <> traQApi::BotMode Json::Value::as<traQApi::BotMode>() const {
    return traQApi::BotMode(*this);
};
