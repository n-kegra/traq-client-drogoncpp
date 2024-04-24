#include <traQ/models/PostStarRequest.h>
#include "../Helper.h"

namespace traQApi {

PostStarRequest::operator Json::Value() const {
    return this->toJson();
}
PostStarRequest::PostStarRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PostStarRequest Json::Value::as<traQApi::PostStarRequest>() const {
    return traQApi::PostStarRequest(*this);
};
