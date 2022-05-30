#include <traQ/models/PostUserGroupAdminRequest.h>

namespace traQApi {

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
template <> traQApi::PostUserGroupAdminRequest Json::Value::as<traQApi::PostUserGroupAdminRequest>() const {
    return traQApi::PostUserGroupAdminRequest(*this);
}
