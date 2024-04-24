#include <traQ/models/StampWithThumbnail.h>
#include "../Helper.h"

namespace traQApi {

StampWithThumbnail::operator Json::Value() const {
    return this->toJson();
}
StampWithThumbnail::StampWithThumbnail(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value StampWithThumbnail::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["name"] = (name);
    _json["creatorId"] = (creatorId);
    _json["createdAt"] = (createdAt);
    _json["updatedAt"] = (updatedAt);
    _json["fileId"] = (fileId);
    _json["isUnicode"] = (isUnicode);
    _json["hasThumbnail"] = (hasThumbnail);
    return _json;
}
StampWithThumbnail& StampWithThumbnail::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    name = _json["name"].as<std::string>();
    creatorId = _json["creatorId"].as<std::string>();
    createdAt = _json["createdAt"].as<std::string>();
    updatedAt = _json["updatedAt"].as<std::string>();
    fileId = _json["fileId"].as<std::string>();
    isUnicode = _json["isUnicode"].as<bool>();
    hasThumbnail = _json["hasThumbnail"].as<bool>();
    return *this;
}

}
template <> traQApi::StampWithThumbnail Json::Value::as<traQApi::StampWithThumbnail>() const {
    return traQApi::StampWithThumbnail(*this);
};
