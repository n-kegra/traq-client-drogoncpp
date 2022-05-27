#ifndef _PostStarRequest_H
#define _PostStarRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// スター追加リクエスト
struct PostStarRequest {
    std::string channelId;

    PostStarRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostStarRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostStarRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PostStarRequest Json::Value::as<traQ::PostStarRequest>() const;

#endif
