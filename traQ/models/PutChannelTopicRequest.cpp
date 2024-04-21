#include <traQ/models/PutChannelTopicRequest.h>

namespace traQApi {

PutChannelTopicRequest::operator Json::Value() const {
    return this->toJson();
}
PutChannelTopicRequest::PutChannelTopicRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PutChannelTopicRequest Json::Value::as<traQApi::PutChannelTopicRequest>() const {
    return traQApi::PutChannelTopicRequest(*this);
};
