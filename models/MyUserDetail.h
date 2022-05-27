#ifndef _MyUserDetail_H
#define _MyUserDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/UserAccountState.h"
#include "../models/UserPermission.h"
#include "../models/UserTag.h"
#include <vector>

namespace traQ {

// 自分のユーザー詳細情報
struct MyUserDetail {
    std::string id;
    std::string bio;
    std::vector<std::string> groups;
    std::vector<UserTag> tags;
    std::string updatedAt;
    std::string lastOnline;
    std::string twitterId;
    std::string name;
    std::string displayName;
    std::string iconFileId;
    bool bot;
    UserAccountState state;
    std::vector<UserPermission> permissions;
    std::string homeChannel;

    MyUserDetail() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    MyUserDetail(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    MyUserDetail& fromJson(const Json::Value& _json);
};

}
template <> traQ::MyUserDetail Json::Value::as<traQ::MyUserDetail>() const;

#endif
