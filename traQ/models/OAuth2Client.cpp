#include <traQ/models/OAuth2Client.h>

namespace traQApi {

OAuth2Client::operator Json::Value() const {
    return this->toJson();
}
OAuth2Client::OAuth2Client(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value OAuth2Client::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["name"] = (name);
    _json["description"] = (description);
    _json["developerId"] = (developerId);
    _json["scopes"] = __Helper::toJson(scopes);
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
template <> traQApi::OAuth2Client Json::Value::as<traQApi::OAuth2Client>() const {
    return traQApi::OAuth2Client(*this);
};
