#ifndef TRAQ_NotificationApi_H
#define TRAQ_NotificationApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/MyChannelViewState.h>
#include <traQ/models/PatchChannelSubscribersRequest.h>
#include <traQ/models/PostMyFCMDeviceRequest.h>
#include <traQ/models/PutChannelSubscribeLevelRequest.h>
#include <traQ/models/PutChannelSubscribersRequest.h>
#include <traQ/models/UnreadChannel.h>
#include <traQ/models/UserSubscribeState.h>


namespace traQApi {

class NotificationApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    NotificationApi(std::string _baseurl_host, std::string _baseurl_path);
    
    NotificationApi& setBearerToken(std::string _token);
    NotificationApi& setBasicAuth(std::string _username, std::string _password);
    NotificationApi& setApikey(std::string _apikey);


    // チャンネルの通知購読者を編集
    void
    editChannelSubscribers(
        const std::string& _channelId, 
        const std::optional<PatchChannelSubscribersRequest>& _patchChannelSubscribersRequest
    );

    // チャンネルの通知購読者のリストを取得
    std::vector<std::string>
    getChannelSubscribers(
        const std::string& _channelId
    );

    // 自分のチャンネル購読状態を取得
    std::vector<UserSubscribeState>
    getMyChannelSubscriptions(
    );

    // 未読チャンネルを取得
    std::vector<UnreadChannel>
    getMyUnreadChannels(
    );

    // 自身のチャンネル閲覧状態一覧を取得
    std::vector<MyChannelViewState>
    getMyViewStates(
    );

    // チャンネルを既読にする
    void
    readChannel(
        const std::string& _channelId
    );

    // FCMデバイスを登録
    void
    registerFCMDevice(
        const std::optional<PostMyFCMDeviceRequest>& _postMyFCMDeviceRequest
    );

    // チャンネル購読レベルを設定
    void
    setChannelSubscribeLevel(
        const std::string& _channelId, 
        const std::optional<PutChannelSubscribeLevelRequest>& _putChannelSubscribeLevelRequest
    );

    // チャンネルの通知購読者を設定
    void
    setChannelSubscribers(
        const std::string& _channelId, 
        const std::optional<PutChannelSubscribersRequest>& _putChannelSubscribersRequest
    );

    // WebSocket通知ストリームに接続します
    void
    ws(
    );

};

}

#endif
