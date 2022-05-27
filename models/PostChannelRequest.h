#ifndef _PostChannelRequest_H
#define _PostChannelRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["parent"] = (parent);
        return _json;
    }
    PostChannelRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        parent = _json["parent"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::PostChannelRequest Json::Value::as<traQ::PostChannelRequest>() const { return traQ::PostChannelRequest(*this); }

#endif
