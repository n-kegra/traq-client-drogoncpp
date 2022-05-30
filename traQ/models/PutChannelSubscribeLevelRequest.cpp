#include <traQ/models/PutChannelSubscribeLevelRequest.h>

namespace traQApi {

Json::Value PutChannelSubscribeLevelRequest::toJson() const {
    Json::Value _json;
    _json["level"] = (level);
    return _json;
}
PutChannelSubscribeLevelRequest& PutChannelSubscribeLevelRequest::fromJson(const Json::Value& _json) {
    level = _json["level"].as<ChannelSubscribeLevel>();
    return *this;
}

}
template <> traQApi::PutChannelSubscribeLevelRequest Json::Value::as<traQApi::PutChannelSubscribeLevelRequest>() const {
    return traQApi::PutChannelSubscribeLevelRequest(*this);
}
