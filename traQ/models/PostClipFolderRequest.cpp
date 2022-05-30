#include <traQ/models/PostClipFolderRequest.h>

namespace traQApi {

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
template <> traQApi::PostClipFolderRequest Json::Value::as<traQApi::PostClipFolderRequest>() const {
    return traQApi::PostClipFolderRequest(*this);
}
