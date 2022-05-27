#ifndef _PostChannelRequest_H
#define _PostChannelRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// チャンネル作成リクエスト
struct PostChannelRequest {
    std::string name;
    std::string parent;

    PostChannelRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostChannelRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PostChannelRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PostChannelRequest Json::Value::as<traQAPI::PostChannelRequest>() const;

#endif
