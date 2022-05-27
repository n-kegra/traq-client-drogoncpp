#include "PutMyPasswordRequest.h"

namespace traQAPI {

Json::Value PutMyPasswordRequest::toJson() const {
    Json::Value _json;
    _json["password"] = (password);
    _json["newPassword"] = (newPassword);
    return _json;
}
PutMyPasswordRequest& PutMyPasswordRequest::fromJson(const Json::Value& _json) {
    password = _json["password"].as<std::string>();
    newPassword = _json["newPassword"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PutMyPasswordRequest Json::Value::as<traQAPI::PutMyPasswordRequest>() const {
    return traQAPI::PutMyPasswordRequest(*this);
}
