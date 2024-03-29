#ifndef TRAQ_PostUserRequest_H
#define TRAQ_PostUserRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["password"] = (password);
        return _json;
    }
    PostUserRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        password = _json["password"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PostUserRequest Json::Value::as<traQApi::PostUserRequest>() const {
    return traQApi::PostUserRequest(*this);
};

#endif
