#ifndef TRAQ_UserPermission_H
#define TRAQ_UserPermission_H

#include <drogon/drogon.h>
#include <json/json.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>


namespace traQApi {

// ユーザー権限
struct UserPermission {
    enum class Value {
        eGet_webhook,
        eCreate_webhook,
        eEdit_webhook,
        eDelete_webhook,
        eAccess_others_webhook,
        eGet_bot,
        eCreate_bot,
        eEdit_bot,
        eDelete_bot,
        eAccess_others_bot,
        eBot_action_join_channel,
        eBot_action_leave_channel,
        eCreate_channel,
        eGet_channel,
        eEdit_channel,
        eDelete_channel,
        eChange_parent_channel,
        eEdit_channel_topic,
        eGet_channel_star,
        eEdit_channel_star,
        eGet_my_tokens,
        eRevoke_my_token,
        eGet_clients,
        eCreate_client,
        eEdit_my_client,
        eDelete_my_client,
        eManage_others_client,
        eUpload_file,
        eDownload_file,
        eDelete_file,
        eGet_message,
        ePost_message,
        eEdit_message,
        eDelete_message,
        eReport_message,
        eGet_message_reports,
        eCreate_message_pin,
        eDelete_message_pin,
        eGet_channel_subscription,
        eEdit_channel_subscription,
        eConnect_notification_stream,
        eRegister_fcm_device,
        eGet_stamp,
        eCreate_stamp,
        eEdit_stamp,
        eEdit_stamp_created_by_others,
        eDelete_stamp,
        eAdd_message_stamp,
        eRemove_message_stamp,
        eGet_my_stamp_history,
        eGet_stamp_palette,
        eCreate_stamp_palette,
        eEdit_stamp_palette,
        eDelete_stamp_palette,
        eGet_user,
        eRegister_user,
        eGet_me,
        eEdit_me,
        eChange_my_icon,
        eChange_my_password,
        eEdit_other_users,
        eGet_user_qr_code,
        eGet_user_tag,
        eEdit_user_tag,
        eGet_user_group,
        eCreate_user_group,
        eCreate_special_user_group,
        eEdit_user_group,
        eDelete_user_group,
        eEdit_others_user_group,
        eWeb_rtc,
        eGet_my_sessions,
        eDelete_my_sessions,
        eGet_my_external_account,
        eEdit_my_external_account,
        eGet_unread,
        eDelete_unread,
        eGet_clip_folder,
        eCreate_clip_folder,
        eEdit_clip_folder,
        eDelete_clip_folder,
        Unknown,
    } value;
    UserPermission();
    operator Json::Value() const;
    UserPermission(const Json::Value& __value);
    UserPermission(const Value __value);

    Json::Value toJson() const;
    UserPermission& fromJson(const Json::Value& _json);
};

}
template <> traQApi::UserPermission Json::Value::as<traQApi::UserPermission>() const;

#endif
