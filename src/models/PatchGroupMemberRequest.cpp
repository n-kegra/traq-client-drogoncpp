#include <traQ/models/PatchGroupMemberRequest.h>
#include "../Helper.h"

namespace traQApi {

PatchGroupMemberRequest::operator Json::Value() const {
    return this->toJson();
}
PatchGroupMemberRequest::PatchGroupMemberRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PatchGroupMemberRequest Json::Value::as<traQApi::PatchGroupMemberRequest>() const {
    return traQApi::PatchGroupMemberRequest(*this);
};
