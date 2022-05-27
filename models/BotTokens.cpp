#include "BotTokens.h"

namespace traQAPI {

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
template <> traQAPI::BotTokens Json::Value::as<traQAPI::BotTokens>() const {
    return traQAPI::BotTokens(*this);
}
