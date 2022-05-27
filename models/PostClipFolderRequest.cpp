#include "PostClipFolderRequest.h"

namespace traQAPI {

Json::Value PostClipFolderRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["description"] = (description);
    return _json;
}
PostClipFolderRequest& PostClipFolderRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostClipFolderRequest Json::Value::as<traQAPI::PostClipFolderRequest>() const {
    return traQAPI::PostClipFolderRequest(*this);
}
