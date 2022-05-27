#include "PostUserTagRequest.h"

namespace traQAPI {

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
template <> traQAPI::PostUserTagRequest Json::Value::as<traQAPI::PostUserTagRequest>() const {
    return traQAPI::PostUserTagRequest(*this);
}
