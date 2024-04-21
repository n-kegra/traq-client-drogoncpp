#include <traQ/models/PatchUserTagRequest.h>

namespace traQApi {

PatchUserTagRequest::operator Json::Value() const {
    return this->toJson();
}
PatchUserTagRequest::PatchUserTagRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value PatchUserTagRequest::toJson() const {
    Json::Value _json;
    _json["isLocked"] = (isLocked);
    return _json;
}
PatchUserTagRequest& PatchUserTagRequest::fromJson(const Json::Value& _json) {
    isLocked = _json["isLocked"].as<bool>();
    return *this;
}

}
template <> traQApi::PatchUserTagRequest Json::Value::as<traQApi::PatchUserTagRequest>() const {
    return traQApi::PatchUserTagRequest(*this);
};
