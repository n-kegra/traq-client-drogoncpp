#include "PatchStampRequest.h"

namespace traQ {

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
template <> traQ::PatchStampRequest Json::Value::as<traQ::PatchStampRequest>() const {
    return traQ::PatchStampRequest(*this);
}
