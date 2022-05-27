#include "PatchStampRequest.h"

namespace traQAPI {

Json::Value PatchStampRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["creatorId"] = (creatorId);
    return _json;
}
PatchStampRequest& PatchStampRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    creatorId = _json["creatorId"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PatchStampRequest Json::Value::as<traQAPI::PatchStampRequest>() const {
    return traQAPI::PatchStampRequest(*this);
}
