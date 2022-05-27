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

    VersionFlags() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    VersionFlags(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    VersionFlags& fromJson(const Json::Value& _json);
};

}
template <> traQ::VersionFlags Json::Value::as<traQ::VersionFlags>() const;

#endif
