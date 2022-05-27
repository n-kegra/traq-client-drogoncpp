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

    Json::Value toJson() const {
        Json::Value _json;
        _json["newPassword"] = (newPassword);
        return _json;
    }
    PutUserPasswordRequest& fromJson(const Json::Value& _json) {
        newPassword = _json["newPassword"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::PutUserPasswordRequest Json::Value::as<traQ::PutUserPasswordRequest>() const { return traQ::PutUserPasswordRequest(*this); }

#endif
