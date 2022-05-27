#include "PatchChannelRequest.h"

namespace traQ {

Json::Value PatchChannelRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["archived"] = (archived);
    _json["force"] = (force);
    _json["parent"] = (parent);
    return _json;
}
PatchChannelRequest& PatchChannelRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    archived = _json["archived"].as<bool>();
    force = _json["force"].as<bool>();
    parent = _json["parent"].as<std::string>();
    return *this;
}

}
template <> traQ::PatchChannelRequest Json::Value::as<traQ::PatchChannelRequest>() const {
    return traQ::PatchChannelRequest(*this);
}
