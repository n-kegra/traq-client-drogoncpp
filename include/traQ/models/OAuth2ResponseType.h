#ifndef TRAQ_OAuth2ResponseType_H
#define TRAQ_OAuth2ResponseType_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

struct OAuth2ResponseType {
    enum class Value {
        eCode,
        eToken,
        eNone,
        Unknown,
    } value;
    OAuth2ResponseType();
    operator Json::Value() const;
    OAuth2ResponseType(const Json::Value& __value);
    OAuth2ResponseType(const Value __value);

    Json::Value toJson() const;
    OAuth2ResponseType& fromJson(const Json::Value& _json);
};

}
template <> traQApi::OAuth2ResponseType Json::Value::as<traQApi::OAuth2ResponseType>() const;

#endif
