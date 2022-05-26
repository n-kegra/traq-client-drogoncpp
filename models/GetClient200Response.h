#ifndef _GetClient200Response_H
#define _GetClient200Response_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/OAuth2Client.h"
#include "../models/OAuth2ClientDetail.h"
#include "../models/OAuth2Scope.h"
#include <vector>

namespace traQ {

struct GetClient200Response {
    std::string id;
    std::string name;
    std::string description;
    std::string developerId;
    std::vector<OAuth2Scope> scopes;
    std::string callbackUrl;
    std::string secret;

    operator Json::Value() const {
        return this->toJson();
    }
    GetClient200Response(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["name"] = (name);
        _json["description"] = (description);
        _json["developerId"] = (developerId);
        _json["scopes"] = Helper::toJson(scopes);
        _json["callbackUrl"] = (callbackUrl);
        _json["secret"] = (secret);
        return _json;
    }
    GetClient200Response& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        developerId = _json["developerId"].as<std::string>();
        scopes = _json["scopes"].as<std::vector<OAuth2Scope>>();
        callbackUrl = _json["callbackUrl"].as<std::string>();
        secret = _json["secret"].as<std::string>();
        return *this;
    }
};

}

#endif
