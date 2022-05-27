#ifndef _UserTag_H
#define _UserTag_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザータグ
struct UserTag {
    std::string tagId;
    std::string tag;
    bool isLocked;
    std::string createdAt;
    std::string updatedAt;

    UserTag() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    UserTag(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    UserTag& fromJson(const Json::Value& _json);
};

}
template <> traQ::UserTag Json::Value::as<traQ::UserTag>() const;

#endif
