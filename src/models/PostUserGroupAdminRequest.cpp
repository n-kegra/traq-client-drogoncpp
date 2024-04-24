#include <traQ/models/PostUserGroupAdminRequest.h>
#include "../Helper.h"

namespace traQApi {

PostUserGroupAdminRequest::operator Json::Value() const {
    return this->toJson();
}
PostUserGroupAdminRequest::PostUserGroupAdminRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
};
