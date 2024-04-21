#ifndef TRAQ_ChannelViewer_H
#define TRAQ_ChannelViewer_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ChannelViewState.h>

namespace traQApi {

// チャンネル閲覧者情報
struct ChannelViewer {
    std::string userId;
    ChannelViewState state;
    std::string updatedAt;

    ChannelViewer() = default;
    operator Json::Value() const;
    ChannelViewer(const Json::Value& __value);

    Json::Value toJson() const;
    ChannelViewer& fromJson(const Json::Value& _json);
};

}
template <> traQApi::ChannelViewer Json::Value::as<traQApi::ChannelViewer>() const;

#endif
