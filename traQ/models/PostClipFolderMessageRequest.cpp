#include <traQ/models/PostClipFolderMessageRequest.h>

namespace traQApi {

PostClipFolderMessageRequest::operator Json::Value() const {
    return this->toJson();
}
PostClipFolderMessageRequest::PostClipFolderMessageRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PostClipFolderMessageRequest Json::Value::as<traQApi::PostClipFolderMessageRequest>() const {
    return traQApi::PostClipFolderMessageRequest(*this);
};
