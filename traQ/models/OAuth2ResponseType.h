#ifndef TRAQ_OAuth2ResponseType_H
#define TRAQ_OAuth2ResponseType_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

struct OAuth2ResponseType {
    enum class Value {
        eCode,
        eToken,
        eNone,
        Unknown,
    } value;
    OAuth2ResponseType() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    OAuth2ResponseType(const Json::Value& __value) {
        this->fromJson(__value);
    }
    OAuth2ResponseType(const Value __value) : value(__value) {}

    Json::Value toJson() const;
    OAuth2ResponseType& fromJson(const Json::Value& _json);
};

}
template <> traQApi::OAuth2ResponseType Json::Value::as<traQApi::OAuth2ResponseType>() const;

#endif
