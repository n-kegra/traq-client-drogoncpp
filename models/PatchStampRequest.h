#ifndef _PatchStampRequest_H
#define _PatchStampRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

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
template <> traQ::PatchStampRequest Json::Value::as<traQ::PatchStampRequest>() const { return traQ::PatchStampRequest(*this); }

#endif
