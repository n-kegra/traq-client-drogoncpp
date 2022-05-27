#ifndef _PatchBotRequest_H
#define _PatchBotRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/BotMode.h"
#include <vector>

namespace traQ {

// BOT情報変更リクエスト
struct PatchBotRequest {
    std::string displayName;
    std::string description;
    bool privileged;
    BotMode mode;
    std::string endpoint;
    std::string developerId;
    std::vector<std::string> subscribeEvents;

    PatchBotRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PatchBotRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    PatchBotRequest& fromJson(const Json::Value& _json);
};

}
template <> traQ::PatchBotRequest Json::Value::as<traQ::PatchBotRequest>() const;

#endif
