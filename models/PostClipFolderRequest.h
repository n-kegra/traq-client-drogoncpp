#ifndef _PostClipFolderRequest_H
#define _PostClipFolderRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// クリップフォルダ作成リクエスト
struct PostClipFolderRequest {
    std::string name;
    std::string description;

    PostClipFolderRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostClipFolderRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["description"] = (description);
        return _json;
    }
    PostClipFolderRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        description = _json["description"].as<std::string>();
        return *this;
    }
};

}
template <> traQ::PostClipFolderRequest Json::Value::as<traQ::PostClipFolderRequest>() const { return traQ::PostClipFolderRequest(*this); }

#endif
