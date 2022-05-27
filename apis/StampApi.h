#ifndef _StampApi_H
#define _StampApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/MessageStamp.h"
#include "../models/PatchStampPaletteRequest.h"
#include "../models/PatchStampRequest.h"
#include "../models/PostMessageStampRequest.h"
#include "../models/PostStampPaletteRequest.h"
#include "../models/Stamp.h"
#include "../models/StampHistoryEntry.h"
#include "../models/StampPalette.h"
#include "../models/StampStats.h"


namespace traQ {

class StampApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    StampApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    StampApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    StampApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    StampApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // スタンプを押す
    auto addMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId, 
        const std::optional<PostMessageStampRequest>& _postMessageStampRequest
    );


    // スタンプ画像を変更
    auto changeStampImage(
        const std::string& _stampId, 
        const drogon::UploadFile& _file
    );


    // スタンプを作成
    auto createStamp(
        const std::string& _name, 
        const drogon::UploadFile& _file
    );


    // スタンプパレットを作成
    auto createStampPalette(
        const std::optional<PostStampPaletteRequest>& _postStampPaletteRequest
    );


    // スタンプを削除
    auto deleteStamp(
        const std::string& _stampId
    );


    // スタンプパレットを削除
    auto deleteStampPalette(
        const std::string& _paletteId
    );


    // スタンプ情報を変更
    auto editStamp(
        const std::string& _stampId, 
        const std::optional<PatchStampRequest>& _patchStampRequest
    );


    // スタンプパレットを編集
    auto editStampPalette(
        const std::string& _paletteId, 
        const std::optional<PatchStampPaletteRequest>& _patchStampPaletteRequest
    );


    // メッセージのスタンプリストを取得
    auto getMessageStamps(
        const std::string& _messageId
    );


    // スタンプ履歴を取得
    auto getMyStampHistory(
        const std::optional<int32_t>& _limit
    );


    // スタンプ情報を取得
    auto getStamp(
        const std::string& _stampId
    );


    // スタンプ画像を取得
    auto getStampImage(
        const std::string& _stampId
    );


    // スタンプパレットを取得
    auto getStampPalette(
        const std::string& _paletteId
    );


    // スタンプパレットのリストを取得
    auto getStampPalettes(
    );


    // スタンプ統計情報を取得
    auto getStampStats(
        const std::string& _stampId
    );


    // スタンプリストを取得
    auto getStamps(
        const std::optional<bool>& _includeUnicode, 
        const std::optional<std::string>& _type
    );


    // スタンプを消す
    auto removeMessageStamp(
        const std::string& _messageId, 
        const std::string& _stampId
    );


};

}

#endif
