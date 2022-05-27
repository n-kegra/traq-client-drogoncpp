#ifndef _UserGroupMember_H
#define _UserGroupMember_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

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
template <> traQAPI::UserGroupMember Json::Value::as<traQAPI::UserGroupMember>() const;

#endif
