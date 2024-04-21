#ifndef TRAQ_UserDetail_H
#define TRAQ_UserDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/UserAccountState.h>
#include <traQ/models/UserTag.h>
#include <vector>

namespace traQApi {

// ユーザー詳細情報
struct UserDetail {
    std::string id;
    UserAccountState state;
    bool bot;
    std::string iconFileId;
    std::string displayName;
    std::string name;
    std::string twitterId;
    std::string lastOnline;
    std::string updatedAt;
    std::vector<UserTag> tags;
    std::vector<std::string> groups;
    std::string bio;
    std::string homeChannel;

    UserDetail() = default;
    operator Json::Value() const;
    UserDetail(const Json::Value& __value);

    Json::Value toJson() const;
    UserDetail& fromJson(const Json::Value& _json);
};

}
template <> traQApi::UserDetail Json::Value::as<traQApi::UserDetail>() const;

#endif
