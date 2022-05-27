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

    Json::Value toJson() const;
    LoginSession& fromJson(const Json::Value& _json);
};

}
template <> traQ::LoginSession Json::Value::as<traQ::LoginSession>() const;

#endif
