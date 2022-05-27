#include "PutUserPasswordRequest.h"

namespace traQAPI {

Json::Value PutUserPasswordRequest::toJson() const {
    Json::Value _json;
    _json["newPassword"] = (newPassword);
    return _json;
}
PutUserPasswordRequest& PutUserPasswordRequest::fromJson(const Json::Value& _json) {
    newPassword = _json["newPassword"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PutUserPasswordRequest Json::Value::as<traQAPI::PutUserPasswordRequest>() const {
    return traQAPI::PutUserPasswordRequest(*this);
}
