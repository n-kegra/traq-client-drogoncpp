#ifndef _UserGroupMember_H
#define _UserGroupMember_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザーグループメンバー
struct UserGroupMember {
    std::string id;
    std::string role;

    operator Json::Value() const {
        return this->toJson();
    }
    UserGroupMember(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["role"] = (role);
        return _json;
    }
    UserGroupMember& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        role = _json["role"].as<std::string>();
        return *this;
    }
};

}

#endif
