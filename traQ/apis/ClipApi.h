#ifndef TRAQ_ClipApi_H
#define TRAQ_ClipApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>
#include <traQ/Helper.h>

#include <traQ/models/ClipFolder.h>
#include <traQ/models/ClippedMessage.h>
#include <traQ/models/MessageClip.h>
#include <traQ/models/PatchClipFolderRequest.h>
#include <traQ/models/PostClipFolderMessageRequest.h>
#include <traQ/models/PostClipFolderRequest.h>


namespace traQApi {

class ClipApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    ClipApi(std::string _baseurl_host, std::string _baseurl_path);
    
    ClipApi& setBearerToken(std::string _token);
    ClipApi& setBasicAuth(std::string _username, std::string _password);
    ClipApi& setApikey(std::string _apikey);


    // メッセージをクリップフォルダに追加
    ClippedMessage
    clipMessage(
        const std::string& _folderId, 
        const std::optional<PostClipFolderMessageRequest>& _postClipFolderMessageRequest
    );

    // クリップフォルダを作成
    ClipFolder
    createClipFolder(
        const std::optional<PostClipFolderRequest>& _postClipFolderRequest
    );

    // クリップフォルダを削除
    void
    deleteClipFolder(
        const std::string& _folderId
    );

    // クリップフォルダ情報を編集
    void
    editClipFolder(
        const std::string& _folderId, 
        const std::optional<PatchClipFolderRequest>& _patchClipFolderRequest
    );

    // クリップフォルダ情報を取得
    ClipFolder
    getClipFolder(
        const std::string& _folderId
    );

    // クリップフォルダのリストを取得
    std::vector<ClipFolder>
    getClipFolders(
    );

    // フォルダ内のクリップのリストを取得
    std::vector<ClippedMessage>
    getClips(
        const std::string& _folderId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset, 
        const std::optional<std::string>& _order
    );

    // 自分のクリップを取得
    std::vector<MessageClip>
    getMessageClips(
        const std::string& _messageId
    );

    // メッセージをクリップフォルダから除外
    void
    unclipMessage(
        const std::string& _folderId, 
        const std::string& _messageId
    );

};

}

#endif
