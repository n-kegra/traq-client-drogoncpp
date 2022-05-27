#ifndef _PostUserRequest_H
#define _PostUserRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// ユーザー登録リクエスト
struct PostUserRequest {
    std::string name;
    std::string password;

    PostUserRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostUserRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostUserRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostUserRequest Json::Value::as<traQAPI::PostUserRequest>() const;

#endif
