#ifndef _UserPermission_H
#define _UserPermission_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザー権限
struct UserPermission {

    operator Json::Value() const {
        return this->toJson();
    }
    UserPermission(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    UserPermission& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
