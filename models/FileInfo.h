#ifndef _FileInfo_H
#define _FileInfo_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/FileInfoThumbnail.h"
#include "../models/ThumbnailInfo.h"
#include <vector>

namespace traQ {

// ファイル情報
struct FileInfo {
    std::string id;
    std::string name;
    std::string mime;
    int64_t size;
    std::string md5;
    bool isAnimatedImage;
    std::string createdAt;
    std::vector<ThumbnailInfo> thumbnails;
    FileInfoThumbnail thumbnail;
    std::string channelId;
    std::string uploaderId;

    operator Json::Value() const {
        return this->toJson();
    }
    FileInfo(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
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
    FileInfo& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        name = _json["name"].as<std::string>();
        mime = _json["mime"].as<std::string>();
        size = _json["size"].as<int64_t>();
        md5 = _json["md5"].as<std::string>();
        isAnimatedImage = _json["isAnimatedImage"].as<bool>();
        createdAt = _json["createdAt"].as<std::string>();
        thumbnails = _json["thumbnails"].as<std::vector<ThumbnailInfo>>();
        thumbnail = _json["thumbnail"].as<FileInfoThumbnail>();
        channelId = _json["channelId"].as<std::string>();
        uploaderId = _json["uploaderId"].as<std::string>();
        return *this;
    }
};

}

#endif
