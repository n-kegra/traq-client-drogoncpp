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

    Json::Value toJson() const {
        switch(this->value) {
        case Value::eCode:
            return Json::Value("code");
        case Value::eToken:
            return Json::Value("token");
        case Value::eNone:
            return Json::Value("none");
        default:
            return Json::Value(Json::nullValue);
        }
    }
    OAuth2ResponseType& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "code") {
            this->value = Value::eCode;
        } else
        if (s == "token") {
            this->value = Value::eToken;
        } else
        if (s == "none") {
            this->value = Value::eNone;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> inline traQApi::OAuth2ResponseType Json::Value::as<traQApi::OAuth2ResponseType>() const {
    return traQApi::OAuth2ResponseType(*this);
};

#endif
