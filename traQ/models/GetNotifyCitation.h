#ifndef TRAQ_GetNotifyCitation_H
#define TRAQ_GetNotifyCitation_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// メッセージ引用通知の設定情報
struct GetNotifyCitation {
    bool notifyCitation;

    GetNotifyCitation() = default;
    operator Json::Value() const;
    GetNotifyCitation(const Json::Value& __value);

    Json::Value toJson() const;
    GetNotifyCitation& fromJson(const Json::Value& _json);
};

}
template <> traQApi::GetNotifyCitation Json::Value::as<traQApi::GetNotifyCitation>() const;

#endif
