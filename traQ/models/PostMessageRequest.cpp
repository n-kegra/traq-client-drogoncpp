#include <traQ/models/PostMessageRequest.h>

namespace traQApi {

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
template <> traQApi::PostMessageRequest Json::Value::as<traQApi::PostMessageRequest>() const {
    return traQApi::PostMessageRequest(*this);
}
