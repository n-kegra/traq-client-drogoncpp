#ifndef TRAQ_FileInfoThumbnail_H
#define TRAQ_FileInfoThumbnail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// サムネイル情報 サムネイルが存在しない場合はnullになります Deprecated: thumbnailsを参照してください
struct FileInfoThumbnail {
    std::string mime;
    int32_t width;
    int32_t height;

    FileInfoThumbnail() = default;
    operator Json::Value() const;
    FileInfoThumbnail(const Json::Value& __value);

    Json::Value toJson() const;
    FileInfoThumbnail& fromJson(const Json::Value& _json);
};

}
template <> traQApi::FileInfoThumbnail Json::Value::as<traQApi::FileInfoThumbnail>() const;

#endif
