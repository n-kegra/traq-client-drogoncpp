#ifndef _OAuth2Client_H
#define _OAuth2Client_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/OAuth2Scope.h"
#include <vector>

namespace traQ {

// OAuth2クライアント情報
struct OAuth2Client {
    std::string id;
    std::string name;
    std::string description;
    std::string developerId;
    std::vector<OAuth2Scope> scopes;

    OAuth2Client() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    OAuth2Client(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["name"] = (name);
        _json["description"] = (description);
        _json["developerId"] = (developerId);
        _json["scopes"] = Helper::toJson(scopes);
        return _json;
    }
    OAuth2Client& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        developerId = _json["developerId"].as<std::string>();
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            scopes.emplace_back((*_it).as<OAuth2Scope>());    
        }
        return *this;
    }
};

}
template <> traQ::OAuth2Client Json::Value::as<traQ::OAuth2Client>() const { return traQ::OAuth2Client(*this); }

#endif
