#ifndef TRAQ_PatchBotRequest_H
#define TRAQ_PatchBotRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/BotMode.h>
#include <vector>

namespace traQApi {

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
template <> traQApi::PatchBotRequest Json::Value::as<traQApi::PatchBotRequest>() const;

#endif
