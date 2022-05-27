#include "PostClipFolderMessageRequest.h"

namespace traQAPI {

Json::Value PostClipFolderMessageRequest::toJson() const {
    Json::Value _json;
    _json["messageId"] = (messageId);
    return _json;
}
PostClipFolderMessageRequest& PostClipFolderMessageRequest::fromJson(const Json::Value& _json) {
    messageId = _json["messageId"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PostClipFolderMessageRequest Json::Value::as<traQAPI::PostClipFolderMessageRequest>() const {
    return traQAPI::PostClipFolderMessageRequest(*this);
}
