#ifndef TRAQ_UserGroup_H
#define TRAQ_UserGroup_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/UserGroupMember.h>
#include <vector>

namespace traQApi {

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
template <> traQApi::UserGroup Json::Value::as<traQApi::UserGroup>() const;

#endif
