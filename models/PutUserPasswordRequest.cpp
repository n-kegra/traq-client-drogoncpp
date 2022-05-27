#include "PutUserPasswordRequest.h"

namespace traQ {

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
template <> traQ::PutUserPasswordRequest Json::Value::as<traQ::PutUserPasswordRequest>() const {
    return traQ::PutUserPasswordRequest(*this);
}
