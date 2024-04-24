#include <traQ/models/PatchClipFolderRequest.h>
#include "../Helper.h"

namespace traQApi {

PatchClipFolderRequest::operator Json::Value() const {
    return this->toJson();
}
PatchClipFolderRequest::PatchClipFolderRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PatchClipFolderRequest Json::Value::as<traQApi::PatchClipFolderRequest>() const {
    return traQApi::PatchClipFolderRequest(*this);
};
