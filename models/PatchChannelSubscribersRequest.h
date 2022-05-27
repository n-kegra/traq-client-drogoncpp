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

    PatchChannelSubscribersRequest() = default;
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
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            on.emplace_back((*_it).as<std::string>());    
        }
        for (auto _it = _json.begin(); _it != _json.end(); _it++) {
            off.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> traQ::PatchChannelSubscribersRequest Json::Value::as<traQ::PatchChannelSubscribersRequest>() const { return traQ::PatchChannelSubscribersRequest(*this); }

#endif
