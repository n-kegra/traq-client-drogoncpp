#include <traQ/models/BotEventResult.h>

namespace traQApi {

BotEventResult::BotEventResult() { value = Value::Unknown; };
BotEventResult::operator Json::Value() const {
    return this->toJson();
}
BotEventResult::BotEventResult(const Json::Value& __value) {
    this->fromJson(__value);
}
BotEventResult::BotEventResult(const Value __value) : value(__value) {}

Json::Value BotEventResult::toJson() const {
    switch(this->value) {
    case Value::eOk:
        return Json::Value("ok");
    case Value::eNg:
        return Json::Value("ng");
    case Value::eNe:
        return Json::Value("ne");
    case Value::eDp:
        return Json::Value("dp");
    default:
        return Json::Value(Json::nullValue);
    }
}
BotEventResult& BotEventResult::fromJson(const Json::Value& _json) {
    std::string s = _json.asString();
    if (s == "ok") {
        this->value = Value::eOk;
    } else
    if (s == "ng") {
        this->value = Value::eNg;
    } else
    if (s == "ne") {
        this->value = Value::eNe;
    } else
    if (s == "dp") {
        this->value = Value::eDp;
    } else
    {
        this->value = Value::Unknown;
    }
    return (*this);
}

}
template <> traQApi::BotEventResult Json::Value::as<traQApi::BotEventResult>() const {
    return traQApi::BotEventResult(*this);
};
