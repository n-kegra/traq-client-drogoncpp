#include <traQ/models/PutChannelSubscribeLevelRequest.h>
#include "../Helper.h"

namespace traQApi {

PutChannelSubscribeLevelRequest::operator Json::Value() const {
    return this->toJson();
}
PutChannelSubscribeLevelRequest::PutChannelSubscribeLevelRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
};
