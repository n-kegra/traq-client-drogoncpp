#ifndef _PostMessageRequest_H
#define _PostMessageRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// メッセージ投稿リクエスト
struct PostMessageRequest {
    std::string content;
    bool embed;

    operator Json::Value() const {
        return this->toJson();
    }
    PostMessageRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["content"] = (content);
        _json["embed"] = (embed);
        return _json;
    }
    PostMessageRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        content = _json["content"].as<std::string>();
        embed = _json["embed"].as<bool>();
        return *this;
    }
};

}

#endif
