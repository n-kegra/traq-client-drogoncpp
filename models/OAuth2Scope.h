#ifndef _OAuth2Scope_H
#define _OAuth2Scope_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// OAuth2スコープ
struct OAuth2Scope {

    operator Json::Value() const {
        return this->toJson();
    }
    OAuth2Scope(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    OAuth2Scope& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
