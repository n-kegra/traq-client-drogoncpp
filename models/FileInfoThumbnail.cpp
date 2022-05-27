#include "FileInfoThumbnail.h"

namespace traQAPI {

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
template <> traQAPI::FileInfoThumbnail Json::Value::as<traQAPI::FileInfoThumbnail>() const {
    return traQAPI::FileInfoThumbnail(*this);
}
