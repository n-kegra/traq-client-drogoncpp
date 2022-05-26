#ifndef _UserGroup_H
#define _UserGroup_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/UserGroupMember.h"
#include <vector>

namespace traQ {

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

    operator Json::Value() const {
        return this->toJson();
    }
    UserGroup(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["name"] = (name);
        _json["description"] = (description);
        _json["type"] = (type);
        _json["icon"] = (icon);
        _json["members"] = Helper::toJson(members);
        _json["createdAt"] = (createdAt);
        _json["updatedAt"] = (updatedAt);
        _json["admins"] = Helper::toJson(admins);
        return _json;
    }
    UserGroup& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        type = _json["type"].as<std::string>();
        icon = _json["icon"].as<std::string>();
        members = _json["members"].as<std::vector<UserGroupMember>>();
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        admins = _json["admins"].as<std::vector<std::string>>();
        return *this;
    }
};

}

#endif
