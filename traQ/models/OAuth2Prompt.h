#ifndef TRAQ_OAuth2Prompt_H
#define TRAQ_OAuth2Prompt_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

struct OAuth2Prompt {
    enum class Value {
        eNone,
        Unknown,
    } value;
    OAuth2Prompt() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    OAuth2Prompt(const Json::Value& __value) {
        this->fromJson(__value);
    }
    OAuth2Prompt(const Value __value) : value(__value) {}

    Json::Value toJson() const {
        switch(this->value) {
        case Value::eNone:
            return Json::Value("none");
        default:
            return Json::Value(Json::nullValue);
        }
    }
    OAuth2Prompt& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
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
template <> inline traQApi::OAuth2Prompt Json::Value::as<traQApi::OAuth2Prompt>() const {
    return traQApi::OAuth2Prompt(*this);
};

#endif
