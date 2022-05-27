#include "PostClientRequest.h"

namespace traQAPI {

Json::Value PostClientRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["callbackUrl"] = (callbackUrl);
    _json["scopes"] = Helper::toJson(scopes);
    _json["description"] = (description);
    return _json;
}
PostClientRequest& PostClientRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    callbackUrl = _json["callbackUrl"].as<std::string>();
    for (auto _it = _json["scopes"].begin(); _it != _json["scopes"].end(); _it++) {
        scopes.emplace_back((*_it).as<OAuth2Scope>());    
    }
    description = _json["description"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostClientRequest Json::Value::as<traQAPI::PostClientRequest>() const {
    return traQAPI::PostClientRequest(*this);
}
