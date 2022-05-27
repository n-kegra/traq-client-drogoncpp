#ifndef _PatchChannelRequest_H
#define _PatchChannelRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQAPI {

// チャンネル情報変更リクエスト
struct PatchChannelRequest {
    std::string name;
    bool archived;
    bool force;
    std::string parent;

    PatchChannelRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchChannelRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchChannelRequest& fromJson(const Json::Value& _json);
};

}
template <> traQAPI::PatchChannelRequest Json::Value::as<traQAPI::PatchChannelRequest>() const;

#endif
