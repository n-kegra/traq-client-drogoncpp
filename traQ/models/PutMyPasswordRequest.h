#ifndef TRAQ_PutMyPasswordRequest_H
#define TRAQ_PutMyPasswordRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["password"] = (password);
        _json["newPassword"] = (newPassword);
        return _json;
    }
    PutMyPasswordRequest& fromJson(const Json::Value& _json) {
        password = _json["password"].as<std::string>();
        newPassword = _json["newPassword"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PutMyPasswordRequest Json::Value::as<traQApi::PutMyPasswordRequest>() const {
    return traQApi::PutMyPasswordRequest(*this);
};

#endif
