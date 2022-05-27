#include "LoginSession.h"

namespace traQAPI {

Json::Value LoginSession::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["issuedAt"] = (issuedAt);
    return _json;
}
LoginSession& LoginSession::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    issuedAt = _json["issuedAt"].as<std::string>();
    return *this;
}

}
template <> traQAPI::LoginSession Json::Value::as<traQAPI::LoginSession>() const {
    return traQAPI::LoginSession(*this);
}
