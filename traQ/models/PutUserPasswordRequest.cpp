#include <traQ/models/PutUserPasswordRequest.h>

namespace traQApi {

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
template <> traQApi::PutUserPasswordRequest Json::Value::as<traQApi::PutUserPasswordRequest>() const {
    return traQApi::PutUserPasswordRequest(*this);
}
