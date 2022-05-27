#include "PostStarRequest.h"

namespace traQAPI {

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
template <> traQAPI::PostStarRequest Json::Value::as<traQAPI::PostStarRequest>() const {
    return traQAPI::PostStarRequest(*this);
}
