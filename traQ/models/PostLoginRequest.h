#ifndef TRAQ_PostLoginRequest_H
#define TRAQ_PostLoginRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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
template <> traQApi::PostLoginRequest Json::Value::as<traQApi::PostLoginRequest>() const;

#endif
