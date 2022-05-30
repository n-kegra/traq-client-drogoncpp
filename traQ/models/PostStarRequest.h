#ifndef TRAQ_PostStarRequest_H
#define TRAQ_PostStarRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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
template <> traQApi::PostStarRequest Json::Value::as<traQApi::PostStarRequest>() const;

#endif
