#ifndef _PostUserTagRequest_H
#define _PostUserTagRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザータグ追加リクエスト
struct PostUserTagRequest {
    std::string tag;

    operator Json::Value() const {
        return this->toJson();
    }
    PostUserTagRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["tag"] = (tag);
        return _json;
    }
    PostUserTagRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        tag = _json["tag"].as<std::string>();
        return *this;
    }
};

}

#endif
