#include "PatchUserTagRequest.h"

namespace traQ {

Json::Value PatchUserTagRequest::toJson() const {
    Json::Value _json;
    _json["isLocked"] = (isLocked);
    return _json;
}
PatchUserTagRequest& PatchUserTagRequest::fromJson(const Json::Value& _json) {
    isLocked = _json["isLocked"].as<bool>();
    return *this;
}

}
template <> traQ::PatchUserTagRequest Json::Value::as<traQ::PatchUserTagRequest>() const {
    return traQ::PatchUserTagRequest(*this);
}
