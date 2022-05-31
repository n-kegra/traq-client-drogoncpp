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
        case Value::eGet_webhook:
            return Json::Value("get_webhook");
        case Value::eCreate_webhook:
            return Json::Value("create_webhook");
        case Value::eEdit_webhook:
            return Json::Value("edit_webhook");
        case Value::eDelete_webhook:
            return Json::Value("delete_webhook");
        case Value::eAccess_others_webhook:
            return Json::Value("access_others_webhook");
        case Value::eGet_bot:
            return Json::Value("get_bot");
        case Value::eCreate_bot:
            return Json::Value("create_bot");
        case Value::eEdit_bot:
            return Json::Value("edit_bot");
        case Value::eDelete_bot:
            return Json::Value("delete_bot");
        case Value::eAccess_others_bot:
            return Json::Value("access_others_bot");
        case Value::eBot_action_join_channel:
            return Json::Value("bot_action_join_channel");
        case Value::eBot_action_leave_channel:
            return Json::Value("bot_action_leave_channel");
        case Value::eCreate_channel:
            return Json::Value("create_channel");
        case Value::eGet_channel:
            return Json::Value("get_channel");
        case Value::eEdit_channel:
            return Json::Value("edit_channel");
        case Value::eDelete_channel:
            return Json::Value("delete_channel");
        case Value::eChange_parent_channel:
            return Json::Value("change_parent_channel");
        case Value::eEdit_channel_topic:
            return Json::Value("edit_channel_topic");
        case Value::eGet_channel_star:
            return Json::Value("get_channel_star");
        case Value::eEdit_channel_star:
            return Json::Value("edit_channel_star");
        case Value::eGet_my_tokens:
            return Json::Value("get_my_tokens");
        case Value::eRevoke_my_token:
            return Json::Value("revoke_my_token");
        case Value::eGet_clients:
            return Json::Value("get_clients");
        case Value::eCreate_client:
            return Json::Value("create_client");
        case Value::eEdit_my_client:
            return Json::Value("edit_my_client");
        case Value::eDelete_my_client:
            return Json::Value("delete_my_client");
        case Value::eManage_others_client:
            return Json::Value("manage_others_client");
        case Value::eUpload_file:
            return Json::Value("upload_file");
        case Value::eDownload_file:
            return Json::Value("download_file");
        case Value::eDelete_file:
            return Json::Value("delete_file");
        case Value::eGet_message:
            return Json::Value("get_message");
        case Value::ePost_message:
            return Json::Value("post_message");
        case Value::eEdit_message:
            return Json::Value("edit_message");
        case Value::eDelete_message:
            return Json::Value("delete_message");
        case Value::eReport_message:
            return Json::Value("report_message");
        case Value::eGet_message_reports:
            return Json::Value("get_message_reports");
        case Value::eCreate_message_pin:
            return Json::Value("create_message_pin");
        case Value::eDelete_message_pin:
            return Json::Value("delete_message_pin");
        case Value::eGet_channel_subscription:
            return Json::Value("get_channel_subscription");
        case Value::eEdit_channel_subscription:
            return Json::Value("edit_channel_subscription");
        case Value::eConnect_notification_stream:
            return Json::Value("connect_notification_stream");
        case Value::eRegister_fcm_device:
            return Json::Value("register_fcm_device");
        case Value::eGet_stamp:
            return Json::Value("get_stamp");
        case Value::eCreate_stamp:
            return Json::Value("create_stamp");
        case Value::eEdit_stamp:
            return Json::Value("edit_stamp");
        case Value::eEdit_stamp_created_by_others:
            return Json::Value("edit_stamp_created_by_others");
        case Value::eDelete_stamp:
            return Json::Value("delete_stamp");
        case Value::eAdd_message_stamp:
            return Json::Value("add_message_stamp");
        case Value::eRemove_message_stamp:
            return Json::Value("remove_message_stamp");
        case Value::eGet_my_stamp_history:
            return Json::Value("get_my_stamp_history");
        case Value::eGet_stamp_palette:
            return Json::Value("get_stamp_palette");
        case Value::eCreate_stamp_palette:
            return Json::Value("create_stamp_palette");
        case Value::eEdit_stamp_palette:
            return Json::Value("edit_stamp_palette");
        case Value::eDelete_stamp_palette:
            return Json::Value("delete_stamp_palette");
        case Value::eGet_user:
            return Json::Value("get_user");
        case Value::eRegister_user:
            return Json::Value("register_user");
        case Value::eGet_me:
            return Json::Value("get_me");
        case Value::eEdit_me:
            return Json::Value("edit_me");
        case Value::eChange_my_icon:
            return Json::Value("change_my_icon");
        case Value::eChange_my_password:
            return Json::Value("change_my_password");
        case Value::eEdit_other_users:
            return Json::Value("edit_other_users");
        case Value::eGet_user_qr_code:
            return Json::Value("get_user_qr_code");
        case Value::eGet_user_tag:
            return Json::Value("get_user_tag");
        case Value::eEdit_user_tag:
            return Json::Value("edit_user_tag");
        case Value::eGet_user_group:
            return Json::Value("get_user_group");
        case Value::eCreate_user_group:
            return Json::Value("create_user_group");
        case Value::eCreate_special_user_group:
            return Json::Value("create_special_user_group");
        case Value::eEdit_user_group:
            return Json::Value("edit_user_group");
        case Value::eDelete_user_group:
            return Json::Value("delete_user_group");
        case Value::eEdit_others_user_group:
            return Json::Value("edit_others_user_group");
        case Value::eWeb_rtc:
            return Json::Value("web_rtc");
        case Value::eGet_my_sessions:
            return Json::Value("get_my_sessions");
        case Value::eDelete_my_sessions:
            return Json::Value("delete_my_sessions");
        case Value::eGet_my_external_account:
            return Json::Value("get_my_external_account");
        case Value::eEdit_my_external_account:
            return Json::Value("edit_my_external_account");
        case Value::eGet_unread:
            return Json::Value("get_unread");
        case Value::eDelete_unread:
            return Json::Value("delete_unread");
        case Value::eGet_clip_folder:
            return Json::Value("get_clip_folder");
        case Value::eCreate_clip_folder:
            return Json::Value("create_clip_folder");
        case Value::eEdit_clip_folder:
            return Json::Value("edit_clip_folder");
        case Value::eDelete_clip_folder:
            return Json::Value("delete_clip_folder");
        default:
            return Json::Value(Json::nullValue);
        }
    }
    UserPermission& fromJson(const Json::Value& _json) {
        std::string s = _json.asString();
        if (s == "get_webhook") {
            this->value = Value::eGet_webhook;
        } else
        if (s == "create_webhook") {
            this->value = Value::eCreate_webhook;
        } else
        if (s == "edit_webhook") {
            this->value = Value::eEdit_webhook;
        } else
        if (s == "delete_webhook") {
            this->value = Value::eDelete_webhook;
        } else
        if (s == "access_others_webhook") {
            this->value = Value::eAccess_others_webhook;
        } else
        if (s == "get_bot") {
            this->value = Value::eGet_bot;
        } else
        if (s == "create_bot") {
            this->value = Value::eCreate_bot;
        } else
        if (s == "edit_bot") {
            this->value = Value::eEdit_bot;
        } else
        if (s == "delete_bot") {
            this->value = Value::eDelete_bot;
        } else
        if (s == "access_others_bot") {
            this->value = Value::eAccess_others_bot;
        } else
        if (s == "bot_action_join_channel") {
            this->value = Value::eBot_action_join_channel;
        } else
        if (s == "bot_action_leave_channel") {
            this->value = Value::eBot_action_leave_channel;
        } else
        if (s == "create_channel") {
            this->value = Value::eCreate_channel;
        } else
        if (s == "get_channel") {
            this->value = Value::eGet_channel;
        } else
        if (s == "edit_channel") {
            this->value = Value::eEdit_channel;
        } else
        if (s == "delete_channel") {
            this->value = Value::eDelete_channel;
        } else
        if (s == "change_parent_channel") {
            this->value = Value::eChange_parent_channel;
        } else
        if (s == "edit_channel_topic") {
            this->value = Value::eEdit_channel_topic;
        } else
        if (s == "get_channel_star") {
            this->value = Value::eGet_channel_star;
        } else
        if (s == "edit_channel_star") {
            this->value = Value::eEdit_channel_star;
        } else
        if (s == "get_my_tokens") {
            this->value = Value::eGet_my_tokens;
        } else
        if (s == "revoke_my_token") {
            this->value = Value::eRevoke_my_token;
        } else
        if (s == "get_clients") {
            this->value = Value::eGet_clients;
        } else
        if (s == "create_client") {
            this->value = Value::eCreate_client;
        } else
        if (s == "edit_my_client") {
            this->value = Value::eEdit_my_client;
        } else
        if (s == "delete_my_client") {
            this->value = Value::eDelete_my_client;
        } else
        if (s == "manage_others_client") {
            this->value = Value::eManage_others_client;
        } else
        if (s == "upload_file") {
            this->value = Value::eUpload_file;
        } else
        if (s == "download_file") {
            this->value = Value::eDownload_file;
        } else
        if (s == "delete_file") {
            this->value = Value::eDelete_file;
        } else
        if (s == "get_message") {
            this->value = Value::eGet_message;
        } else
        if (s == "post_message") {
            this->value = Value::ePost_message;
        } else
        if (s == "edit_message") {
            this->value = Value::eEdit_message;
        } else
        if (s == "delete_message") {
            this->value = Value::eDelete_message;
        } else
        if (s == "report_message") {
            this->value = Value::eReport_message;
        } else
        if (s == "get_message_reports") {
            this->value = Value::eGet_message_reports;
        } else
        if (s == "create_message_pin") {
            this->value = Value::eCreate_message_pin;
        } else
        if (s == "delete_message_pin") {
            this->value = Value::eDelete_message_pin;
        } else
        if (s == "get_channel_subscription") {
            this->value = Value::eGet_channel_subscription;
        } else
        if (s == "edit_channel_subscription") {
            this->value = Value::eEdit_channel_subscription;
        } else
        if (s == "connect_notification_stream") {
            this->value = Value::eConnect_notification_stream;
        } else
        if (s == "register_fcm_device") {
            this->value = Value::eRegister_fcm_device;
        } else
        if (s == "get_stamp") {
            this->value = Value::eGet_stamp;
        } else
        if (s == "create_stamp") {
            this->value = Value::eCreate_stamp;
        } else
        if (s == "edit_stamp") {
            this->value = Value::eEdit_stamp;
        } else
        if (s == "edit_stamp_created_by_others") {
            this->value = Value::eEdit_stamp_created_by_others;
        } else
        if (s == "delete_stamp") {
            this->value = Value::eDelete_stamp;
        } else
        if (s == "add_message_stamp") {
            this->value = Value::eAdd_message_stamp;
        } else
        if (s == "remove_message_stamp") {
            this->value = Value::eRemove_message_stamp;
        } else
        if (s == "get_my_stamp_history") {
            this->value = Value::eGet_my_stamp_history;
        } else
        if (s == "get_stamp_palette") {
            this->value = Value::eGet_stamp_palette;
        } else
        if (s == "create_stamp_palette") {
            this->value = Value::eCreate_stamp_palette;
        } else
        if (s == "edit_stamp_palette") {
            this->value = Value::eEdit_stamp_palette;
        } else
        if (s == "delete_stamp_palette") {
            this->value = Value::eDelete_stamp_palette;
        } else
        if (s == "get_user") {
            this->value = Value::eGet_user;
        } else
        if (s == "register_user") {
            this->value = Value::eRegister_user;
        } else
        if (s == "get_me") {
            this->value = Value::eGet_me;
        } else
        if (s == "edit_me") {
            this->value = Value::eEdit_me;
        } else
        if (s == "change_my_icon") {
            this->value = Value::eChange_my_icon;
        } else
        if (s == "change_my_password") {
            this->value = Value::eChange_my_password;
        } else
        if (s == "edit_other_users") {
            this->value = Value::eEdit_other_users;
        } else
        if (s == "get_user_qr_code") {
            this->value = Value::eGet_user_qr_code;
        } else
        if (s == "get_user_tag") {
            this->value = Value::eGet_user_tag;
        } else
        if (s == "edit_user_tag") {
            this->value = Value::eEdit_user_tag;
        } else
        if (s == "get_user_group") {
            this->value = Value::eGet_user_group;
        } else
        if (s == "create_user_group") {
            this->value = Value::eCreate_user_group;
        } else
        if (s == "create_special_user_group") {
            this->value = Value::eCreate_special_user_group;
        } else
        if (s == "edit_user_group") {
            this->value = Value::eEdit_user_group;
        } else
        if (s == "delete_user_group") {
            this->value = Value::eDelete_user_group;
        } else
        if (s == "edit_others_user_group") {
            this->value = Value::eEdit_others_user_group;
        } else
        if (s == "web_rtc") {
            this->value = Value::eWeb_rtc;
        } else
        if (s == "get_my_sessions") {
            this->value = Value::eGet_my_sessions;
        } else
        if (s == "delete_my_sessions") {
            this->value = Value::eDelete_my_sessions;
        } else
        if (s == "get_my_external_account") {
            this->value = Value::eGet_my_external_account;
        } else
        if (s == "edit_my_external_account") {
            this->value = Value::eEdit_my_external_account;
        } else
        if (s == "get_unread") {
            this->value = Value::eGet_unread;
        } else
        if (s == "delete_unread") {
            this->value = Value::eDelete_unread;
        } else
        if (s == "get_clip_folder") {
            this->value = Value::eGet_clip_folder;
        } else
        if (s == "create_clip_folder") {
            this->value = Value::eCreate_clip_folder;
        } else
        if (s == "edit_clip_folder") {
            this->value = Value::eEdit_clip_folder;
        } else
        if (s == "delete_clip_folder") {
            this->value = Value::eDelete_clip_folder;
        } else
        {
            this->value = Value::Unknown;
        }
        return (*this);
    }
};

}
template <> inline traQApi::UserPermission Json::Value::as<traQApi::UserPermission>() const {
    return traQApi::UserPermission(*this);
};

#endif
