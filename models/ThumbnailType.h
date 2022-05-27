#ifndef _ThumbnailType_H
#define _ThumbnailType_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        switch(this->value) {
        case Value::eimage:
            return Json::Value("image");
        case Value::ewaveform:
            return Json::Value("waveform");
        case Value::Unknown:
            return Json::Value(Json::nullValue);
        }
    }
    ThumbnailType& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "image") {
            this->value = Value::eimage;
        } else
        if (s == "waveform") {
            this->value = Value::ewaveform;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> traQ::ThumbnailType Json::Value::as<traQ::ThumbnailType>() const { return traQ::ThumbnailType(*this); }

#endif
