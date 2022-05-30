#ifndef TRAQ_FileInfo_H
#define TRAQ_FileInfo_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/FileInfoThumbnail.h>
#include <traQ/models/ThumbnailInfo.h>
#include <vector>

namespace traQApi {

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
template <> traQApi::FileInfo Json::Value::as<traQApi::FileInfo>() const;

#endif
