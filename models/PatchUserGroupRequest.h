#ifndef _PatchUserGroupRequest_H
#define _PatchUserGroupRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// ユーザーグループ編集リクエスト
struct PatchUserGroupRequest {
    std::string name;
    std::string description;
    std::string type;

    PatchUserGroupRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchUserGroupRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchUserGroupRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PatchUserGroupRequest Json::Value::as<traQAPI::PatchUserGroupRequest>() const;

#endif
