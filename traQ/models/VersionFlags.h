#ifndef TRAQ_VersionFlags_H
#define TRAQ_VersionFlags_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <vector>

namespace traQApi {

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
template <> traQApi::VersionFlags Json::Value::as<traQApi::VersionFlags>() const;

#endif
