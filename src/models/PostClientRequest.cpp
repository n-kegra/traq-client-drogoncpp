#include <traQ/models/PostClientRequest.h>
#include "../Helper.h"

namespace traQApi {

PostClientRequest::operator Json::Value() const {
    return this->toJson();
}
PostClientRequest::PostClientRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value PostClientRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["callbackUrl"] = (callbackUrl);
    _json["scopes"] = __Helper::toJson(scopes);
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
template <> traQApi::PostClientRequest Json::Value::as<traQApi::PostClientRequest>() const {
    return traQApi::PostClientRequest(*this);
};
