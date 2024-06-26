#include <traQ/models/PatchChannelRequest.h>
#include "../Helper.h"

namespace traQApi {

PatchChannelRequest::operator Json::Value() const {
    return this->toJson();
}
PatchChannelRequest::PatchChannelRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

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
template <> traQApi::PatchChannelRequest Json::Value::as<traQApi::PatchChannelRequest>() const {
    return traQApi::PatchChannelRequest(*this);
};
