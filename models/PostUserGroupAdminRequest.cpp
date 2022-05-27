#include "PostUserGroupAdminRequest.h"

namespace traQ {

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
template <> traQ::PostUserGroupAdminRequest Json::Value::as<traQ::PostUserGroupAdminRequest>() const {
    return traQ::PostUserGroupAdminRequest(*this);
}
