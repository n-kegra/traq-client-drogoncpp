#include <traQ/models/FileInfoThumbnail.h>
#include "../Helper.h"

namespace traQApi {

FileInfoThumbnail::operator Json::Value() const {
    return this->toJson();
}
FileInfoThumbnail::FileInfoThumbnail(const Json::Value& __value) {
    this->fromJson(__value);
}

Json::Value FileInfoThumbnail::toJson() const {
    Json::Value _json;
    _json["mime"] = (mime);
    _json["width"] = (width);
    _json["height"] = (height);
    return _json;
}
FileInfoThumbnail& FileInfoThumbnail::fromJson(const Json::Value& _json) {
    mime = _json["mime"].as<std::string>();
    width = _json["width"].as<int32_t>();
    height = _json["height"].as<int32_t>();
    return *this;
}

}
template <> traQApi::FileInfoThumbnail Json::Value::as<traQApi::FileInfoThumbnail>() const {
    return traQApi::FileInfoThumbnail(*this);
};
