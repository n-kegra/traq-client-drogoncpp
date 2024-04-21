#include <traQ/models/PostChannelRequest.h>

namespace traQApi {

PostChannelRequest::operator Json::Value() const {
    return this->toJson();
}
PostChannelRequest::PostChannelRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value PostChannelRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["parent"] = (parent);
    return _json;
}
PostChannelRequest& PostChannelRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    parent = _json["parent"].as<std::string>();
    return *this;
}

}
template <> traQApi::PostChannelRequest Json::Value::as<traQApi::PostChannelRequest>() const {
    return traQApi::PostChannelRequest(*this);
};
