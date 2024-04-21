#include <traQ/models/PatchStampRequest.h>

namespace traQApi {

PatchStampRequest::operator Json::Value() const {
    return this->toJson();
}
PatchStampRequest::PatchStampRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value PatchStampRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["creatorId"] = (creatorId);
    return _json;
}
PatchStampRequest& PatchStampRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    creatorId = _json["creatorId"].as<std::string>();
    return *this;
}

}
template <> traQApi::PatchStampRequest Json::Value::as<traQApi::PatchStampRequest>() const {
    return traQApi::PatchStampRequest(*this);
};
