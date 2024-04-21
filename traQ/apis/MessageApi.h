#ifndef TRAQ_MessageApi_H
#define TRAQ_MessageApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/Message.h>
#include <traQ/models/MessageClip.h>
#include <traQ/models/MessagePin.h>
#include <traQ/models/MessageSearchResult.h>
#include <traQ/models/MessageStamp.h>
#include <traQ/models/PostMessageRequest.h>
#include <traQ/models/PostMessageStampRequest.h>


namespace traQApi {

class MessageApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    MessageApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    MessageApi& setBearerToken(std::string _token);
    MessageApi& setBasicAuth(std::string _username, std::string _password);
    MessageApi& setApikey(std::string _apikey);


    // スタンプを押す
    void
    addMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId, 
        const std::optional<PostMessageStampRequest>& _postMessageStampRequest
    );

    // ピン留めする
    MessagePin
    createPin(
        const std::string& _messageId
    );

    // メッセージを削除
    void
    deleteMessage(
        const std::string& _messageId
    );

    // メッセージを編集
    void
    editMessage(
        const std::string& _messageId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    );

    // ダイレクトメッセージのリストを取得
    std::vector<Message>
    getDirectMessages(
        const std::string& _userId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    );

    // メッセージを取得
    Message
    getMessage(
        const std::string& _messageId
    );

    // 自分のクリップを取得
    std::vector<MessageClip>
    getMessageClips(
        const std::string& _messageId
    );

    // メッセージのスタンプリストを取得
    std::vector<MessageStamp>
    getMessageStamps(
        const std::string& _messageId
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

    // ピン留めを取得
    MessagePin
    getPin(
        const std::string& _messageId
    );

    // ダイレクトメッセージを送信
    Message
    postDirectMessage(
        const std::string& _userId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    );

    // チャンネルにメッセージを投稿
    Message
    postMessage(
        const std::string& _channelId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    );

    // スタンプを消す
    void
    removeMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId
    );

    // ピン留めを外す
    void
    removePin(
        const std::string& _messageId
    );

    // メッセージを検索
    MessageSearchResult
    searchMessages(
        const std::optional<std::string>& _word, 
        const std::optional<std::string>& _after, 
        const std::optional<std::string>& _before, 
        const std::optional<std::string>& _in, 
        const std::optional<std::string>& _to, 
        const std::optional<std::string>& _from, 
        const std::optional<std::string>& _citation, 
        const std::optional<bool>& _bot, 
        const std::optional<bool>& _hasURL, 
        const std::optional<bool>& _hasAttachments, 
        const std::optional<bool>& _hasImage, 
        const std::optional<bool>& _hasVideo, 
        const std::optional<bool>& _hasAudio, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _sort
    );

};

}

#endif
