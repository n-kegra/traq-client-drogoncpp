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

    Json::Value toJson() const {
        switch(this->value) {
        case Value::eget_webhook:
            return Json::Value("get_webhook");
        case Value::ecreate_webhook:
            return Json::Value("create_webhook");
        case Value::eedit_webhook:
            return Json::Value("edit_webhook");
        case Value::edelete_webhook:
            return Json::Value("delete_webhook");
        case Value::eaccess_others_webhook:
            return Json::Value("access_others_webhook");
        case Value::eget_bot:
            return Json::Value("get_bot");
        case Value::ecreate_bot:
            return Json::Value("create_bot");
        case Value::eedit_bot:
            return Json::Value("edit_bot");
        case Value::edelete_bot:
            return Json::Value("delete_bot");
        case Value::eaccess_others_bot:
            return Json::Value("access_others_bot");
        case Value::ebot_action_join_channel:
            return Json::Value("bot_action_join_channel");
        case Value::ebot_action_leave_channel:
            return Json::Value("bot_action_leave_channel");
        case Value::ecreate_channel:
            return Json::Value("create_channel");
        case Value::eget_channel:
            return Json::Value("get_channel");
        case Value::eedit_channel:
            return Json::Value("edit_channel");
        case Value::edelete_channel:
            return Json::Value("delete_channel");
        case Value::echange_parent_channel:
            return Json::Value("change_parent_channel");
        case Value::eedit_channel_topic:
            return Json::Value("edit_channel_topic");
        case Value::eget_channel_star:
            return Json::Value("get_channel_star");
        case Value::eedit_channel_star:
            return Json::Value("edit_channel_star");
        case Value::eget_my_tokens:
            return Json::Value("get_my_tokens");
        case Value::erevoke_my_token:
            return Json::Value("revoke_my_token");
        case Value::eget_clients:
            return Json::Value("get_clients");
        case Value::ecreate_client:
            return Json::Value("create_client");
        case Value::eedit_my_client:
            return Json::Value("edit_my_client");
        case Value::edelete_my_client:
            return Json::Value("delete_my_client");
        case Value::emanage_others_client:
            return Json::Value("manage_others_client");
        case Value::eupload_file:
            return Json::Value("upload_file");
        case Value::edownload_file:
            return Json::Value("download_file");
        case Value::edelete_file:
            return Json::Value("delete_file");
        case Value::eget_message:
            return Json::Value("get_message");
        case Value::epost_message:
            return Json::Value("post_message");
        case Value::eedit_message:
            return Json::Value("edit_message");
        case Value::edelete_message:
            return Json::Value("delete_message");
        case Value::ereport_message:
            return Json::Value("report_message");
        case Value::eget_message_reports:
            return Json::Value("get_message_reports");
        case Value::ecreate_message_pin:
            return Json::Value("create_message_pin");
        case Value::edelete_message_pin:
            return Json::Value("delete_message_pin");
        case Value::eget_channel_subscription:
            return Json::Value("get_channel_subscription");
        case Value::eedit_channel_subscription:
            return Json::Value("edit_channel_subscription");
        case Value::econnect_notification_stream:
            return Json::Value("connect_notification_stream");
        case Value::eregister_fcm_device:
            return Json::Value("register_fcm_device");
        case Value::eget_stamp:
            return Json::Value("get_stamp");
        case Value::ecreate_stamp:
            return Json::Value("create_stamp");
        case Value::eedit_stamp:
            return Json::Value("edit_stamp");
        case Value::eedit_stamp_created_by_others:
            return Json::Value("edit_stamp_created_by_others");
        case Value::edelete_stamp:
            return Json::Value("delete_stamp");
        case Value::eadd_message_stamp:
            return Json::Value("add_message_stamp");
        case Value::eremove_message_stamp:
            return Json::Value("remove_message_stamp");
        case Value::eget_my_stamp_history:
            return Json::Value("get_my_stamp_history");
        case Value::eget_stamp_palette:
            return Json::Value("get_stamp_palette");
        case Value::ecreate_stamp_palette:
            return Json::Value("create_stamp_palette");
        case Value::eedit_stamp_palette:
            return Json::Value("edit_stamp_palette");
        case Value::edelete_stamp_palette:
            return Json::Value("delete_stamp_palette");
        case Value::eget_user:
            return Json::Value("get_user");
        case Value::eregister_user:
            return Json::Value("register_user");
        case Value::eget_me:
            return Json::Value("get_me");
        case Value::eedit_me:
            return Json::Value("edit_me");
        case Value::echange_my_icon:
            return Json::Value("change_my_icon");
        case Value::echange_my_password:
            return Json::Value("change_my_password");
        case Value::eedit_other_users:
            return Json::Value("edit_other_users");
        case Value::eget_user_qr_code:
            return Json::Value("get_user_qr_code");
        case Value::eget_user_tag:
            return Json::Value("get_user_tag");
        case Value::eedit_user_tag:
            return Json::Value("edit_user_tag");
        case Value::eget_user_group:
            return Json::Value("get_user_group");
        case Value::ecreate_user_group:
            return Json::Value("create_user_group");
        case Value::ecreate_special_user_group:
            return Json::Value("create_special_user_group");
        case Value::eedit_user_group:
            return Json::Value("edit_user_group");
        case Value::edelete_user_group:
            return Json::Value("delete_user_group");
        case Value::eedit_others_user_group:
            return Json::Value("edit_others_user_group");
        case Value::eweb_rtc:
            return Json::Value("web_rtc");
        case Value::eget_my_sessions:
            return Json::Value("get_my_sessions");
        case Value::edelete_my_sessions:
            return Json::Value("delete_my_sessions");
        case Value::eget_my_external_account:
            return Json::Value("get_my_external_account");
        case Value::eedit_my_external_account:
            return Json::Value("edit_my_external_account");
        case Value::eget_unread:
            return Json::Value("get_unread");
        case Value::edelete_unread:
            return Json::Value("delete_unread");
        case Value::eget_clip_folder:
            return Json::Value("get_clip_folder");
        case Value::ecreate_clip_folder:
            return Json::Value("create_clip_folder");
        case Value::eedit_clip_folder:
            return Json::Value("edit_clip_folder");
        case Value::edelete_clip_folder:
            return Json::Value("delete_clip_folder");
        case Value::Unknown:
            return Json::Value(Json::nullValue);
        }
    }
    UserPermission& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "get_webhook") {
            this->value = Value::eget_webhook;
        } else
        if (s == "create_webhook") {
            this->value = Value::ecreate_webhook;
        } else
        if (s == "edit_webhook") {
            this->value = Value::eedit_webhook;
        } else
        if (s == "delete_webhook") {
            this->value = Value::edelete_webhook;
        } else
        if (s == "access_others_webhook") {
            this->value = Value::eaccess_others_webhook;
        } else
        if (s == "get_bot") {
            this->value = Value::eget_bot;
        } else
        if (s == "create_bot") {
            this->value = Value::ecreate_bot;
        } else
        if (s == "edit_bot") {
            this->value = Value::eedit_bot;
        } else
        if (s == "delete_bot") {
            this->value = Value::edelete_bot;
        } else
        if (s == "access_others_bot") {
            this->value = Value::eaccess_others_bot;
        } else
        if (s == "bot_action_join_channel") {
            this->value = Value::ebot_action_join_channel;
        } else
        if (s == "bot_action_leave_channel") {
            this->value = Value::ebot_action_leave_channel;
        } else
        if (s == "create_channel") {
            this->value = Value::ecreate_channel;
        } else
        if (s == "get_channel") {
            this->value = Value::eget_channel;
        } else
        if (s == "edit_channel") {
            this->value = Value::eedit_channel;
        } else
        if (s == "delete_channel") {
            this->value = Value::edelete_channel;
        } else
        if (s == "change_parent_channel") {
            this->value = Value::echange_parent_channel;
        } else
        if (s == "edit_channel_topic") {
            this->value = Value::eedit_channel_topic;
        } else
        if (s == "get_channel_star") {
            this->value = Value::eget_channel_star;
        } else
        if (s == "edit_channel_star") {
            this->value = Value::eedit_channel_star;
        } else
        if (s == "get_my_tokens") {
            this->value = Value::eget_my_tokens;
        } else
        if (s == "revoke_my_token") {
            this->value = Value::erevoke_my_token;
        } else
        if (s == "get_clients") {
            this->value = Value::eget_clients;
        } else
        if (s == "create_client") {
            this->value = Value::ecreate_client;
        } else
        if (s == "edit_my_client") {
            this->value = Value::eedit_my_client;
        } else
        if (s == "delete_my_client") {
            this->value = Value::edelete_my_client;
        } else
        if (s == "manage_others_client") {
            this->value = Value::emanage_others_client;
        } else
        if (s == "upload_file") {
            this->value = Value::eupload_file;
        } else
        if (s == "download_file") {
            this->value = Value::edownload_file;
        } else
        if (s == "delete_file") {
            this->value = Value::edelete_file;
        } else
        if (s == "get_message") {
            this->value = Value::eget_message;
        } else
        if (s == "post_message") {
            this->value = Value::epost_message;
        } else
        if (s == "edit_message") {
            this->value = Value::eedit_message;
        } else
        if (s == "delete_message") {
            this->value = Value::edelete_message;
        } else
        if (s == "report_message") {
            this->value = Value::ereport_message;
        } else
        if (s == "get_message_reports") {
            this->value = Value::eget_message_reports;
        } else
        if (s == "create_message_pin") {
            this->value = Value::ecreate_message_pin;
        } else
        if (s == "delete_message_pin") {
            this->value = Value::edelete_message_pin;
        } else
        if (s == "get_channel_subscription") {
            this->value = Value::eget_channel_subscription;
        } else
        if (s == "edit_channel_subscription") {
            this->value = Value::eedit_channel_subscription;
        } else
        if (s == "connect_notification_stream") {
            this->value = Value::econnect_notification_stream;
        } else
        if (s == "register_fcm_device") {
            this->value = Value::eregister_fcm_device;
        } else
        if (s == "get_stamp") {
            this->value = Value::eget_stamp;
        } else
        if (s == "create_stamp") {
            this->value = Value::ecreate_stamp;
        } else
        if (s == "edit_stamp") {
            this->value = Value::eedit_stamp;
        } else
        if (s == "edit_stamp_created_by_others") {
            this->value = Value::eedit_stamp_created_by_others;
        } else
        if (s == "delete_stamp") {
            this->value = Value::edelete_stamp;
        } else
        if (s == "add_message_stamp") {
            this->value = Value::eadd_message_stamp;
        } else
        if (s == "remove_message_stamp") {
            this->value = Value::eremove_message_stamp;
        } else
        if (s == "get_my_stamp_history") {
            this->value = Value::eget_my_stamp_history;
        } else
        if (s == "get_stamp_palette") {
            this->value = Value::eget_stamp_palette;
        } else
        if (s == "create_stamp_palette") {
            this->value = Value::ecreate_stamp_palette;
        } else
        if (s == "edit_stamp_palette") {
            this->value = Value::eedit_stamp_palette;
        } else
        if (s == "delete_stamp_palette") {
            this->value = Value::edelete_stamp_palette;
        } else
        if (s == "get_user") {
            this->value = Value::eget_user;
        } else
        if (s == "register_user") {
            this->value = Value::eregister_user;
        } else
        if (s == "get_me") {
            this->value = Value::eget_me;
        } else
        if (s == "edit_me") {
            this->value = Value::eedit_me;
        } else
        if (s == "change_my_icon") {
            this->value = Value::echange_my_icon;
        } else
        if (s == "change_my_password") {
            this->value = Value::echange_my_password;
        } else
        if (s == "edit_other_users") {
            this->value = Value::eedit_other_users;
        } else
        if (s == "get_user_qr_code") {
            this->value = Value::eget_user_qr_code;
        } else
        if (s == "get_user_tag") {
            this->value = Value::eget_user_tag;
        } else
        if (s == "edit_user_tag") {
            this->value = Value::eedit_user_tag;
        } else
        if (s == "get_user_group") {
            this->value = Value::eget_user_group;
        } else
        if (s == "create_user_group") {
            this->value = Value::ecreate_user_group;
        } else
        if (s == "create_special_user_group") {
            this->value = Value::ecreate_special_user_group;
        } else
        if (s == "edit_user_group") {
            this->value = Value::eedit_user_group;
        } else
        if (s == "delete_user_group") {
            this->value = Value::edelete_user_group;
        } else
        if (s == "edit_others_user_group") {
            this->value = Value::eedit_others_user_group;
        } else
        if (s == "web_rtc") {
            this->value = Value::eweb_rtc;
        } else
        if (s == "get_my_sessions") {
            this->value = Value::eget_my_sessions;
        } else
        if (s == "delete_my_sessions") {
            this->value = Value::edelete_my_sessions;
        } else
        if (s == "get_my_external_account") {
            this->value = Value::eget_my_external_account;
        } else
        if (s == "edit_my_external_account") {
            this->value = Value::eedit_my_external_account;
        } else
        if (s == "get_unread") {
            this->value = Value::eget_unread;
        } else
        if (s == "delete_unread") {
            this->value = Value::edelete_unread;
        } else
        if (s == "get_clip_folder") {
            this->value = Value::eget_clip_folder;
        } else
        if (s == "create_clip_folder") {
            this->value = Value::ecreate_clip_folder;
        } else
        if (s == "edit_clip_folder") {
            this->value = Value::eedit_clip_folder;
        } else
        if (s == "delete_clip_folder") {
            this->value = Value::edelete_clip_folder;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> traQ::UserPermission Json::Value::as<traQ::UserPermission>() const { return traQ::UserPermission(*this); }

#endif
