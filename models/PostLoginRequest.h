#ifndef _PostLoginRequest_H
#define _PostLoginRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// ログインリクエスト
struct PostLoginRequest {
    std::string name;
    std::string password;

    PostLoginRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostLoginRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostLoginRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostLoginRequest Json::Value::as<traQAPI::PostLoginRequest>() const;

#endif
