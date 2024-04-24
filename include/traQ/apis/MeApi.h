#ifndef TRAQ_MeApi_H
#define TRAQ_MeApi_H

#include <drogon/drogon.h>
#include <string>
#include <optional>

#include <traQ/models/ActiveOAuth2Token.h>
#include <traQ/models/ExternalProviderUser.h>
#include <traQ/models/GetNotifyCitation.h>
#include <traQ/models/LoginSession.h>
#include <traQ/models/MyChannelViewState.h>
#include <traQ/models/MyUserDetail.h>
#include <traQ/models/PatchMeRequest.h>
#include <traQ/models/PatchUserTagRequest.h>
#include <traQ/models/PostLinkExternalAccount.h>
#include <traQ/models/PostMyFCMDeviceRequest.h>
#include <traQ/models/PostStarRequest.h>
#include <traQ/models/PostUnlinkExternalAccount.h>
#include <traQ/models/PostUserTagRequest.h>
#include <traQ/models/PutChannelSubscribeLevelRequest.h>
#include <traQ/models/PutMyPasswordRequest.h>
#include <traQ/models/PutNotifyCitationRequest.h>
#include <traQ/models/StampHistoryEntry.h>
#include <traQ/models/UnreadChannel.h>
#include <traQ/models/UserSettings.h>
#include <traQ/models/UserSubscribeState.h>
#include <traQ/models/UserTag.h>


namespace traQApi {

class MeApi {
    std::string baseurl_path;
    std::optional<std::string> bearer_token;
    std::optional<std::string> basic_username;
    std::optional<std::string> basic_password;
    std::optional<std::string> apikey;
    drogon::HttpClientPtr client;

public:

    MeApi(std::string baseurl = "https://q.trap.jp/api/v3");
    
    MeApi& setBearerToken(std::string _token);
    MeApi& setBasicAuth(std::string _username, std::string _password);
    MeApi& setApikey(std::string _apikey);


    // チャンネルをスターに追加
    void
    addMyStar(
        const std::optional<PostStarRequest>& _postStarRequest
    );

    // 自分にタグを追加
    UserTag
    addMyUserTag(
        const std::optional<PostUserTagRequest>& _postUserTagRequest
    );

    // 自分のアイコン画像を変更
    void
    changeMyIcon(
        const drogon::UploadFile& _file
    );

    // メッセージ引用通知の設定情報を変更
    void
    changeMyNotifyCitation(
        const std::optional<PutNotifyCitationRequest>& _putNotifyCitationRequest
    );

    // 自分のパスワードを変更
    void
    changeMyPassword(
        const std::optional<PutMyPasswordRequest>& _putMyPasswordRequest
    );

    // 自分のユーザー情報を変更
    void
    editMe(
        const std::optional<PatchMeRequest>& _patchMeRequest
    );

    // 自分のタグを編集
    void
    editMyUserTag(
        const std::string& _tagId, 
        const std::optional<PatchUserTagRequest>& _patchUserTagRequest
    );

    // 自分のユーザー詳細を取得
    MyUserDetail
    getMe(
    );

    // 自分のチャンネル購読状態を取得
    std::vector<UserSubscribeState>
    getMyChannelSubscriptions(
    );

    // 外部ログインアカウント一覧を取得
    std::vector<ExternalProviderUser>
    getMyExternalAccounts(
    );

    // 自分のアイコン画像を取得
    drogon::HttpResponsePtr
    getMyIcon(
    );

    // メッセージ引用通知の設定情報を取得
    GetNotifyCitation
    getMyNotifyCitation(
    );

    // QRコードを取得
    drogon::HttpResponsePtr
    getMyQRCode(
        const std::optional<bool>& _token
    );

    // 自分のログインセッションリストを取得
    std::vector<LoginSession>
    getMySessions(
    );

    // スタンプ履歴を取得
    std::vector<StampHistoryEntry>
    getMyStampHistory(
        const std::optional<int32_t>& _limit
    );

    // スターチャンネルリストを取得
    std::vector<std::string>
    getMyStars(
    );

    // 有効トークンのリストを取得
    std::vector<ActiveOAuth2Token>
    getMyTokens(
    );

    // 未読チャンネルを取得
    std::vector<UnreadChannel>
    getMyUnreadChannels(
    );

    // 自分のタグリストを取得
    std::vector<UserTag>
    getMyUserTags(
    );

    // 自身のチャンネル閲覧状態一覧を取得
    std::vector<MyChannelViewState>
    getMyViewStates(
    );

    // ユーザー設定を取得
    UserSettings
    getUserSettings(
    );

    // 外部ログインアカウントを紐付ける
    void
    linkExternalAccount(
        const std::optional<PostLinkExternalAccount>& _postLinkExternalAccount
    );

    // チャンネルを既読にする
    void
    readChannel(
        const std::string& _channelId
    );

    // FCMデバイスを登録
    void
    registerFCMDevice(
        const std::optional<PostMyFCMDeviceRequest>& _postMyFCMDeviceRequest
    );

    // チャンネルをスターから削除します
    void
    removeMyStar(
        const std::string& _channelId
    );

    // 自分からタグを削除します
    void
    removeMyUserTag(
        const std::string& _tagId
    );

    // セッションを無効化
    void
    revokeMySession(
        const std::string& _sessionId
    );

    // トークンの認可を取り消す
    void
    revokeMyToken(
        const std::string& _tokenId
    );

    // チャンネル購読レベルを設定
    void
    setChannelSubscribeLevel(
        const std::string& _channelId, 
        const std::optional<PutChannelSubscribeLevelRequest>& _putChannelSubscribeLevelRequest
    );

    // 外部ログインアカウントの紐付けを解除
    void
    unlinkExternalAccount(
        const std::optional<PostUnlinkExternalAccount>& _postUnlinkExternalAccount
    );

};

}

#endif
