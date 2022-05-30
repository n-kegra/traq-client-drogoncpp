#include <traQ/models/BotMode.h>

namespace traQApi {

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
template <> traQApi::BotMode Json::Value::as<traQApi::BotMode>() const {
    return traQApi::BotMode(*this);
}
