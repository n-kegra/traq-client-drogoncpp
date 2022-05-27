#include "Stamp.h"

namespace traQAPI {

Json::Value Stamp::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["name"] = (name);
    _json["creatorId"] = (creatorId);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    _json["fileId"] = (fileId);
    _json["isUnicode"] = (isUnicode);
    return _json;
}
Stamp& Stamp::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    name = _json["name"].as<std::string>();
    creatorId = _json["creatorId"].as<std::string>();
    createdAt = _json["createdAt"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    fileId = _json["fileId"].as<std::string>();
    isUnicode = _json["isUnicode"].as<bool>();
    return *this;
}

}
template <> traQAPI::Stamp Json::Value::as<traQAPI::Stamp>() const {
    return traQAPI::Stamp(*this);
}
