#ifndef TRAQ_PostBotRequest_H
#define TRAQ_PostBotRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/BotMode.h>

namespace traQApi {

// BOT作成リクエスト
struct PostBotRequest {
    std::string name;
    std::string displayName;
    std::string description;
    BotMode mode;
    std::string endpoint;

    PostBotRequest() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    PostBotRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["displayName"] = (displayName);
        _json["description"] = (description);
        _json["mode"] = (mode);
        _json["endpoint"] = (endpoint);
        return _json;
    }
    PostBotRequest& fromJson(const Json::Value& _json) {
        name = _json["name"].as<std::string>();
        displayName = _json["displayName"].as<std::string>();
        description = _json["description"].as<std::string>();
        mode = _json["mode"].as<BotMode>();
        endpoint = _json["endpoint"].as<std::string>();
        return *this;
    }
};

}
template <> inline traQApi::PostBotRequest Json::Value::as<traQApi::PostBotRequest>() const {
    return traQApi::PostBotRequest(*this);
};

#endif
