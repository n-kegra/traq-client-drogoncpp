#ifndef _UserSettings_H
#define _UserSettings_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザー設定の情報
struct UserSettings {
    std::string id;
    bool notifyCitation;

    UserSettings() = default;
    operator Json::Value() const {
        return this->toJson();
    }
    UserSettings(const Json::Value& __value) {
        this->fromJson(__value);
    }

    Json::Value toJson() const;
    UserSettings& fromJson(const Json::Value& _json);
};

}
template <> traQ::UserSettings Json::Value::as<traQ::UserSettings>() const;

#endif
