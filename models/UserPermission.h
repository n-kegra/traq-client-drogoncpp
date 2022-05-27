#ifndef _UserPermission_H
#define _UserPermission_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"


namespace traQ {

// ユーザー権限
struct UserPermission {
    enum class Value {
        eget_webhook,
        ecreate_webhook,
        eedit_webhook,
        edelete_webhook,
        eaccess_others_webhook,
        eget_bot,
        ecreate_bot,
        eedit_bot,
        edelete_bot,
        eaccess_others_bot,
        ebot_action_join_channel,
        ebot_action_leave_channel,
        ecreate_channel,
        eget_channel,
        eedit_channel,
        edelete_channel,
        echange_parent_channel,
        eedit_channel_topic,
        eget_channel_star,
        eedit_channel_star,
        eget_my_tokens,
        erevoke_my_token,
        eget_clients,
        ecreate_client,
        eedit_my_client,
        edelete_my_client,
        emanage_others_client,
        eupload_file,
        edownload_file,
        edelete_file,
        eget_message,
        epost_message,
        eedit_message,
        edelete_message,
        ereport_message,
        eget_message_reports,
        ecreate_message_pin,
        edelete_message_pin,
        eget_channel_subscription,
        eedit_channel_subscription,
        econnect_notification_stream,
        eregister_fcm_device,
        eget_stamp,
        ecreate_stamp,
        eedit_stamp,
        eedit_stamp_created_by_others,
        edelete_stamp,
        eadd_message_stamp,
        eremove_message_stamp,
        eget_my_stamp_history,
        eget_stamp_palette,
        ecreate_stamp_palette,
        eedit_stamp_palette,
        edelete_stamp_palette,
        eget_user,
        eregister_user,
        eget_me,
        eedit_me,
        echange_my_icon,
        echange_my_password,
        eedit_other_users,
        eget_user_qr_code,
        eget_user_tag,
        eedit_user_tag,
        eget_user_group,
        ecreate_user_group,
        ecreate_special_user_group,
        eedit_user_group,
        edelete_user_group,
        eedit_others_user_group,
        eweb_rtc,
        eget_my_sessions,
        edelete_my_sessions,
        eget_my_external_account,
        eedit_my_external_account,
        eget_unread,
        edelete_unread,
        eget_clip_folder,
        ecreate_clip_folder,
        eedit_clip_folder,
        edelete_clip_folder,
        Unknown,
    } value;
    UserPermission() { value = Value::Unknown; };
    operator Json::Value() const {
        return this->toJson();
    }
    UserPermission(const Json::Value& __value) {
        this->fromJson(__value);
    }
    UserPermission(const Value __value) : value(__value) {}

    Json::Value toJson() const;
    UserPermission& fromJson(const Json::Value& _json);
};

}
template <> traQ::UserPermission Json::Value::as<traQ::UserPermission>() const;

#endif
