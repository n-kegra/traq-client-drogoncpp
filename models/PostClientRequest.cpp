#include "PostClientRequest.h"

namespace traQ {

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
template <> traQ::PostClientRequest Json::Value::as<traQ::PostClientRequest>() const {
    return traQ::PostClientRequest(*this);
}
