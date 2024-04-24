#ifndef TRAQ_MyUserDetail_H
#define TRAQ_MyUserDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>

#include <traQ/models/UserAccountState.h>
#include <traQ/models/UserPermission.h>
#include <traQ/models/UserTag.h>
#include <vector>

namespace traQApi {

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
    operator Json::Value() const;
    MyUserDetail(const Json::Value& __value);

    Json::Value toJson() const;
    MyUserDetail& fromJson(const Json::Value& _json);
};

}
template <> traQApi::MyUserDetail Json::Value::as<traQApi::MyUserDetail>() const;

#endif
