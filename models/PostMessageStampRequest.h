#ifndef _PostMessageStampRequest_H
#define _PostMessageStampRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// スタンプを押すリクエスト
struct PostMessageStampRequest {
    int32_t count;

    PostMessageStampRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostMessageStampRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["count"] = (count);
        return _json;
    }
    PostMessageStampRequest& fromJson(const Json::Value& _json) {
        count = _json["count"].as<int32_t>();
        return *this;
    }
};

}
template <> traQ::PostMessageStampRequest Json::Value::as<traQ::PostMessageStampRequest>() const { return traQ::PostMessageStampRequest(*this); }

#endif
