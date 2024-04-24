#ifndef TRAQ_StampApi_H
#define TRAQ_StampApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

#include <traQ/models/MessageStamp.h>
#include <traQ/models/PatchStampPaletteRequest.h>
#include <traQ/models/PatchStampRequest.h>
#include <traQ/models/PostMessageStampRequest.h>
#include <traQ/models/PostStampPaletteRequest.h>
#include <traQ/models/Stamp.h>
#include <traQ/models/StampHistoryEntry.h>
#include <traQ/models/StampPalette.h>
#include <traQ/models/StampStats.h>
#include <traQ/models/StampWithThumbnail.h>


namespace traQApi {

class StampApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    StampApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    StampApi& setBearerToken(std::string _token);
    StampApi& setBasicAuth(std::string _username, std::string _password);
    StampApi& setApikey(std::string _apikey);


    // スタンプを押す
    void
    addMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId, 
        const std::optional<PostMessageStampRequest>& _postMessageStampRequest
    );

    // スタンプ画像を変更
    void
    changeStampImage(
        const std::string& _stampId, 
        const drogon::UploadFile& _file
    );

    // スタンプを作成
    Stamp
    createStamp(
        const std::string& _name, 
        const drogon::UploadFile& _file
    );

    // スタンプパレットを作成
    StampPalette
    createStampPalette(
        const std::optional<PostStampPaletteRequest>& _postStampPaletteRequest
    );

    // スタンプを削除
    void
    deleteStamp(
        const std::string& _stampId
    );

    // スタンプパレットを削除
    void
    deleteStampPalette(
        const std::string& _paletteId
    );

    // スタンプ情報を変更
    void
    editStamp(
        const std::string& _stampId, 
        const std::optional<PatchStampRequest>& _patchStampRequest
    );

    // スタンプパレットを編集
    void
    editStampPalette(
        const std::string& _paletteId, 
        const std::optional<PatchStampPaletteRequest>& _patchStampPaletteRequest
    );

    // メッセージのスタンプリストを取得
    std::vector<MessageStamp>
    getMessageStamps(
        const std::string& _messageId
    );

    // スタンプ履歴を取得
    std::vector<StampHistoryEntry>
    getMyStampHistory(
        const std::optional<int32_t>& _limit
    );

    // スタンプ情報を取得
    Stamp
    getStamp(
        const std::string& _stampId
    );

    // スタンプ画像を取得
    drogon::HttpResponsePtr
    getStampImage(
        const std::string& _stampId
    );

    // スタンプパレットを取得
    StampPalette
    getStampPalette(
        const std::string& _paletteId
    );

    // スタンプパレットのリストを取得
    std::vector<StampPalette>
    getStampPalettes(
    );

    // スタンプ統計情報を取得
    StampStats
    getStampStats(
        const std::string& _stampId
    );

    // スタンプリストを取得
    std::vector<StampWithThumbnail>
    getStamps(
        const std::optional<bool>& _includeUnicode, 
        const std::optional<std::string>& _type
    );

    // スタンプを消す
    void
    removeMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId
    );

};

}

#endif
