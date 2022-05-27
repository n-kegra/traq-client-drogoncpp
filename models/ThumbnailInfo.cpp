#include "ThumbnailInfo.h"

namespace traQ {

Json::Value ThumbnailInfo::toJson() const {
    Json::Value _json;
    _json["type"] = (type);
    _json["mime"] = (mime);
    _json["width"] = (width);
    _json["height"] = (height);
    return _json;
}
ThumbnailInfo& ThumbnailInfo::fromJson(const Json::Value& _json) {
    type = _json["type"].as<ThumbnailType>();
    mime = _json["mime"].as<std::string>();
    width = _json["width"].as<int32_t>();
    height = _json["height"].as<int32_t>();
    return *this;
}

}
template <> traQ::ThumbnailInfo Json::Value::as<traQ::ThumbnailInfo>() const {
    return traQ::ThumbnailInfo(*this);
}