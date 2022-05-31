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
    ThumbnailType() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    ThumbnailType(const Json::Value& __value) {
        this->fromJson(__value);
    }
    ThumbnailType(const Value __value) : value(__value) {}

    Json::Value toJson() const;
    ThumbnailType& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ThumbnailType Json::Value::as<traQApi::ThumbnailType>() const;

#endif
