#ifndef TRAQ_GetClient200Response_H
#define TRAQ_GetClient200Response_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/OAuth2Client.h>
#include <traQ/models/OAuth2ClientDetail.h>
#include <traQ/models/OAuth2Scope.h>
#include <vector>

namespace traQApi {

struct GetClient200Response {
    std::string id;
    std::string name;
    std::string description;
    std::string developerId;
    std::vector<OAuth2Scope> scopes;
    std::string callbackUrl;
    std::string secret;

    GetClient200Response() = default;
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
        _json["scopes"] = __Helper::toJson(scopes);
        _json["callbackUrl"] = (callbackUrl);
        _json["secret"] = (secret);
        return _json;
    }
    GetClient200Response& fromJson(const Json::Value& _json) {
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        developerId = _json["developerId"].as<std::string>();
        for (auto _it = _json["scopes"].begin(); _it != _json["scopes"].end(); _it++) {
            scopes.emplace_back((*_it).as<OAuth2Scope>());    
        }
        callbackUrl = _json["callbackUrl"].as<std::string>();
        secret = _json["secret"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::GetClient200Response Json::Value::as<traQApi::GetClient200Response>() const {
    return traQApi::GetClient200Response(*this);
};

#endif
