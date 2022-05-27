#ifndef _User_H
#define _User_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/UserAccountState.h"

namespace traQ {

// ユーザー情報
struct User {
    std::string id;
    std::string name;
    std::string displayName;
    std::string iconFileId;
    bool bot;
    UserAccountState state;
    std::string updatedAt;

    User() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    User(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    User& fromJson(const Json::Value& _json);
};

}
template <> traQ::User Json::Value::as<traQ::User>() const;

#endif
