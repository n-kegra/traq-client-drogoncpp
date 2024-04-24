#ifndef TRAQ_ChannelApi_H
#define TRAQ_ChannelApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

#include <traQ/models/BotUser.h>
#include <traQ/models/Channel.h>
#include <traQ/models/ChannelEvent.h>
#include <traQ/models/ChannelList.h>
#include <traQ/models/ChannelStats.h>
#include <traQ/models/ChannelTopic.h>
#include <traQ/models/ChannelViewer.h>
#include <traQ/models/DMChannel.h>
#include <traQ/models/Message.h>
#include <traQ/models/PatchChannelRequest.h>
#include <traQ/models/PatchChannelSubscribersRequest.h>
#include <traQ/models/Pin.h>
#include <traQ/models/PostChannelRequest.h>
#include <traQ/models/PostMessageRequest.h>
#include <traQ/models/PutChannelSubscribersRequest.h>
#include <traQ/models/PutChannelTopicRequest.h>


namespace traQApi {

class ChannelApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    ChannelApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    ChannelApi& setBearerToken(std::string _token);
    ChannelApi& setBasicAuth(std::string _username, std::string _password);
    ChannelApi& setApikey(std::string _apikey);


    // チャンネルを作成
    Channel
    createChannel(
        const std::optional<PostChannelRequest>& _postChannelRequest
    );

    // チャンネル情報を変更
    void
    editChannel(
        const std::string& _channelId, 
        const std::optional<PatchChannelRequest>& _patchChannelRequest
    );

    // チャンネルの通知購読者を編集
    void
    editChannelSubscribers(
        const std::string& _channelId, 
        const std::optional<PatchChannelSubscribersRequest>& _patchChannelSubscribersRequest
    );

    // チャンネルトピックを編集
    void
    editChannelTopic(
        const std::string& _channelId, 
        const std::optional<PutChannelTopicRequest>& _putChannelTopicRequest
    );

    // チャンネル情報を取得
    Channel
    getChannel(
        const std::string& _channelId
    );

    // チャンネル参加中のBOTのリストを取得
    std::vector<BotUser>
    getChannelBots(
        const std::string& _channelId
    );

    // チャンネルイベントのリストを取得
    std::vector<ChannelEvent>
    getChannelEvents(
        const std::string& _channelId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    );

    // チャンネルピンのリストを取得
    std::vector<Pin>
    getChannelPins(
        const std::string& _channelId
    );

    // チャンネル統計情報を取得
    ChannelStats
    getChannelStats(
        const std::string& _channelId
    );

    // チャンネルの通知購読者のリストを取得
    std::vector<std::string>
    getChannelSubscribers(
        const std::string& _channelId
    );

    // チャンネルトピックを取得
    ChannelTopic
    getChannelTopic(
        const std::string& _channelId
    );

    // チャンネル閲覧者リストを取得
    std::vector<ChannelViewer>
    getChannelViewers(
        const std::string& _channelId
    );

    // チャンネルリストを取得
    ChannelList
    getChannels(
        const std::optional<bool>& _includeDm
    );

    // チャンネルメッセージのリストを取得
    std::vector<Message>
    getMessages(
        const std::string& _channelId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    );

    // DMチャンネル情報を取得
    DMChannel
    getUserDMChannel(
        const std::string& _userId
    );

    // チャンネルにメッセージを投稿
    Message
    postMessage(
        const std::string& _channelId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    );

    // チャンネルの通知購読者を設定
    void
    setChannelSubscribers(
        const std::string& _channelId, 
        const std::optional<PutChannelSubscribersRequest>& _putChannelSubscribersRequest
    );

};

}

#endif
