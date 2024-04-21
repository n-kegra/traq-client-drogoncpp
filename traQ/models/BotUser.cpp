#include <traQ/models/BotUser.h>

namespace traQApi {

BotUser::operator Json::Value() const {
    return this->toJson();
}
BotUser::BotUser(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value BotUser::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["botUserId"] = (botUserId);
    return _json;
}
BotUser& BotUser::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    botUserId = _json["botUserId"].as<std::string>();
    return *this;
}

}
template <> traQApi::BotUser Json::Value::as<traQApi::BotUser>() const {
    return traQApi::BotUser(*this);
};
