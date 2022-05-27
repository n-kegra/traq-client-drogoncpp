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

    UserGroup() = default;
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
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        type = _json["type"].as<std::string>();
        icon = _json["icon"].as<std::string>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            members.emplace_back((*_it));    
        }
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            admins.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> traQ::UserGroup Json::Value::as<traQ::UserGroup>() const { return traQ::UserGroup(*this); }

#endif
