#ifndef TRAQ_PatchChannelRequest_H
#define TRAQ_PatchChannelRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// チャンネル情報変更リクエスト
struct PatchChannelRequest {
    std::string name;
    bool archived;
    bool force;
    std::string parent;

    PatchChannelRequest() = default;
    operator Json::Value() const;
    PatchChannelRequest(const Json::Value& __value);

    Json::Value toJson() const;
    PatchChannelRequest& fromJson(const Json::Value& _json);
};

}
template <> traQApi::PatchChannelRequest Json::Value::as<traQApi::PatchChannelRequest>() const;

#endif
