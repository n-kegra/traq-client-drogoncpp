#ifndef _OAuth2ResponseType_H
#define _OAuth2ResponseType_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        switch(this->value) {
        case Value::ecode:
            return Json::Value("code");
        case Value::etoken:
            return Json::Value("token");
        case Value::enone:
            return Json::Value("none");
        case Value::Unknown:
            return Json::Value(Json::nullValue);
        }
    }
    OAuth2ResponseType& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "code") {
            this->value = Value::ecode;
        } else
        if (s == "token") {
            this->value = Value::etoken;
        } else
        if (s == "none") {
            this->value = Value::enone;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> traQ::OAuth2ResponseType Json::Value::as<traQ::OAuth2ResponseType>() const { return traQ::OAuth2ResponseType(*this); }

#endif
