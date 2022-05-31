#ifndef TRAQ_PostChannelRequest_H
#define TRAQ_PostChannelRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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
template <> inline traQApi::PostChannelRequest Json::Value::as<traQApi::PostChannelRequest>() const {
    return traQApi::PostChannelRequest(*this);
};

#endif
