#ifndef _ClipApi_H
#define _ClipApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ClipFolder.h"
#include "../models/ClippedMessage.h"
#include "../models/MessageClip.h"
#include "../models/PatchClipFolderRequest.h"
#include "../models/PostClipFolderMessageRequest.h"
#include "../models/PostClipFolderRequest.h"


namespace traQ {

class ClipApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    ClipApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    ClipApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    ClipApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    ClipApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // メッセージをクリップフォルダに追加
    auto clipMessage(
        const std::string& _folderId, 
        const std::optional<PostClipFolderMessageRequest>& _postClipFolderMessageRequest
    );


    // クリップフォルダを作成
    auto createClipFolder(
        const std::optional<PostClipFolderRequest>& _postClipFolderRequest
    );


    // クリップフォルダを削除
    auto deleteClipFolder(
        const std::string& _folderId
    );


    // クリップフォルダ情報を編集
    auto editClipFolder(
        const std::string& _folderId, 
        const std::optional<PatchClipFolderRequest>& _patchClipFolderRequest
    );


    // クリップフォルダ情報を取得
    auto getClipFolder(
        const std::string& _folderId
    );


    // クリップフォルダのリストを取得
    auto getClipFolders(
    );


    // フォルダ内のクリップのリストを取得
    auto getClips(
        const std::string& _folderId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _order
    );


    // 自分のクリップを取得
    auto getMessageClips(
        const std::string& _messageId
    );


    // メッセージをクリップフォルダから除外
    auto unclipMessage(
        const std::string& _folderId, 
        const std::string& _messageId
    );


};

}

#endif
