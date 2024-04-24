#ifndef TRAQ_PutChannelTopicRequest_H
#define TRAQ_PutChannelTopicRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>


namespace traQApi {

// チャンネルトピック編集リクエスト
struct PutChannelTopicRequest {
    std::string topic;

    PutChannelTopicRequest() = default;
    operator Json::Value() const;
    PutChannelTopicRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PutChannelTopicRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PutChannelTopicRequest Json::Value::as<traQApi::PutChannelTopicRequest>() const;

#endif
