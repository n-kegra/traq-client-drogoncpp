#include "OAuth2Client.h"

namespace traQ {

Json::Value OAuth2Client::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["name"] = (name);
    _json["description"] = (description);
    _json["developerId"] = (developerId);
    _json["scopes"] = Helper::toJson(scopes);
    return _json;
}
OAuth2Client& OAuth2Client::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    developerId = _json["developerId"].as<std::string>();
    for (auto _it = _json["scopes"].begin(); _it != _json["scopes"].end(); _it++) {
        scopes.emplace_back((*_it).as<OAuth2Scope>());    
    }
    return *this;
}

}
template <> traQ::OAuth2Client Json::Value::as<traQ::OAuth2Client>() const {
    return traQ::OAuth2Client(*this);
}
