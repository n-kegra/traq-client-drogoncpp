#ifndef _OAuth2Prompt_H
#define _OAuth2Prompt_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

struct OAuth2Prompt {

    operator Json::Value() const {
        return this->toJson();
    }
    OAuth2Prompt(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    OAuth2Prompt& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
