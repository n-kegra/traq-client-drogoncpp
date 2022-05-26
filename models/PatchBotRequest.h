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

    operator Json::Value() const {
        return this->toJson();
    }
    PatchBotRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["displayName"] = (displayName);
        _json["description"] = (description);
        _json["privileged"] = (privileged);
        _json["mode"] = (mode);
        _json["endpoint"] = (endpoint);
        _json["developerId"] = (developerId);
        _json["subscribeEvents"] = Helper::toJson(subscribeEvents);
        return _json;
    }
    PatchBotRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        displayName = _json["displayName"].as<std::string>();
        description = _json["description"].as<std::string>();
        privileged = _json["privileged"].as<bool>();
        mode = _json["mode"].as<BotMode>();
        endpoint = _json["endpoint"].as<std::string>();
        developerId = _json["developerId"].as<std::string>();
        subscribeEvents = _json["subscribeEvents"].as<std::vector<std::string>>();
        return *this;
    }
};

}

#endif
