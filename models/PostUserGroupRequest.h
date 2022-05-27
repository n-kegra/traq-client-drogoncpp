#ifndef _PostUserGroupRequest_H
#define _PostUserGroupRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザーグループ作成リクエスト
struct PostUserGroupRequest {
    std::string name;
    std::string description;
    std::string type;

    PostUserGroupRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostUserGroupRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostUserGroupRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PostUserGroupRequest Json::Value::as<traQ::PostUserGroupRequest>() const;

#endif
