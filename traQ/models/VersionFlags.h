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

    Json::Value toJson() const {
        Json::Value _json;
        _json["externalLogin"] = __Helper::toJson(externalLogin);
        _json["signUpAllowed"] = (signUpAllowed);
        return _json;
    }
    VersionFlags& fromJson(const Json::Value& _json) {
        for (auto _it = _json["externalLogin"].begin(); _it != _json["externalLogin"].end(); _it++) {
            externalLogin.emplace_back((*_it).as<std::string>());    
        }
        signUpAllowed = _json["signUpAllowed"].as<bool>();
        return *this;
    }
};

}
template <> inline traQApi::VersionFlags Json::Value::as<traQApi::VersionFlags>() const {
    return traQApi::VersionFlags(*this);
};

#endif
