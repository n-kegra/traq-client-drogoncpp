#ifndef TRAQ_PostClipFolderRequest_H
#define TRAQ_PostClipFolderRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

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
template <> inline traQApi::PostClipFolderRequest Json::Value::as<traQApi::PostClipFolderRequest>() const {
    return traQApi::PostClipFolderRequest(*this);
};

#endif
