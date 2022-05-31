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

    Json::Value toJson() const;
    OAuth2Prompt& fromJson(const Json::Value& _json);
};

}
template <> traQApi::OAuth2Prompt Json::Value::as<traQApi::OAuth2Prompt>() const;

#endif
