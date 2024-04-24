#ifndef TRAQ_PutMyPasswordRequest_H
#define TRAQ_PutMyPasswordRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// パスワード変更リクエスト
struct PutMyPasswordRequest {
    std::string password;
    std::string newPassword;

    PutMyPasswordRequest() = default;
    operator Json::Value() const;
    PutMyPasswordRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PutMyPasswordRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PutMyPasswordRequest Json::Value::as<traQApi::PutMyPasswordRequest>() const;

#endif
