#include <traQ/models/PatchClientRequest.h>
#include "../Helper.h"

namespace traQApi {

PatchClientRequest::operator Json::Value() const {
    return this->toJson();
}
PatchClientRequest::PatchClientRequest(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value PatchClientRequest::toJson() const {
    Json::Value _json;
    _json["name"] = (name);
    _json["description"] = (description);
    _json["callbackUrl"] = (callbackUrl);
    _json["developerId"] = (developerId);
    return _json;
}
PatchClientRequest& PatchClientRequest::fromJson(const Json::Value& _json) {
    name = _json["name"].as<std::string>();
    description = _json["description"].as<std::string>();
    callbackUrl = _json["callbackUrl"].as<std::string>();
    developerId = _json["developerId"].as<std::string>();
    return *this;
}

}
template <> traQApi::PatchClientRequest Json::Value::as<traQApi::PatchClientRequest>() const {
    return traQApi::PatchClientRequest(*this);
};
