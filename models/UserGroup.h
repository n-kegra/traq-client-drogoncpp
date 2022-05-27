#ifndef _UserGroup_H
#define _UserGroup_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/UserGroupMember.h"
#include <vector>

namespace traQAPI {

// ユーザーグループ
struct UserGroup {
    std::string id;
    std::string name;
    std::string description;
    std::string type;
    std::string icon;
    std::vector<UserGroupMember> members;
    std::string createdAt;
    std::string updatedAt;
    std::vector<std::string> admins;

    UserGroup() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    UserGroup(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    UserGroup& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::UserGroup Json::Value::as<traQAPI::UserGroup>() const;

#endif
