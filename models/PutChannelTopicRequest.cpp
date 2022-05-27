#include "PutChannelTopicRequest.h"

namespace traQ {

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
template <> traQ::PutChannelTopicRequest Json::Value::as<traQ::PutChannelTopicRequest>() const {
    return traQ::PutChannelTopicRequest(*this);
}
