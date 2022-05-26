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

    operator Json::Value() const {
        return this->toJson();
    }
    PutChannelTopicRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["topic"] = (topic);
        return _json;
    }
    PutChannelTopicRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        topic = _json["topic"].as<std::string>();
        return *this;
    }
};

}

#endif
