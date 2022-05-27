#ifndef _OAuth2Prompt_H
#define _OAuth2Prompt_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

struct OAuth2Prompt {
    enum class Value {
        enone,
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
template <> traQAPI::OAuth2Prompt Json::Value::as<traQAPI::OAuth2Prompt>() const;

#endif
