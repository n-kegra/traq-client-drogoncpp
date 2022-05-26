#ifndef _OAuth2ResponseType_H
#define _OAuth2ResponseType_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

struct OAuth2ResponseType {

    operator Json::Value() const {
        return this->toJson();
    }
    OAuth2ResponseType(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    OAuth2ResponseType& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
