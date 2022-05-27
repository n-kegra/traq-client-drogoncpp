#include "PatchClipFolderRequest.h"

namespace traQ {

Json::Value PatchClipFolderRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["description"] = (description);
    return _json;
}
PatchClipFolderRequest& PatchClipFolderRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    return *this;
}

}
template <> traQ::PatchClipFolderRequest Json::Value::as<traQ::PatchClipFolderRequest>() const {
    return traQ::PatchClipFolderRequest(*this);
}
