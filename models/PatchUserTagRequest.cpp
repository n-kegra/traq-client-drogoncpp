#include "PatchUserTagRequest.h"

namespace traQAPI {

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
template <> traQAPI::PatchUserTagRequest Json::Value::as<traQAPI::PatchUserTagRequest>() const {
    return traQAPI::PatchUserTagRequest(*this);
}
