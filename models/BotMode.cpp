#include "BotMode.h"

namespace traQAPI {

Json::Value BotMode::toJson() const {
    switch(this->value) {
    case Value::eHTTP:
        return Json::Value("HTTP");
    case Value::eWebSocket:
        return Json::Value("WebSocket");
    case Value::Unknown:
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
template <> traQAPI::BotMode Json::Value::as<traQAPI::BotMode>() const {
    return traQAPI::BotMode(*this);
}
