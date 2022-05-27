#ifndef _GetNotifyCitation_H
#define _GetNotifyCitation_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// メッセージ引用通知の設定情報
struct GetNotifyCitation {
    bool notifyCitation;

    GetNotifyCitation() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    GetNotifyCitation(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const {
        Json::Value _json;
        _json["notifyCitation"] = (notifyCitation);
        return _json;
    }
    GetNotifyCitation& fromJson(const Json::Value& _json) {
        notifyCitation = _json["notifyCitation"].as<bool>();
        return *this;
    }
};

}
template <> traQ::GetNotifyCitation Json::Value::as<traQ::GetNotifyCitation>() const { return traQ::GetNotifyCitation(*this); }

#endif
