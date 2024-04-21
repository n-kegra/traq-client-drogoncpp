#include <traQ/models/BotTokens.h>

namespace traQApi {

BotTokens::operator Json::Value() const {
    return this->toJson();
}
BotTokens::BotTokens(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value BotTokens::toJson() const {
    Json::Value _json;
    _json["verificationToken"] = (verificationToken);
    _json["accessToken"] = (accessToken);
    return _json;
}
BotTokens& BotTokens::fromJson(const Json::Value& _json) {
    verificationToken = _json["verificationToken"].as<std::string>();
    accessToken = _json["accessToken"].as<std::string>();
    return *this;
}

}
template <> traQApi::BotTokens Json::Value::as<traQApi::BotTokens>() const {
    return traQApi::BotTokens(*this);
};
