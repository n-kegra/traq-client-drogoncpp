#ifndef TRAQ_PutUserPasswordRequest_H
#define TRAQ_PutUserPasswordRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザーパスワード変更リクエスト
struct PutUserPasswordRequest {
    std::string newPassword;

    PutUserPasswordRequest() = default;
    operator Json::Value() const;
    PutUserPasswordRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PutUserPasswordRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PutUserPasswordRequest Json::Value::as<traQApi::PutUserPasswordRequest>() const;

#endif
