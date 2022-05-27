#include "PutChannelSubscribeLevelRequest.h"

namespace traQ {

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
template <> traQ::PutChannelSubscribeLevelRequest Json::Value::as<traQ::PutChannelSubscribeLevelRequest>() const {
    return traQ::PutChannelSubscribeLevelRequest(*this);
}
