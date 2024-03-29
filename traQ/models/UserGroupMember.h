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

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["role"] = (role);
        return _json;
    }
    UserGroupMember& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        role = _json["role"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::UserGroupMember Json::Value::as<traQApi::UserGroupMember>() const {
    return traQApi::UserGroupMember(*this);
};

#endif
