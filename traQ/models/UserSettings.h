#ifndef TRAQ_UserSettings_H
#define TRAQ_UserSettings_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザー設定の情報
struct UserSettings {
    std::string id;
    bool notifyCitation;

    UserSettings() = default;
    operator Json::Value() const;
    UserSettings(const Json::Value& __value);

    Json::Value toJson() const;
    UserSettings& fromJson(const Json::Value& _json);
};

}
template <> traQApi::UserSettings Json::Value::as<traQApi::UserSettings>() const;

#endif
