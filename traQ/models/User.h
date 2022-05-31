#ifndef TRAQ_User_H
#define TRAQ_User_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/UserAccountState.h>

namespace traQApi {

// ユーザー情報
struct User {
    std::string id;
    std::string name;
    std::string displayName;
    std::string iconFileId;
    bool bot;
    UserAccountState state;
    std::string updatedAt;

    User() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    User(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["name"] = (name);
        _json["displayName"] = (displayName);
        _json["iconFileId"] = (iconFileId);
        _json["bot"] = (bot);
        _json["state"] = (state);
        _json["updatedAt"] = (updatedAt);
        return _json;
    }
    User& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        displayName = _json["displayName"].as<std::string>();
        iconFileId = _json["iconFileId"].as<std::string>();
        bot = _json["bot"].as<bool>();
        state = _json["state"].as<UserAccountState>();
        updatedAt = _json["updatedAt"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::User Json::Value::as<traQApi::User>() const {
    return traQApi::User(*this);
};

#endif
