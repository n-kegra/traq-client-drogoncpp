#ifndef _PutChannelTopicRequest_H
#define _PutChannelTopicRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// チャンネルトピック編集リクエスト
struct PutChannelTopicRequest {
    std::string topic;

    PutChannelTopicRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PutChannelTopicRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PutChannelTopicRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PutChannelTopicRequest Json::Value::as<traQ::PutChannelTopicRequest>() const;

#endif
