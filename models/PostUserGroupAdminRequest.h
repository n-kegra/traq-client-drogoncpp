#ifndef _PostUserGroupAdminRequest_H
#define _PostUserGroupAdminRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// グループ管理者追加リクエスト
struct PostUserGroupAdminRequest {
    std::string id;

    PostUserGroupAdminRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostUserGroupAdminRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostUserGroupAdminRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PostUserGroupAdminRequest Json::Value::as<traQ::PostUserGroupAdminRequest>() const;

#endif
