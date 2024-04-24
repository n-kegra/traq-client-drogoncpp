#include <traQ/models/MessageClip.h>
#include "../Helper.h"

namespace traQApi {

MessageClip::operator Json::Value() const {
    return this->toJson();
}
MessageClip::MessageClip(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::MessageClip Json::Value::as<traQApi::MessageClip>() const {
    return traQApi::MessageClip(*this);
};
