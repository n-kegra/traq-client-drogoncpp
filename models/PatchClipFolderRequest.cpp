#include "PatchClipFolderRequest.h"

namespace traQAPI {

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
template <> traQAPI::PatchClipFolderRequest Json::Value::as<traQAPI::PatchClipFolderRequest>() const {
    return traQAPI::PatchClipFolderRequest(*this);
}
