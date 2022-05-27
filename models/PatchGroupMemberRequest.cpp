#include "PatchGroupMemberRequest.h"

namespace traQAPI {

Json::Value PatchGroupMemberRequest::toJson() const {
    Json::Value _json;
    _json["role"] = (role);
    return _json;
}
PatchGroupMemberRequest& PatchGroupMemberRequest::fromJson(const Json::Value& _json) {
    role = _json["role"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PatchGroupMemberRequest Json::Value::as<traQAPI::PatchGroupMemberRequest>() const {
    return traQAPI::PatchGroupMemberRequest(*this);
}
