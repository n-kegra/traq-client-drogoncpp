#ifndef _ChannelApi_H
#define _ChannelApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/BotUser.h"
#include "../models/Channel.h"
#include "../models/ChannelEvent.h"
#include "../models/ChannelList.h"
#include "../models/ChannelStats.h"
#include "../models/ChannelTopic.h"
#include "../models/ChannelViewer.h"
#include "../models/DMChannel.h"
#include "../models/Message.h"
#include "../models/PatchChannelRequest.h"
#include "../models/PatchChannelSubscribersRequest.h"
#include "../models/Pin.h"
#include "../models/PostChannelRequest.h"
#include "../models/PostMessageRequest.h"
#include "../models/PutChannelSubscribersRequest.h"
#include "../models/PutChannelTopicRequest.h"


namespace traQ {

class ChannelApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    ChannelApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    ChannelApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    ChannelApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    ChannelApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // チャンネルを作成
    auto createChannel(
        const std::optional<PostChannelRequest>& _postChannelRequest
    );


    // チャンネル情報を変更
    auto editChannel(
        const std::string& _channelId, 
        const std::optional<PatchChannelRequest>& _patchChannelRequest
    );


    // チャンネルの通知購読者を編集
    auto editChannelSubscribers(
        const std::string& _channelId, 
        const std::optional<PatchChannelSubscribersRequest>& _patchChannelSubscribersRequest
    );


    // チャンネルトピックを編集
    auto editChannelTopic(
        const std::string& _channelId, 
        const std::optional<PutChannelTopicRequest>& _putChannelTopicRequest
    );


    // チャンネル情報を取得
    auto getChannel(
        const std::string& _channelId
    );


    // チャンネル参加中のBOTのリストを取得
    auto getChannelBots(
        const std::string& _channelId
    );


    // チャンネルイベントのリストを取得
    auto getChannelEvents(
        const std::string& _channelId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    );


    // チャンネルピンのリストを取得
    auto getChannelPins(
        const std::string& _channelId
    );


    // チャンネル統計情報を取得
    auto getChannelStats(
        const std::string& _channelId
    );


    // チャンネルの通知購読者のリストを取得
    auto getChannelSubscribers(
        const std::string& _channelId
    );


    // チャンネルトピックを取得
    auto getChannelTopic(
        const std::string& _channelId
    );


    // チャンネル閲覧者リストを取得
    auto getChannelViewers(
        const std::string& _channelId
    );


    // チャンネルリストを取得
    auto getChannels(
        const std::optional<bool>& _includeDm
    );


    // チャンネルメッセージのリストを取得
    auto getMessages(
        const std::string& _channelId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    );


    // DMチャンネル情報を取得
    auto getUserDMChannel(
        const std::string& _userId
    );


    // チャンネルにメッセージを投稿
    auto postMessage(
        const std::string& _channelId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    );


    // チャンネルの通知購読者を設定
    auto setChannelSubscribers(
        const std::string& _channelId, 
        const std::optional<PutChannelSubscribersRequest>& _putChannelSubscribersRequest
    );


};

}

#endif
