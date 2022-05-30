#include <traQ/models/BotEventResult.h>

namespace traQApi {

Json::Value BotEventResult::toJson() const {
    switch(this->value) {
    case Value::eok:
        return Json::Value("ok");
    case Value::eng:
        return Json::Value("ng");
    case Value::ene:
        return Json::Value("ne");
    case Value::edp:
        return Json::Value("dp");
    case Value::Unknown:
        return Json::Value(Json::nullValue);
    }
}
BotEventResult& BotEventResult::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "ok") {
        this->value = Value::eok;
    } else
    if (s == "ng") {
        this->value = Value::eng;
    } else
    if (s == "ne") {
        this->value = Value::ene;
    } else
    if (s == "dp") {
        this->value = Value::edp;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQApi::BotEventResult Json::Value::as<traQApi::BotEventResult>() const {
    return traQApi::BotEventResult(*this);
}
