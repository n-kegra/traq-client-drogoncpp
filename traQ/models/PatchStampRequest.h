#ifndef TRAQ_PatchStampRequest_H
#define TRAQ_PatchStampRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// スタンプ情報変更リクエスト
struct PatchStampRequest {
    std::string name;
    std::string creatorId;

    PatchStampRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchStampRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["creatorId"] = (creatorId);
        return _json;
    }
    PatchStampRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        creatorId = _json["creatorId"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PatchStampRequest Json::Value::as<traQApi::PatchStampRequest>() const {
    return traQApi::PatchStampRequest(*this);
};

#endif
