#include <traQ/models/LoginSession.h>
#include "../Helper.h"

namespace traQApi {

LoginSession::operator Json::Value() const {
    return this->toJson();
}
LoginSession::LoginSession(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::LoginSession Json::Value::as<traQApi::LoginSession>() const {
    return traQApi::LoginSession(*this);
};
