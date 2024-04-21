#ifndef TRAQ_LoginSession_H
#define TRAQ_LoginSession_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ログインセッション情報
struct LoginSession {
    std::string id;
    std::string issuedAt;

    LoginSession() = default;
    operator Json::Value() const;
    LoginSession(const Json::Value& __value);

    Json::Value toJson() const;
    LoginSession& fromJson(const Json::Value& _json);
};

}
template <> traQApi::LoginSession Json::Value::as<traQApi::LoginSession>() const;

#endif
