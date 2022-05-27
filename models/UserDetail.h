#ifndef _UserDetail_H
#define _UserDetail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/UserAccountState.h"
#include "../models/UserTag.h"
#include <vector>

namespace traQAPI {

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
    operator Json::Value() const {
        return this->toJson();
    }
    UserDetail(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    UserDetail& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::UserDetail Json::Value::as<traQAPI::UserDetail>() const;

#endif
