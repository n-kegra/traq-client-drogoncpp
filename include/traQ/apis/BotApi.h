#ifndef TRAQ_BotApi_H
#define TRAQ_BotApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

#include <traQ/models/Bot.h>
#include <traQ/models/BotDetail.h>
#include <traQ/models/BotEventLog.h>
#include <traQ/models/BotTokens.h>
#include <traQ/models/BotUser.h>
#include <traQ/models/GetBot200Response.h>
#include <traQ/models/PatchBotRequest.h>
#include <traQ/models/PostBotActionJoinRequest.h>
#include <traQ/models/PostBotActionLeaveRequest.h>
#include <traQ/models/PostBotRequest.h>


namespace traQApi {

class BotApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    BotApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    BotApi& setBearerToken(std::string _token);
    BotApi& setBasicAuth(std::string _username, std::string _password);
    BotApi& setApikey(std::string _apikey);


    // BOTをアクティベート
    void
    activateBot(
        const std::string& _botId
    );

    // BOTのアイコン画像を変更
    void
    changeBotIcon(
        const std::string& _botId, 
        const drogon::UploadFile& _file
    );

    // WebSocket Mode BOT用通知ストリームに接続します
    void
    connectBotWS(
    );

    // BOTを作成
    BotDetail
    createBot(
        const std::optional<PostBotRequest>& _postBotRequest
    );

    // BOTを削除
    void
    deleteBot(
        const std::string& _botId
    );

    // BOT情報を変更
    void
    editBot(
        const std::string& _botId, 
        const std::optional<PatchBotRequest>& _patchBotRequest
    );

    // BOT情報を取得
    GetBot200Response
    getBot(
        const std::string& _botId, 
        const std::optional<bool>& _detail
    );

    // BOTのアイコン画像を取得
    drogon::HttpResponsePtr
    getBotIcon(
        const std::string& _botId
    );

    // BOTのイベントログを取得
    std::vector<BotEventLog>
    getBotLogs(
        const std::string& _botId, 
        const std::optional<int32_t>& _limit, 
        const std::optional<int32_t>& _offset
    );

    // BOTリストを取得
    std::vector<Bot>
    getBots(
        const std::optional<bool>& _all
    );

    // チャンネル参加中のBOTのリストを取得
    std::vector<BotUser>
    getChannelBots(
        const std::string& _channelId
    );

    // BOTをインアクティベート
    void
    inactivateBot(
        const std::string& _botId
    );

    // BOTをチャンネルに参加させる
    void
    letBotJoinChannel(
        const std::string& _botId, 
        const std::optional<PostBotActionJoinRequest>& _postBotActionJoinRequest
    );

    // BOTをチャンネルから退出させる
    void
    letBotLeaveChannel(
        const std::string& _botId, 
        const std::optional<PostBotActionLeaveRequest>& _postBotActionLeaveRequest
    );

    // BOTのトークンを再発行
    BotTokens
    reissueBot(
        const std::string& _botId
    );

};

}

#endif
