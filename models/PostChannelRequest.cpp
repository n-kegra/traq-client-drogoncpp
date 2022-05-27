#include "PostChannelRequest.h"

namespace traQ {

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
template <> traQ::PostChannelRequest Json::Value::as<traQ::PostChannelRequest>() const {
    return traQ::PostChannelRequest(*this);
}
