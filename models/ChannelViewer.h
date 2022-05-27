#ifndef _ChannelViewer_H
#define _ChannelViewer_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ChannelViewState.h"

namespace traQ {

// チャンネル閲覧者情報
struct ChannelViewer {
    std::string userId;
    ChannelViewState state;
    std::string updatedAt;

    ChannelViewer() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    ChannelViewer(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    ChannelViewer& fromJson(const Json::Value& _json);
};

}
template <> traQ::ChannelViewer Json::Value::as<traQ::ChannelViewer>() const;

#endif
