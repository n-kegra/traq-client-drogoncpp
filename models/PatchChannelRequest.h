#ifndef _PatchChannelRequest_H
#define _PatchChannelRequest_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// チャンネル情報変更リクエスト
struct PatchChannelRequest {
    std::string name;
    bool archived;
    bool force;
    std::string parent;

    operator Json::Value() const {
        return this->toJson();
    }
    PatchChannelRequest(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["name"] = (name);
        _json["archived"] = (archived);
        _json["force"] = (force);
        _json["parent"] = (parent);
        return _json;
    }
    PatchChannelRequest& fromJson(const Json::Value& _json) {
        Json::Value _json;
        name = _json["name"].as<std::string>();
        archived = _json["archived"].as<bool>();
        force = _json["force"].as<bool>();
        parent = _json["parent"].as<std::string>();
        return *this;
    }
};

}

#endif
