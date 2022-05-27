#include "FileInfo.h"

namespace traQ {

Json::Value FileInfo::toJson() const {
    Json::Value _json;
    _json["id"] = (id);
    _json["name"] = (name);
    _json["mime"] = (mime);
    _json["size"] = (size);
    _json["md5"] = (md5);
    _json["isAnimatedImage"] = (isAnimatedImage);
    _json["createdAt"] = (createdAt);
    _json["thumbnails"] = Helper::toJson(thumbnails);
    _json["thumbnail"] = (thumbnail.toJson());
    _json["channelId"] = (channelId);
    _json["uploaderId"] = (uploaderId);
    return _json;
}
FileInfo& FileInfo::fromJson(const Json::Value& _json) {
    id = _json["id"].as<std::string>();
    name = _json["name"].as<std::string>();
    mime = _json["mime"].as<std::string>();
    size = _json["size"].as<int64_t>();
    md5 = _json["md5"].as<std::string>();
    isAnimatedImage = _json["isAnimatedImage"].as<bool>();
    createdAt = _json["createdAt"].as<std::string>();
    for (auto _it = _json["thumbnails"].begin(); _it != _json["thumbnails"].end(); _it++) {
        thumbnails.emplace_back((*_it));    
    }
    thumbnail.fromJson(_json["thumbnail"]);
    channelId = _json["channelId"].as<std::string>();
    uploaderId = _json["uploaderId"].as<std::string>();
    return *this;
}

}
template <> traQ::FileInfo Json::Value::as<traQ::FileInfo>() const {
    return traQ::FileInfo(*this);
}
