#include "OAuth2ClientDetail.h"

namespace traQ {

Json::Value OAuth2ClientDetail::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["developerId"] = (developerId);
    _json["description"] = (description);
    _json["name"] = (name);
    _json["scopes"] = Helper::toJson(scopes);
    _json["callbackUrl"] = (callbackUrl);
    _json["secret"] = (secret);
    return _json;
}
OAuth2ClientDetail& OAuth2ClientDetail::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    developerId = _json["developerId"].as<std::string>();
    description = _json["description"].as<std::string>();
    name = _json["name"].as<std::string>();
    for (auto _it = _json["scopes"].begin(); _it != _json["scopes"].end(); _it++) {
        scopes.emplace_back((*_it).as<OAuth2Scope>());    
    }
    callbackUrl = _json["callbackUrl"].as<std::string>();
    secret = _json["secret"].as<std::string>();
    return *this;
}

}
template <> traQ::OAuth2ClientDetail Json::Value::as<traQ::OAuth2ClientDetail>() const {
    return traQ::OAuth2ClientDetail(*this);
}
