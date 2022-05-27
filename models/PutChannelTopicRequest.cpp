#include "PutChannelTopicRequest.h"

namespace traQAPI {

Json::Value PutChannelTopicRequest::toJson() const {
    Json::Value _json;
    _json["topic"] = (topic);
    return _json;
}
PutChannelTopicRequest& PutChannelTopicRequest::fromJson(const Json::Value& _json) {
    topic = _json["topic"].as<std::string>();
    return *this;
}

}
template <> traQAPI::PutChannelTopicRequest Json::Value::as<traQAPI::PutChannelTopicRequest>() const {
    return traQAPI::PutChannelTopicRequest(*this);
}
