#include "PutChannelSubscribeLevelRequest.h"

namespace traQAPI {

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
template <> traQAPI::PutChannelSubscribeLevelRequest Json::Value::as<traQAPI::PutChannelSubscribeLevelRequest>() const {
    return traQAPI::PutChannelSubscribeLevelRequest(*this);
}
