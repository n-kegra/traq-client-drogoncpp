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

    operator Json::Value() const {
        return this->toJson();
    }
    ThumbnailType(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        return _json;
    }
    ThumbnailType& fromJson(const Json::Value& _json) {
        Json::Value _json;
        return *this;
    }
};

}

#endif
