#include "GetClient200Response.h"

namespace traQAPI {

Json::Value GetClient200Response::toJson() const {
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
GetClient200Response& GetClient200Response::fromJson(const Json::Value& _json) {
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

}
template <> traQAPI::GetClient200Response Json::Value::as<traQAPI::GetClient200Response>() const {
    return traQAPI::GetClient200Response(*this);
}
