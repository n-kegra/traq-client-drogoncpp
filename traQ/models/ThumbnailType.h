#ifndef TRAQ_ThumbnailType_H
#define TRAQ_ThumbnailType_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// サムネイル画像のタイプ 
struct ThumbnailType {
    enum class Value {
        eImage,
        eWaveform,
        Unknown,
    } value;
    ThumbnailType();
    operator Json::Value() const;
    ThumbnailType(const Json::Value& __value);
    ThumbnailType(const Value __value);

    Json::Value toJson() const;
    ThumbnailType& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ThumbnailType Json::Value::as<traQApi::ThumbnailType>() const;

#endif
