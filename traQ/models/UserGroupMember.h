#ifndef TRAQ_UserGroupMember_H
#define TRAQ_UserGroupMember_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザーグループメンバー
struct UserGroupMember {
    std::string id;
    std::string role;

    UserGroupMember() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    UserGroupMember(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    UserGroupMember& fromJson(const Json::Value& _json);
};

}
template <> traQApi::UserGroupMember Json::Value::as<traQApi::UserGroupMember>() const;

#endif
