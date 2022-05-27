#ifndef _LoginSession_H
#define _LoginSession_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ログインセッション情報
struct LoginSession {
    std::string id;
    std::string issuedAt;

    LoginSession() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    LoginSession(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["issuedAt"] = (issuedAt);
        return _json;
    }
    LoginSession& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        issuedAt = _json["issuedAt"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::LoginSession Json::Value::as<traQ::LoginSession>() const { return traQ::LoginSession(*this); }

#endif
