#ifndef _PutMyPasswordRequest_H
#define _PutMyPasswordRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// パスワード変更リクエスト
struct PutMyPasswordRequest {
    std::string password;
    std::string newPassword;

    PutMyPasswordRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PutMyPasswordRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PutMyPasswordRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PutMyPasswordRequest Json::Value::as<traQ::PutMyPasswordRequest>() const;

#endif
