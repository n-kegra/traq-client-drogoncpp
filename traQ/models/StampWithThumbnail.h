#ifndef TRAQ_StampWithThumbnail_H
#define TRAQ_StampWithThumbnail_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// スタンプ情報とサムネイルの有無
struct StampWithThumbnail {
    std::string id;
    std::string name;
    std::string creatorId;
    std::string createdAt;
    std::string updatedAt;
    std::string fileId;
    bool isUnicode;
    bool hasThumbnail;

    StampWithThumbnail() = default;
    operator Json::Value() const;
    StampWithThumbnail(const Json::Value& __value);

    Json::Value toJson() const;
    StampWithThumbnail& fromJson(const Json::Value& _json);
};

}
template <> traQApi::StampWithThumbnail Json::Value::as<traQApi::StampWithThumbnail>() const;

#endif
