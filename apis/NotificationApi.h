#ifndef _NotificationApi_H
#define _NotificationApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/MyChannelViewState.h"
#include "../models/PatchChannelSubscribersRequest.h"
#include "../models/PostMyFCMDeviceRequest.h"
#include "../models/PutChannelSubscribeLevelRequest.h"
#include "../models/PutChannelSubscribersRequest.h"
#include "../models/UnreadChannel.h"
#include "../models/UserSubscribeState.h"


namespace traQ {

class NotificationApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    NotificationApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    NotificationApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    NotificationApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    NotificationApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // チャンネルの通知購読者を編集
    auto editChannelSubscribers(
        const std::string& _channelId, 
        const std::optional<PatchChannelSubscribersRequest>& _patchChannelSubscribersRequest
    );


    // チャンネルの通知購読者のリストを取得
    auto getChannelSubscribers(
        const std::string& _channelId
    );


    // 自分のチャンネル購読状態を取得
    auto getMyChannelSubscriptions(
    );


    // 未読チャンネルを取得
    auto getMyUnreadChannels(
    );


    // 自身のチャンネル閲覧状態一覧を取得
    auto getMyViewStates(
    );


    // チャンネルを既読にする
    auto readChannel(
        const std::string& _channelId
    );


    // FCMデバイスを登録
    auto registerFCMDevice(
        const std::optional<PostMyFCMDeviceRequest>& _postMyFCMDeviceRequest
    );


    // チャンネル購読レベルを設定
    auto setChannelSubscribeLevel(
        const std::string& _channelId, 
        const std::optional<PutChannelSubscribeLevelRequest>& _putChannelSubscribeLevelRequest
    );


    // チャンネルの通知購読者を設定
    auto setChannelSubscribers(
        const std::string& _channelId, 
        const std::optional<PutChannelSubscribersRequest>& _putChannelSubscribersRequest
    );


    // WebSocket通知ストリームに接続します
    auto ws(
    );


};

}

#endif
