#ifndef _OAuth2ResponseType_H
#define _OAuth2ResponseType_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

struct OAuth2ResponseType {
    enum class Value {
        ecode,
        etoken,
        enone,
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
template <> traQAPI::OAuth2ResponseType Json::Value::as<traQAPI::OAuth2ResponseType>() const;

#endif
