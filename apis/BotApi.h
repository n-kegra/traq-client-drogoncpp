#ifndef _BotApi_H
#define _BotApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/Bot.h"
#include "../models/BotDetail.h"
#include "../models/BotEventLog.h"
#include "../models/BotTokens.h"
#include "../models/BotUser.h"
#include "../models/GetBot200Response.h"
#include "../models/PatchBotRequest.h"
#include "../models/PostBotActionJoinRequest.h"
#include "../models/PostBotActionLeaveRequest.h"
#include "../models/PostBotRequest.h"


namespace traQ {

class BotApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    BotApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    BotApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    BotApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    BotApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // BOTをアクティベート
    auto activateBot(
        const std::string& _botId
    );


    // BOTのアイコン画像を変更
    auto changeBotIcon(
        const std::string& _botId, 
        const drogon::UploadFile& _file
    );


    // WebSocket Mode BOT用通知ストリームに接続します
    auto connectBotWS(
    );


    // BOTを作成
    auto createBot(
        const std::optional<PostBotRequest>& _postBotRequest
    );


    // BOTを削除
    auto deleteBot(
        const std::string& _botId
    );


    // BOT情報を変更
    auto editBot(
        const std::string& _botId, 
        const std::optional<PatchBotRequest>& _patchBotRequest
    );


    // BOT情報を取得
    auto getBot(
        const std::string& _botId, 
        const std::optional<bool>& _detail
    );


    // BOTのアイコン画像を取得
    auto getBotIcon(
        const std::string& _botId
    );


    // BOTのイベントログを取得
    auto getBotLogs(
        const std::string& _botId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset
    );


    // BOTリストを取得
    auto getBots(
        const std::optional<bool>& _all
    );


    // チャンネル参加中のBOTのリストを取得
    auto getChannelBots(
        const std::string& _channelId
    );


    // BOTをインアクティベート
    auto inactivateBot(
        const std::string& _botId
    );


    // BOTをチャンネルに参加させる
    auto letBotJoinChannel(
        const std::string& _botId, 
        const std::optional<PostBotActionJoinRequest>& _postBotActionJoinRequest
    );


    // BOTをチャンネルから退出させる
    auto letBotLeaveChannel(
        const std::string& _botId, 
        const std::optional<PostBotActionLeaveRequest>& _postBotActionLeaveRequest
    );


    // BOTのトークンを再発行
    auto reissueBot(
        const std::string& _botId
    );


};

}

#endif
