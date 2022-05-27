#include "MessageClip.h"

namespace traQAPI {

Json::Value MessageClip::toJson() const {
    Json::Value _json;
    _json["folderId"] = (folderId);
    _json["clippedAt"] = (clippedAt);
    return _json;
}
MessageClip& MessageClip::fromJson(const Json::Value& _json) {
    folderId = _json["folderId"].as<std::string>();
    clippedAt = _json["clippedAt"].as<std::string>();
    return *this;
}

}
template <> traQAPI::MessageClip Json::Value::as<traQAPI::MessageClip>() const {
    return traQAPI::MessageClip(*this);
}
