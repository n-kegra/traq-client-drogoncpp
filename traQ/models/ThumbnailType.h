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

    Json::Value toJson() const {
        switch(this->value) {
        case Value::eImage:
            return Json::Value("image");
        case Value::eWaveform:
            return Json::Value("waveform");
        default:
            return Json::Value(Json::nullValue);
        }
    }
    ThumbnailType& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "image") {
            this->value = Value::eImage;
        } else
        if (s == "waveform") {
            this->value = Value::eWaveform;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> inline traQApi::ThumbnailType Json::Value::as<traQApi::ThumbnailType>() const {
    return traQApi::ThumbnailType(*this);
};

#endif
