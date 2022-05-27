#include "MessageClip.h"

namespace traQ {

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
template <> traQ::MessageClip Json::Value::as<traQ::MessageClip>() const {
    return traQ::MessageClip(*this);
}
