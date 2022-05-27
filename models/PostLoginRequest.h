#ifndef _PostLoginRequest_H
#define _PostLoginRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["password"] = (password);
        return _json;
    }
    PostLoginRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        password = _json["password"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::PostLoginRequest Json::Value::as<traQ::PostLoginRequest>() const { return traQ::PostLoginRequest(*this); }

#endif
