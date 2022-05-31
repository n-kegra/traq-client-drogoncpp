#ifndef TRAQ_PostUserTagRequest_H
#define TRAQ_PostUserTagRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザータグ追加リクエスト
struct PostUserTagRequest {
    std::string tag;

    PostUserTagRequest() = default;
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
        tag = _json["tag"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PostUserTagRequest Json::Value::as<traQApi::PostUserTagRequest>() const {
    return traQApi::PostUserTagRequest(*this);
};

#endif
