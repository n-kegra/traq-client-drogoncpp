#ifndef _MessageApi_H
#define _MessageApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Message.h"
#include "../models/MessageClip.h"
#include "../models/MessagePin.h"
#include "../models/MessageSearchResult.h"
#include "../models/MessageStamp.h"
#include "../models/PostMessageRequest.h"
#include "../models/PostMessageStampRequest.h"


namespace traQ {

class MessageApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    MessageApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    MessageApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    MessageApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    MessageApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // スタンプを押す
    auto addMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId, 
        const std::optional<PostMessageStampRequest>& _postMessageStampRequest
    );


    // ピン留めする
    auto createPin(
        const std::string& _messageId
    );


    // メッセージを削除
    auto deleteMessage(
        const std::string& _messageId
    );


    // メッセージを編集
    auto editMessage(
        const std::string& _messageId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    );


    // ダイレクトメッセージのリストを取得
    auto getDirectMessages(
        const std::string& _userId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _since, 
        const std::optional<std::string>& _until, 
        const std::optional<bool>& _inclusive, 
        const std::optional<std::string>& _order
    );


    // メッセージを取得
    auto getMessage(
        const std::string& _messageId
    );


    // 自分のクリップを取得
    auto getMessageClips(
        const std::string& _messageId
    );


    // メッセージのスタンプリストを取得
    auto getMessageStamps(
        const std::string& _messageId
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


    // ピン留めを取得
    auto getPin(
        const std::string& _messageId
    );


    // ダイレクトメッセージを送信
    auto postDirectMessage(
        const std::string& _userId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    );


    // チャンネルにメッセージを投稿
    auto postMessage(
        const std::string& _channelId, 
        const std::optional<PostMessageRequest>& _postMessageRequest
    );


    // スタンプを消す
    auto removeMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId
    );


    // ピン留めを外す
    auto removePin(
        const std::string& _messageId
    );


    // メッセージを検索
    auto searchMessages(
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
