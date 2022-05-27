#include "PostUserTagRequest.h"

namespace traQ {

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
template <> traQ::PostUserTagRequest Json::Value::as<traQ::PostUserTagRequest>() const {
    return traQ::PostUserTagRequest(*this);
}
