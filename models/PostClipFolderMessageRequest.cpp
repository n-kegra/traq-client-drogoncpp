#include "PostClipFolderMessageRequest.h"

namespace traQ {

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
template <> traQ::PostClipFolderMessageRequest Json::Value::as<traQ::PostClipFolderMessageRequest>() const {
    return traQ::PostClipFolderMessageRequest(*this);
}
