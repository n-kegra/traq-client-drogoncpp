#ifndef TRAQ_PatchUserGroupRequest_H
#define TRAQ_PatchUserGroupRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// ユーザーグループ編集リクエスト
struct PatchUserGroupRequest {
    std::string name;
    std::string description;
    std::string type;

    PatchUserGroupRequest() = default;
    operator Json::Value() const;
    PatchUserGroupRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchUserGroupRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchUserGroupRequest Json::Value::as<traQApi::PatchUserGroupRequest>() const;

#endif
