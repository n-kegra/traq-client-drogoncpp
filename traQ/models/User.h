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
    operator Json::Value() const;
    User(const Json::Value& __value);

    Json::Value toJson() const;
    User& fromJson(const Json::Value& _json);
};

}
template <> traQApi::User Json::Value::as<traQApi::User>() const;

#endif
