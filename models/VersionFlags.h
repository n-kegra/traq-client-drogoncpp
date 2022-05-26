#ifndef _VersionFlags_H
#define _VersionFlags_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQ {

struct VersionFlags {
    std::vector<std::string> externalLogin;
    bool signUpAllowed;

    operator Json::Value() const {
        return this->toJson();
    }
    VersionFlags(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["externalLogin"] = Helper::toJson(externalLogin);
        _json["signUpAllowed"] = (signUpAllowed);
        return _json;
    }
    VersionFlags& fromJson(const Json::Value& _json) {
        Json::Value _json;
        externalLogin = _json["externalLogin"].as<std::vector<std::string>>();
        signUpAllowed = _json["signUpAllowed"].as<bool>();
        return *this;
    }
};

}

#endif