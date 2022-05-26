#ifndef _DMChannel_H
#define _DMChannel_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ダイレクトメッセージチャンネル
struct DMChannel {
    std::string id;
    std::string userId;

    operator Json::Value() const {
        return this->toJson();
    }
    DMChannel(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["id"] = (id);
        _json["userId"] = (userId);
        return _json;
    }
    DMChannel& fromJson(const Json::Value& _json) {
        Json::Value _json;
        id = _json["id"].as<std::string>();
        userId = _json["userId"].as<std::string>();
        return *this;
    }
};

}

#endif
