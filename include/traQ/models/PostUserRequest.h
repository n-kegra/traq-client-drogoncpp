#ifndef TRAQ_PostUserRequest_H
#define TRAQ_PostUserRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// ユーザー登録リクエスト
struct PostUserRequest {
    std::string name;
    std::string password;

    PostUserRequest() = default;
    operator Json::Value() const;
    PostUserRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PostUserRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PostUserRequest Json::Value::as<traQApi::PostUserRequest>() const;

#endif
