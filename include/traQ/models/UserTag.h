#ifndef TRAQ_UserTag_H
#define TRAQ_UserTag_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// ユーザータグ
struct UserTag {
    std::string tagId;
    std::string tag;
    bool isLocked;
    std::string createdAt;
    std::string updatedAt;

    UserTag() = default;
    operator Json::Value() const;
    UserTag(const Json::Value& __value);

    Json::Value toJson() const;
    UserTag& fromJson(const Json::Value& _json);
};

}
template <> traQApi::UserTag Json::Value::as<traQApi::UserTag>() const;

#endif
