#ifndef _MeApi_H
#define _MeApi_H

#include <drogon/drogon.h>
#include <drogon/utils/Utilities.h>
#include <json/json.h>
#include <string>
#include <optional>
#include "../helper.h"

#include "../models/ActiveOAuth2Token.h"
#include "../models/ExternalProviderUser.h"
#include "../models/GetNotifyCitation.h"
#include "../models/LoginSession.h"
#include "../models/MyChannelViewState.h"
#include "../models/MyUserDetail.h"
#include "../models/PatchMeRequest.h"
#include "../models/PatchUserTagRequest.h"
#include "../models/PostLinkExternalAccount.h"
#include "../models/PostMyFCMDeviceRequest.h"
#include "../models/PostStarRequest.h"
#include "../models/PostUnlinkExternalAccount.h"
#include "../models/PostUserTagRequest.h"
#include "../models/PutChannelSubscribeLevelRequest.h"
#include "../models/PutMyPasswordRequest.h"
#include "../models/PutNotifyCitationRequest.h"
#include "../models/StampHistoryEntry.h"
#include "../models/UnreadChannel.h"
#include "../models/UserSettings.h"
#include "../models/UserSubscribeState.h"
#include "../models/UserTag.h"


namespace traQ {

class MeApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    MeApi(std::string _baseurl_host, std::string _baseurl_path) :
        baseurl_path(_baseurl_path), client(drogon::HttpClient::newHttpClient(_baseurl_host)) {}
    
    MeApi& setBearerToken(std::string _token) { this->bearer_token = _token; return *this; }
    MeApi& setBasicAuth(std::string _username, std::string _password) { this->basic_username = _username; this->basic_password = _password; return *this; }
    MeApi& setApikey(std::string _apikey) { this->apikey = _apikey; return *this; }


    // チャンネルをスターに追加
    auto addMyStar(
        const std::optional<PostStarRequest>& _postStarRequest
    );


    // 自分にタグを追加
    auto addMyUserTag(
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    );


    // 自分のアイコン画像を変更
    auto changeMyIcon(
        const drogon::UploadFile& _file
    );


    // メッセージ引用通知の設定情報を変更
    auto changeMyNotifyCitation(
        const std::optional<PutNotifyCitationRequest>& _putNotifyCitationRequest
    );


    // 自分のパスワードを変更
    auto changeMyPassword(
        const std::optional<PutMyPasswordRequest>& _putMyPasswordRequest
    );


    // 自分のユーザー情報を変更
    auto editMe(
        const std::optional<PatchMeRequest>& _patchMeRequest
    );


    // 自分のタグを編集
    auto editMyUserTag(
        const std::string& _tagId, 
        const std::optional<PatchUserTagRequest>& _patchUserTagRequest
    );


    // 自分のユーザー詳細を取得
    auto getMe(
    );


    // 自分のチャンネル購読状態を取得
    auto getMyChannelSubscriptions(
    );


    // 外部ログインアカウント一覧を取得
    auto getMyExternalAccounts(
    );


    // 自分のアイコン画像を取得
    auto getMyIcon(
    );


    // メッセージ引用通知の設定情報を取得
    auto getMyNotifyCitation(
    );


    // QRコードを取得
    auto getMyQRCode(
        const std::optional<bool>& _token
    );


    // 自分のログインセッションリストを取得
    auto getMySessions(
    );


    // スタンプ履歴を取得
    auto getMyStampHistory(
        const std::optional<int32_t>& _limit
    );


    // スターチャンネルリストを取得
    auto getMyStars(
    );


    // 有効トークンのリストを取得
    auto getMyTokens(
    );


    // 未読チャンネルを取得
    auto getMyUnreadChannels(
    );


    // 自分のタグリストを取得
    auto getMyUserTags(
    );


    // 自身のチャンネル閲覧状態一覧を取得
    auto getMyViewStates(
    );


    // ユーザー設定を取得
    auto getUserSettings(
    );


    // 外部ログインアカウントを紐付ける
    auto linkExternalAccount(
        const std::optional<PostLinkExternalAccount>& _postLinkExternalAccount
    );


    // チャンネルを既読にする
    auto readChannel(
        const std::string& _channelId
    );


    // FCMデバイスを登録
    auto registerFCMDevice(
        const std::optional<PostMyFCMDeviceRequest>& _postMyFCMDeviceRequest
    );


    // チャンネルをスターから削除します
    auto removeMyStar(
        const std::string& _channelId
    );


    // 自分からタグを削除します
    auto removeMyUserTag(
        const std::string& _tagId
    );


    // セッションを無効化
    auto revokeMySession(
        const std::string& _sessionId
    );


    // トークンの認可を取り消す
    auto revokeMyToken(
        const std::string& _tokenId
    );


    // チャンネル購読レベルを設定
    auto setChannelSubscribeLevel(
        const std::string& _channelId, 
        const std::optional<PutChannelSubscribeLevelRequest>& _putChannelSubscribeLevelRequest
    );


    // 外部ログインアカウントの紐付けを解除
    auto unlinkExternalAccount(
        const std::optional<PostUnlinkExternalAccount>& _postUnlinkExternalAccount
    );


};

}

#endif
