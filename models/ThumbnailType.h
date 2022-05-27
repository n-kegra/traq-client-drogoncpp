#ifndef _ThumbnailType_H
#define _ThumbnailType_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// サムネイル画像のタイプ 
struct ThumbnailType {
    enum class Value {
        eimage,
        ewaveform,
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
template <> traQAPI::ThumbnailType Json::Value::as<traQAPI::ThumbnailType>() const;

#endif
