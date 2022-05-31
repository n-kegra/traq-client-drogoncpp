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

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["name"] = (name);
        _json["description"] = (description);
        _json["type"] = (type);
        _json["icon"] = (icon);
        _json["members"] = __Helper::toJson(members);
        _json["createdAt"] = (createdAt);
        _json["updatedAt"] = (updatedAt);
        _json["admins"] = __Helper::toJson(admins);
        return _json;
    }
    UserGroup& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        type = _json["type"].as<std::string>();
        icon = _json["icon"].as<std::string>();
        for (auto _it = _json["members"].begin(); _it != _json["members"].end(); _it++) {
            members.emplace_back((*_it));    
        }
        createdAt = _json["createdAt"].as<std::string>();
        updatedAt = _json["updatedAt"].as<std::string>();
        for (auto _it = _json["admins"].begin(); _it != _json["admins"].end(); _it++) {
            admins.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> inline traQApi::UserGroup Json::Value::as<traQApi::UserGroup>() const {
    return traQApi::UserGroup(*this);
};

#endif
