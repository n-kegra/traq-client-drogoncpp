#include <traQ/models/PostUserTagRequest.h>

namespace traQApi {

Json::Value PostUserTagRequest::toJson() const {
    Json::Value _json;
    _json["tag"] = (tag);
    return _json;
}
PostUserTagRequest& PostUserTagRequest::fromJson(const Json::Value& _json) {
    tag = _json["tag"].as<std::string>();
    return *this;
}

}
template <> traQApi::PostUserTagRequest Json::Value::as<traQApi::PostUserTagRequest>() const {
    return traQApi::PostUserTagRequest(*this);
}
