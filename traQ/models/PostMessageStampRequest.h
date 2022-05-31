#ifndef TRAQ_PostMessageStampRequest_H
#define TRAQ_PostMessageStampRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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
template <> inline traQApi::PostMessageStampRequest Json::Value::as<traQApi::PostMessageStampRequest>() const {
    return traQApi::PostMessageStampRequest(*this);
};

#endif
