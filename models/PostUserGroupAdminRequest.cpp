#include "PostUserGroupAdminRequest.h"

namespace traQAPI {

Json::Value PostUserGroupAdminRequest::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    return _json;
}
PostUserGroupAdminRequest& PostUserGroupAdminRequest::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostUserGroupAdminRequest Json::Value::as<traQAPI::PostUserGroupAdminRequest>() const {
    return traQAPI::PostUserGroupAdminRequest(*this);
}
