#ifndef _PostUserRequest_H
#define _PostUserRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザー登録リクエスト
struct PostUserRequest {
    std::string name;
    std::string password;

    operator Json::Value() const {
        return this->toJson();
    }
    PostUserRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["password"] = (password);
        return _json;
    }
    PostUserRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        name = _json["name"].as<std::string>();
        password = _json["password"].as<std::string>();
        return *this;
    }
};

}

#endif
