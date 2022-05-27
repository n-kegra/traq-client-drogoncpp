#include "PostUserRequest.h"

namespace traQ {

Json::Value PostUserRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["password"] = (password);
    return _json;
}
PostUserRequest& PostUserRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    password = _json["password"].as<std::string>();
    return *this;
}

}
template <> traQ::PostUserRequest Json::Value::as<traQ::PostUserRequest>() const {
    return traQ::PostUserRequest(*this);
}
