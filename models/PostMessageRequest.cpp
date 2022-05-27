#include "PostMessageRequest.h"

namespace traQ {

Json::Value PostMessageRequest::toJson() const {
    Json::Value _json;
    _json["content"] = (content);
    _json["embed"] = (embed);
    return _json;
}
PostMessageRequest& PostMessageRequest::fromJson(const Json::Value& _json) {
    content = _json["content"].as<std::string>();
    embed = _json["embed"].as<bool>();
    return *this;
}

}
template <> traQ::PostMessageRequest Json::Value::as<traQ::PostMessageRequest>() const {
    return traQ::PostMessageRequest(*this);
}
