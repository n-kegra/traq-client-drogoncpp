#ifndef _PatchChannelSubscribersRequest_H
#define _PatchChannelSubscribersRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include <vector>

namespace traQ {

// チャンネル購読者編集リクエスト
struct PatchChannelSubscribersRequest {
    std::vector<std::string> on;
    std::vector<std::string> off;

    operator Json::Value() const {
        return this->toJson();
    }
    PatchChannelSubscribersRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["on"] = Helper::toJson(on);
        _json["off"] = Helper::toJson(off);
        return _json;
    }
    PatchChannelSubscribersRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        on = _json["on"].as<std::vector<std::string>>();
        off = _json["off"].as<std::vector<std::string>>();
        return *this;
    }
};

}

#endif
