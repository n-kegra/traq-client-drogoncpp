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

    FileInfo() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    FileInfo(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    FileInfo& fromJson(const Json::Value& _json);
};

}
template <> traQ::FileInfo Json::Value::as<traQ::FileInfo>() const;

#endif
