#ifndef TRAQ_BotUser_H
#define TRAQ_BotUser_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// BOTユーザー対
struct BotUser {
    std::string id;
    std::string botUserId;

    BotUser() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    BotUser(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["botUserId"] = (botUserId);
        return _json;
    }
    BotUser& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        botUserId = _json["botUserId"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::BotUser Json::Value::as<traQApi::BotUser>() const {
    return traQApi::BotUser(*this);
};

#endif
