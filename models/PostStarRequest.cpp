#include "PostStarRequest.h"

namespace traQ {

Json::Value PostStarRequest::toJson() const {
    Json::Value _json;
    _json["channelId"] = (channelId);
    return _json;
}
PostStarRequest& PostStarRequest::fromJson(const Json::Value& _json) {
    channelId = _json["channelId"].as<std::string>();
    return *this;
}

}
template <> traQ::PostStarRequest Json::Value::as<traQ::PostStarRequest>() const {
    return traQ::PostStarRequest(*this);
}
