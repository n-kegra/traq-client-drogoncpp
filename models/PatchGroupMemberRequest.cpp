#include "PatchGroupMemberRequest.h"

namespace traQ {

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
template <> traQ::PatchGroupMemberRequest Json::Value::as<traQ::PatchGroupMemberRequest>() const {
    return traQ::PatchGroupMemberRequest(*this);
}
