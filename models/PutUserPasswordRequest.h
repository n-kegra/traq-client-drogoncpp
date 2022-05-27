#ifndef _PutUserPasswordRequest_H
#define _PutUserPasswordRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザーパスワード変更リクエスト
struct PutUserPasswordRequest {
    std::string newPassword;

    PutUserPasswordRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PutUserPasswordRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PutUserPasswordRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PutUserPasswordRequest Json::Value::as<traQ::PutUserPasswordRequest>() const;

#endif
