#ifndef TRAQ_PatchChannelSubscribersRequest_H
#define TRAQ_PatchChannelSubscribersRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <vector>

namespace traQApi {

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
        _json["on"] = __Helper::toJson(on);
        _json["off"] = __Helper::toJson(off);
        return _json;
    }
    PatchChannelSubscribersRequest& fromJson(const Json::Value& _json) {
        for (auto _it = _json["on"].begin(); _it != _json["on"].end(); _it++) {
            on.emplace_back((*_it).as<std::string>());    
        }
        for (auto _it = _json["off"].begin(); _it != _json["off"].end(); _it++) {
            off.emplace_back((*_it).as<std::string>());    
        }
        return *this;
    }
};

}
template <> inline traQApi::PatchChannelSubscribersRequest Json::Value::as<traQApi::PatchChannelSubscribersRequest>() const {
    return traQApi::PatchChannelSubscribersRequest(*this);
};

#endif
