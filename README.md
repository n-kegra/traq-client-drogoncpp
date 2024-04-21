# Documentation for traQ v3
<a name="documentation-for-api-endpoints"></a>
## Documentation for API Endpoints
All URIs are relative to *https://q.trap.jp/api/v3*
Class | Method | HTTP request | Description
------------ | ------------- | ------------- | -------------
*ActivityApi* | [**getActivityTimeline**](Apis/ActivityApi.md#getactivitytimeline) | **GET** /activity/timeline | アクテビティタイムラインを取得
*ActivityApi* | [**getOnlineUsers**](Apis/ActivityApi.md#getonlineusers) | **GET** /activity/onlines | オンラインユーザーリストを取得
*AuthenticationApi* | [**getMyExternalAccounts**](Apis/AuthenticationApi.md#getmyexternalaccounts) | **GET** /users/me/ex-accounts | 外部ログインアカウント一覧を取得
*AuthenticationApi* | [**getMySessions**](Apis/AuthenticationApi.md#getmysessions) | **GET** /users/me/sessions | 自分のログインセッションリストを取得
*AuthenticationApi* | [**linkExternalAccount**](Apis/AuthenticationApi.md#linkexternalaccount) | **POST** /users/me/ex-accounts/link | 外部ログインアカウントを紐付ける
*AuthenticationApi* | [**login**](Apis/AuthenticationApi.md#login) | **POST** /login | ログイン
*AuthenticationApi* | [**logout**](Apis/AuthenticationApi.md#logout) | **POST** /logout | ログアウト
*AuthenticationApi* | [**revokeMySession**](Apis/AuthenticationApi.md#revokemysession) | **DELETE** /users/me/sessions/{sessionId} | セッションを無効化
*AuthenticationApi* | [**unlinkExternalAccount**](Apis/AuthenticationApi.md#unlinkexternalaccount) | **POST** /users/me/ex-accounts/unlink | 外部ログインアカウントの紐付けを解除
*BotApi* | [**activateBot**](Apis/BotApi.md#activatebot) | **POST** /bots/{botId}/actions/activate | BOTをアクティベート
*BotApi* | [**changeBotIcon**](Apis/BotApi.md#changeboticon) | **PUT** /bots/{botId}/icon | BOTのアイコン画像を変更
*BotApi* | [**connectBotWS**](Apis/BotApi.md#connectbotws) | **GET** /bots/ws | WebSocket Mode BOT用通知ストリームに接続します
*BotApi* | [**createBot**](Apis/BotApi.md#createbot) | **POST** /bots | BOTを作成
*BotApi* | [**deleteBot**](Apis/BotApi.md#deletebot) | **DELETE** /bots/{botId} | BOTを削除
*BotApi* | [**editBot**](Apis/BotApi.md#editbot) | **PATCH** /bots/{botId} | BOT情報を変更
*BotApi* | [**getBot**](Apis/BotApi.md#getbot) | **GET** /bots/{botId} | BOT情報を取得
*BotApi* | [**getBotIcon**](Apis/BotApi.md#getboticon) | **GET** /bots/{botId}/icon | BOTのアイコン画像を取得
*BotApi* | [**getBotLogs**](Apis/BotApi.md#getbotlogs) | **GET** /bots/{botId}/logs | BOTのイベントログを取得
*BotApi* | [**getBots**](Apis/BotApi.md#getbots) | **GET** /bots | BOTリストを取得
*BotApi* | [**getChannelBots**](Apis/BotApi.md#getchannelbots) | **GET** /channels/{channelId}/bots | チャンネル参加中のBOTのリストを取得
*BotApi* | [**inactivateBot**](Apis/BotApi.md#inactivatebot) | **POST** /bots/{botId}/actions/inactivate | BOTをインアクティベート
*BotApi* | [**letBotJoinChannel**](Apis/BotApi.md#letbotjoinchannel) | **POST** /bots/{botId}/actions/join | BOTをチャンネルに参加させる
*BotApi* | [**letBotLeaveChannel**](Apis/BotApi.md#letbotleavechannel) | **POST** /bots/{botId}/actions/leave | BOTをチャンネルから退出させる
*BotApi* | [**reissueBot**](Apis/BotApi.md#reissuebot) | **POST** /bots/{botId}/actions/reissue | BOTのトークンを再発行
*ChannelApi* | [**createChannel**](Apis/ChannelApi.md#createchannel) | **POST** /channels | チャンネルを作成
*ChannelApi* | [**editChannel**](Apis/ChannelApi.md#editchannel) | **PATCH** /channels/{channelId} | チャンネル情報を変更
*ChannelApi* | [**editChannelSubscribers**](Apis/ChannelApi.md#editchannelsubscribers) | **PATCH** /channels/{channelId}/subscribers | チャンネルの通知購読者を編集
*ChannelApi* | [**editChannelTopic**](Apis/ChannelApi.md#editchanneltopic) | **PUT** /channels/{channelId}/topic | チャンネルトピックを編集
*ChannelApi* | [**getChannel**](Apis/ChannelApi.md#getchannel) | **GET** /channels/{channelId} | チャンネル情報を取得
*ChannelApi* | [**getChannelBots**](Apis/ChannelApi.md#getchannelbots) | **GET** /channels/{channelId}/bots | チャンネル参加中のBOTのリストを取得
*ChannelApi* | [**getChannelEvents**](Apis/ChannelApi.md#getchannelevents) | **GET** /channels/{channelId}/events | チャンネルイベントのリストを取得
*ChannelApi* | [**getChannelPins**](Apis/ChannelApi.md#getchannelpins) | **GET** /channels/{channelId}/pins | チャンネルピンのリストを取得
*ChannelApi* | [**getChannelStats**](Apis/ChannelApi.md#getchannelstats) | **GET** /channels/{channelId}/stats | チャンネル統計情報を取得
*ChannelApi* | [**getChannelSubscribers**](Apis/ChannelApi.md#getchannelsubscribers) | **GET** /channels/{channelId}/subscribers | チャンネルの通知購読者のリストを取得
*ChannelApi* | [**getChannelTopic**](Apis/ChannelApi.md#getchanneltopic) | **GET** /channels/{channelId}/topic | チャンネルトピックを取得
*ChannelApi* | [**getChannelViewers**](Apis/ChannelApi.md#getchannelviewers) | **GET** /channels/{channelId}/viewers | チャンネル閲覧者リストを取得
*ChannelApi* | [**getChannels**](Apis/ChannelApi.md#getchannels) | **GET** /channels | チャンネルリストを取得
*ChannelApi* | [**getMessages**](Apis/ChannelApi.md#getmessages) | **GET** /channels/{channelId}/messages | チャンネルメッセージのリストを取得
*ChannelApi* | [**getUserDMChannel**](Apis/ChannelApi.md#getuserdmchannel) | **GET** /users/{userId}/dm-channel | DMチャンネル情報を取得
*ChannelApi* | [**postMessage**](Apis/ChannelApi.md#postmessage) | **POST** /channels/{channelId}/messages | チャンネルにメッセージを投稿
*ChannelApi* | [**setChannelSubscribers**](Apis/ChannelApi.md#setchannelsubscribers) | **PUT** /channels/{channelId}/subscribers | チャンネルの通知購読者を設定
*ClipApi* | [**clipMessage**](Apis/ClipApi.md#clipmessage) | **POST** /clip-folders/{folderId}/messages | メッセージをクリップフォルダに追加
*ClipApi* | [**createClipFolder**](Apis/ClipApi.md#createclipfolder) | **POST** /clip-folders | クリップフォルダを作成
*ClipApi* | [**deleteClipFolder**](Apis/ClipApi.md#deleteclipfolder) | **DELETE** /clip-folders/{folderId} | クリップフォルダを削除
*ClipApi* | [**editClipFolder**](Apis/ClipApi.md#editclipfolder) | **PATCH** /clip-folders/{folderId} | クリップフォルダ情報を編集
*ClipApi* | [**getClipFolder**](Apis/ClipApi.md#getclipfolder) | **GET** /clip-folders/{folderId} | クリップフォルダ情報を取得
*ClipApi* | [**getClipFolders**](Apis/ClipApi.md#getclipfolders) | **GET** /clip-folders | クリップフォルダのリストを取得
*ClipApi* | [**getClips**](Apis/ClipApi.md#getclips) | **GET** /clip-folders/{folderId}/messages | フォルダ内のクリップのリストを取得
*ClipApi* | [**getMessageClips**](Apis/ClipApi.md#getmessageclips) | **GET** /messages/{messageId}/clips | 自分のクリップを取得
*ClipApi* | [**unclipMessage**](Apis/ClipApi.md#unclipmessage) | **DELETE** /clip-folders/{folderId}/messages/{messageId} | メッセージをクリップフォルダから除外
*FileApi* | [**deleteFile**](Apis/FileApi.md#deletefile) | **DELETE** /files/{fileId} | ファイルを削除
*FileApi* | [**getFile**](Apis/FileApi.md#getfile) | **GET** /files/{fileId} | ファイルをダウンロード
*FileApi* | [**getFileMeta**](Apis/FileApi.md#getfilemeta) | **GET** /files/{fileId}/meta | ファイルメタを取得
*FileApi* | [**getFiles**](Apis/FileApi.md#getfiles) | **GET** /files | ファイルメタのリストを取得
*FileApi* | [**getThumbnailImage**](Apis/FileApi.md#getthumbnailimage) | **GET** /files/{fileId}/thumbnail | サムネイル画像を取得
*FileApi* | [**postFile**](Apis/FileApi.md#postfile) | **POST** /files | ファイルをアップロード
*GroupApi* | [**addUserGroupAdmin**](Apis/GroupApi.md#addusergroupadmin) | **POST** /groups/{groupId}/admins | グループ管理者を追加
*GroupApi* | [**addUserGroupMember**](Apis/GroupApi.md#addusergroupmember) | **POST** /groups/{groupId}/members | グループメンバーを追加
*GroupApi* | [**changeUserGroupIcon**](Apis/GroupApi.md#changeusergroupicon) | **PUT** /groups/{groupId}/icon | ユーザーグループのアイコンを変更
*GroupApi* | [**createUserGroup**](Apis/GroupApi.md#createusergroup) | **POST** /groups | ユーザーグループを作成
*GroupApi* | [**deleteUserGroup**](Apis/GroupApi.md#deleteusergroup) | **DELETE** /groups/{groupId} | ユーザーグループを削除
*GroupApi* | [**editUserGroup**](Apis/GroupApi.md#editusergroup) | **PATCH** /groups/{groupId} | ユーザーグループを編集
*GroupApi* | [**editUserGroupMember**](Apis/GroupApi.md#editusergroupmember) | **PATCH** /groups/{groupId}/members/{userId} | グループメンバーを編集
*GroupApi* | [**getUserGroup**](Apis/GroupApi.md#getusergroup) | **GET** /groups/{groupId} | ユーザーグループを取得
*GroupApi* | [**getUserGroupAdmins**](Apis/GroupApi.md#getusergroupadmins) | **GET** /groups/{groupId}/admins | グループ管理者を取得
*GroupApi* | [**getUserGroupMembers**](Apis/GroupApi.md#getusergroupmembers) | **GET** /groups/{groupId}/members | グループメンバーを取得
*GroupApi* | [**getUserGroups**](Apis/GroupApi.md#getusergroups) | **GET** /groups | ユーザーグループのリストを取得
*GroupApi* | [**removeUserGroupAdmin**](Apis/GroupApi.md#removeusergroupadmin) | **DELETE** /groups/{groupId}/admins/{userId} | グループ管理者を削除
*GroupApi* | [**removeUserGroupMember**](Apis/GroupApi.md#removeusergroupmember) | **DELETE** /groups/{groupId}/members/{userId} | グループメンバーを削除
*MeApi* | [**addMyStar**](Apis/MeApi.md#addmystar) | **POST** /users/me/stars | チャンネルをスターに追加
*MeApi* | [**addMyUserTag**](Apis/MeApi.md#addmyusertag) | **POST** /users/me/tags | 自分にタグを追加
*MeApi* | [**changeMyIcon**](Apis/MeApi.md#changemyicon) | **PUT** /users/me/icon | 自分のアイコン画像を変更
*MeApi* | [**changeMyNotifyCitation**](Apis/MeApi.md#changemynotifycitation) | **PUT** /users/me/settings/notify-citation | メッセージ引用通知の設定情報を変更
*MeApi* | [**changeMyPassword**](Apis/MeApi.md#changemypassword) | **PUT** /users/me/password | 自分のパスワードを変更
*MeApi* | [**editMe**](Apis/MeApi.md#editme) | **PATCH** /users/me | 自分のユーザー情報を変更
*MeApi* | [**editMyUserTag**](Apis/MeApi.md#editmyusertag) | **PATCH** /users/me/tags/{tagId} | 自分のタグを編集
*MeApi* | [**getMe**](Apis/MeApi.md#getme) | **GET** /users/me | 自分のユーザー詳細を取得
*MeApi* | [**getMyChannelSubscriptions**](Apis/MeApi.md#getmychannelsubscriptions) | **GET** /users/me/subscriptions | 自分のチャンネル購読状態を取得
*MeApi* | [**getMyExternalAccounts**](Apis/MeApi.md#getmyexternalaccounts) | **GET** /users/me/ex-accounts | 外部ログインアカウント一覧を取得
*MeApi* | [**getMyIcon**](Apis/MeApi.md#getmyicon) | **GET** /users/me/icon | 自分のアイコン画像を取得
*MeApi* | [**getMyNotifyCitation**](Apis/MeApi.md#getmynotifycitation) | **GET** /users/me/settings/notify-citation | メッセージ引用通知の設定情報を取得
*MeApi* | [**getMyQRCode**](Apis/MeApi.md#getmyqrcode) | **GET** /users/me/qr-code | QRコードを取得
*MeApi* | [**getMySessions**](Apis/MeApi.md#getmysessions) | **GET** /users/me/sessions | 自分のログインセッションリストを取得
*MeApi* | [**getMyStampHistory**](Apis/MeApi.md#getmystamphistory) | **GET** /users/me/stamp-history | スタンプ履歴を取得
*MeApi* | [**getMyStars**](Apis/MeApi.md#getmystars) | **GET** /users/me/stars | スターチャンネルリストを取得
*MeApi* | [**getMyTokens**](Apis/MeApi.md#getmytokens) | **GET** /users/me/tokens | 有効トークンのリストを取得
*MeApi* | [**getMyUnreadChannels**](Apis/MeApi.md#getmyunreadchannels) | **GET** /users/me/unread | 未読チャンネルを取得
*MeApi* | [**getMyUserTags**](Apis/MeApi.md#getmyusertags) | **GET** /users/me/tags | 自分のタグリストを取得
*MeApi* | [**getMyViewStates**](Apis/MeApi.md#getmyviewstates) | **GET** /users/me/view-states | 自身のチャンネル閲覧状態一覧を取得
*MeApi* | [**getUserSettings**](Apis/MeApi.md#getusersettings) | **GET** /users/me/settings | ユーザー設定を取得
*MeApi* | [**linkExternalAccount**](Apis/MeApi.md#linkexternalaccount) | **POST** /users/me/ex-accounts/link | 外部ログインアカウントを紐付ける
*MeApi* | [**readChannel**](Apis/MeApi.md#readchannel) | **DELETE** /users/me/unread/{channelId} | チャンネルを既読にする
*MeApi* | [**registerFCMDevice**](Apis/MeApi.md#registerfcmdevice) | **POST** /users/me/fcm-device | FCMデバイスを登録
*MeApi* | [**removeMyStar**](Apis/MeApi.md#removemystar) | **DELETE** /users/me/stars/{channelId} | チャンネルをスターから削除します
*MeApi* | [**removeMyUserTag**](Apis/MeApi.md#removemyusertag) | **DELETE** /users/me/tags/{tagId} | 自分からタグを削除します
*MeApi* | [**revokeMySession**](Apis/MeApi.md#revokemysession) | **DELETE** /users/me/sessions/{sessionId} | セッションを無効化
*MeApi* | [**revokeMyToken**](Apis/MeApi.md#revokemytoken) | **DELETE** /users/me/tokens/{tokenId} | トークンの認可を取り消す
*MeApi* | [**setChannelSubscribeLevel**](Apis/MeApi.md#setchannelsubscribelevel) | **PUT** /users/me/subscriptions/{channelId} | チャンネル購読レベルを設定
*MeApi* | [**unlinkExternalAccount**](Apis/MeApi.md#unlinkexternalaccount) | **POST** /users/me/ex-accounts/unlink | 外部ログインアカウントの紐付けを解除
*MessageApi* | [**addMessageStamp**](Apis/MessageApi.md#addmessagestamp) | **POST** /messages/{messageId}/stamps/{stampId} | スタンプを押す
*MessageApi* | [**createPin**](Apis/MessageApi.md#createpin) | **POST** /messages/{messageId}/pin | ピン留めする
*MessageApi* | [**deleteMessage**](Apis/MessageApi.md#deletemessage) | **DELETE** /messages/{messageId} | メッセージを削除
*MessageApi* | [**editMessage**](Apis/MessageApi.md#editmessage) | **PUT** /messages/{messageId} | メッセージを編集
*MessageApi* | [**getDirectMessages**](Apis/MessageApi.md#getdirectmessages) | **GET** /users/{userId}/messages | ダイレクトメッセージのリストを取得
*MessageApi* | [**getMessage**](Apis/MessageApi.md#getmessage) | **GET** /messages/{messageId} | メッセージを取得
*MessageApi* | [**getMessageClips**](Apis/MessageApi.md#getmessageclips) | **GET** /messages/{messageId}/clips | 自分のクリップを取得
*MessageApi* | [**getMessageStamps**](Apis/MessageApi.md#getmessagestamps) | **GET** /messages/{messageId}/stamps | メッセージのスタンプリストを取得
*MessageApi* | [**getMessages**](Apis/MessageApi.md#getmessages) | **GET** /channels/{channelId}/messages | チャンネルメッセージのリストを取得
*MessageApi* | [**getPin**](Apis/MessageApi.md#getpin) | **GET** /messages/{messageId}/pin | ピン留めを取得
*MessageApi* | [**postDirectMessage**](Apis/MessageApi.md#postdirectmessage) | **POST** /users/{userId}/messages | ダイレクトメッセージを送信
*MessageApi* | [**postMessage**](Apis/MessageApi.md#postmessage) | **POST** /channels/{channelId}/messages | チャンネルにメッセージを投稿
*MessageApi* | [**removeMessageStamp**](Apis/MessageApi.md#removemessagestamp) | **DELETE** /messages/{messageId}/stamps/{stampId} | スタンプを消す
*MessageApi* | [**removePin**](Apis/MessageApi.md#removepin) | **DELETE** /messages/{messageId}/pin | ピン留めを外す
*MessageApi* | [**searchMessages**](Apis/MessageApi.md#searchmessages) | **GET** /messages | メッセージを検索
*NotificationApi* | [**editChannelSubscribers**](Apis/NotificationApi.md#editchannelsubscribers) | **PATCH** /channels/{channelId}/subscribers | チャンネルの通知購読者を編集
*NotificationApi* | [**getChannelSubscribers**](Apis/NotificationApi.md#getchannelsubscribers) | **GET** /channels/{channelId}/subscribers | チャンネルの通知購読者のリストを取得
*NotificationApi* | [**getMyChannelSubscriptions**](Apis/NotificationApi.md#getmychannelsubscriptions) | **GET** /users/me/subscriptions | 自分のチャンネル購読状態を取得
*NotificationApi* | [**getMyUnreadChannels**](Apis/NotificationApi.md#getmyunreadchannels) | **GET** /users/me/unread | 未読チャンネルを取得
*NotificationApi* | [**getMyViewStates**](Apis/NotificationApi.md#getmyviewstates) | **GET** /users/me/view-states | 自身のチャンネル閲覧状態一覧を取得
*NotificationApi* | [**readChannel**](Apis/NotificationApi.md#readchannel) | **DELETE** /users/me/unread/{channelId} | チャンネルを既読にする
*NotificationApi* | [**registerFCMDevice**](Apis/NotificationApi.md#registerfcmdevice) | **POST** /users/me/fcm-device | FCMデバイスを登録
*NotificationApi* | [**setChannelSubscribeLevel**](Apis/NotificationApi.md#setchannelsubscribelevel) | **PUT** /users/me/subscriptions/{channelId} | チャンネル購読レベルを設定
*NotificationApi* | [**setChannelSubscribers**](Apis/NotificationApi.md#setchannelsubscribers) | **PUT** /channels/{channelId}/subscribers | チャンネルの通知購読者を設定
*NotificationApi* | [**ws**](Apis/NotificationApi.md#ws) | **GET** /ws | WebSocket通知ストリームに接続します
*Oauth2Api* | [**createClient**](Apis/Oauth2Api.md#createclient) | **POST** /clients | OAuth2クライアントを作成
*Oauth2Api* | [**deleteClient**](Apis/Oauth2Api.md#deleteclient) | **DELETE** /clients/{clientId} | OAuth2クライアントを削除
*Oauth2Api* | [**editClient**](Apis/Oauth2Api.md#editclient) | **PATCH** /clients/{clientId} | OAuth2クライアント情報を変更
*Oauth2Api* | [**getClient**](Apis/Oauth2Api.md#getclient) | **GET** /clients/{clientId} | OAuth2クライアント情報を取得
*Oauth2Api* | [**getClients**](Apis/Oauth2Api.md#getclients) | **GET** /clients | OAuth2クライアントのリストを取得
*Oauth2Api* | [**getMyTokens**](Apis/Oauth2Api.md#getmytokens) | **GET** /users/me/tokens | 有効トークンのリストを取得
*Oauth2Api* | [**getOAuth2Authorize**](Apis/Oauth2Api.md#getoauth2authorize) | **GET** /oauth2/authorize | OAuth2 認可エンドポイント
*Oauth2Api* | [**postOAuth2Authorize**](Apis/Oauth2Api.md#postoauth2authorize) | **POST** /oauth2/authorize | OAuth2 認可エンドポイント
*Oauth2Api* | [**postOAuth2AuthorizeDecide**](Apis/Oauth2Api.md#postoauth2authorizedecide) | **POST** /oauth2/authorize/decide | OAuth2 認可承諾API
*Oauth2Api* | [**postOAuth2Token**](Apis/Oauth2Api.md#postoauth2token) | **POST** /oauth2/token | OAuth2 トークンエンドポイント
*Oauth2Api* | [**revokeMyToken**](Apis/Oauth2Api.md#revokemytoken) | **DELETE** /users/me/tokens/{tokenId} | トークンの認可を取り消す
*Oauth2Api* | [**revokeOAuth2Token**](Apis/Oauth2Api.md#revokeoauth2token) | **POST** /oauth2/revoke | OAuth2 トークン無効化エンドポイント
*OgpApi* | [**deleteOgpCache**](Apis/OgpApi.md#deleteogpcache) | **DELETE** /ogp/cache | OGP情報のキャッシュを削除
*OgpApi* | [**getOgp**](Apis/OgpApi.md#getogp) | **GET** /ogp | OGP情報を取得
*PinApi* | [**createPin**](Apis/PinApi.md#createpin) | **POST** /messages/{messageId}/pin | ピン留めする
*PinApi* | [**getChannelPins**](Apis/PinApi.md#getchannelpins) | **GET** /channels/{channelId}/pins | チャンネルピンのリストを取得
*PinApi* | [**getPin**](Apis/PinApi.md#getpin) | **GET** /messages/{messageId}/pin | ピン留めを取得
*PinApi* | [**removePin**](Apis/PinApi.md#removepin) | **DELETE** /messages/{messageId}/pin | ピン留めを外す
*PublicApi* | [**getPublicUserIcon**](Apis/PublicApi.md#getpublicusericon) | **GET** /public/icon/{username} | ユーザーのアイコン画像を取得
*PublicApi* | [**getServerVersion**](Apis/PublicApi.md#getserverversion) | **GET** /version | バージョンを取得
*StampApi* | [**addMessageStamp**](Apis/StampApi.md#addmessagestamp) | **POST** /messages/{messageId}/stamps/{stampId} | スタンプを押す
*StampApi* | [**changeStampImage**](Apis/StampApi.md#changestampimage) | **PUT** /stamps/{stampId}/image | スタンプ画像を変更
*StampApi* | [**createStamp**](Apis/StampApi.md#createstamp) | **POST** /stamps | スタンプを作成
*StampApi* | [**createStampPalette**](Apis/StampApi.md#createstamppalette) | **POST** /stamp-palettes | スタンプパレットを作成
*StampApi* | [**deleteStamp**](Apis/StampApi.md#deletestamp) | **DELETE** /stamps/{stampId} | スタンプを削除
*StampApi* | [**deleteStampPalette**](Apis/StampApi.md#deletestamppalette) | **DELETE** /stamp-palettes/{paletteId} | スタンプパレットを削除
*StampApi* | [**editStamp**](Apis/StampApi.md#editstamp) | **PATCH** /stamps/{stampId} | スタンプ情報を変更
*StampApi* | [**editStampPalette**](Apis/StampApi.md#editstamppalette) | **PATCH** /stamp-palettes/{paletteId} | スタンプパレットを編集
*StampApi* | [**getMessageStamps**](Apis/StampApi.md#getmessagestamps) | **GET** /messages/{messageId}/stamps | メッセージのスタンプリストを取得
*StampApi* | [**getMyStampHistory**](Apis/StampApi.md#getmystamphistory) | **GET** /users/me/stamp-history | スタンプ履歴を取得
*StampApi* | [**getStamp**](Apis/StampApi.md#getstamp) | **GET** /stamps/{stampId} | スタンプ情報を取得
*StampApi* | [**getStampImage**](Apis/StampApi.md#getstampimage) | **GET** /stamps/{stampId}/image | スタンプ画像を取得
*StampApi* | [**getStampPalette**](Apis/StampApi.md#getstamppalette) | **GET** /stamp-palettes/{paletteId} | スタンプパレットを取得
*StampApi* | [**getStampPalettes**](Apis/StampApi.md#getstamppalettes) | **GET** /stamp-palettes | スタンプパレットのリストを取得
*StampApi* | [**getStampStats**](Apis/StampApi.md#getstampstats) | **GET** /stamps/{stampId}/stats | スタンプ統計情報を取得
*StampApi* | [**getStamps**](Apis/StampApi.md#getstamps) | **GET** /stamps | スタンプリストを取得
*StampApi* | [**removeMessageStamp**](Apis/StampApi.md#removemessagestamp) | **DELETE** /messages/{messageId}/stamps/{stampId} | スタンプを消す
*StarApi* | [**addMyStar**](Apis/StarApi.md#addmystar) | **POST** /users/me/stars | チャンネルをスターに追加
*StarApi* | [**getMyStars**](Apis/StarApi.md#getmystars) | **GET** /users/me/stars | スターチャンネルリストを取得
*StarApi* | [**removeMyStar**](Apis/StarApi.md#removemystar) | **DELETE** /users/me/stars/{channelId} | チャンネルをスターから削除します
*UserApi* | [**addUserTag**](Apis/UserApi.md#addusertag) | **POST** /users/{userId}/tags | ユーザーにタグを追加
*UserApi* | [**changeUserIcon**](Apis/UserApi.md#changeusericon) | **PUT** /users/{userId}/icon | ユーザーのアイコン画像を変更します
*UserApi* | [**changeUserPassword**](Apis/UserApi.md#changeuserpassword) | **PUT** /users/{userId}/password | ユーザーのパスワードを変更
*UserApi* | [**createUser**](Apis/UserApi.md#createuser) | **POST** /users | ユーザーを登録
*UserApi* | [**editUser**](Apis/UserApi.md#edituser) | **PATCH** /users/{userId} | ユーザー情報を変更
*UserApi* | [**editUserTag**](Apis/UserApi.md#editusertag) | **PATCH** /users/{userId}/tags/{tagId} | ユーザーのタグを編集
*UserApi* | [**getDirectMessages**](Apis/UserApi.md#getdirectmessages) | **GET** /users/{userId}/messages | ダイレクトメッセージのリストを取得
*UserApi* | [**getUser**](Apis/UserApi.md#getuser) | **GET** /users/{userId} | ユーザー詳細情報を取得
*UserApi* | [**getUserDMChannel**](Apis/UserApi.md#getuserdmchannel) | **GET** /users/{userId}/dm-channel | DMチャンネル情報を取得
*UserApi* | [**getUserIcon**](Apis/UserApi.md#getusericon) | **GET** /users/{userId}/icon | ユーザーのアイコン画像を取得
*UserApi* | [**getUserStats**](Apis/UserApi.md#getuserstats) | **GET** /users/{userId}/stats | ユーザー統計情報を取得
*UserApi* | [**getUserTags**](Apis/UserApi.md#getusertags) | **GET** /users/{userId}/tags | ユーザーのタグリストを取得
*UserApi* | [**getUsers**](Apis/UserApi.md#getusers) | **GET** /users | ユーザーのリストを取得
*UserApi* | [**postDirectMessage**](Apis/UserApi.md#postdirectmessage) | **POST** /users/{userId}/messages | ダイレクトメッセージを送信
*UserApi* | [**removeUserTag**](Apis/UserApi.md#removeusertag) | **DELETE** /users/{userId}/tags/{tagId} | ユーザーからタグを削除します
*UserTagApi* | [**addMyUserTag**](Apis/UserTagApi.md#addmyusertag) | **POST** /users/me/tags | 自分にタグを追加
*UserTagApi* | [**addUserTag**](Apis/UserTagApi.md#addusertag) | **POST** /users/{userId}/tags | ユーザーにタグを追加
*UserTagApi* | [**editMyUserTag**](Apis/UserTagApi.md#editmyusertag) | **PATCH** /users/me/tags/{tagId} | 自分のタグを編集
*UserTagApi* | [**editUserTag**](Apis/UserTagApi.md#editusertag) | **PATCH** /users/{userId}/tags/{tagId} | ユーザーのタグを編集
*UserTagApi* | [**getMyUserTags**](Apis/UserTagApi.md#getmyusertags) | **GET** /users/me/tags | 自分のタグリストを取得
*UserTagApi* | [**getTag**](Apis/UserTagApi.md#gettag) | **GET** /tags/{tagId} | タグ情報を取得
*UserTagApi* | [**getUserTags**](Apis/UserTagApi.md#getusertags) | **GET** /users/{userId}/tags | ユーザーのタグリストを取得
*UserTagApi* | [**removeMyUserTag**](Apis/UserTagApi.md#removemyusertag) | **DELETE** /users/me/tags/{tagId} | 自分からタグを削除します
*UserTagApi* | [**removeUserTag**](Apis/UserTagApi.md#removeusertag) | **DELETE** /users/{userId}/tags/{tagId} | ユーザーからタグを削除します
*WebhookApi* | [**changeWebhookIcon**](Apis/WebhookApi.md#changewebhookicon) | **PUT** /webhooks/{webhookId}/icon | Webhookのアイコンを変更
*WebhookApi* | [**createWebhook**](Apis/WebhookApi.md#createwebhook) | **POST** /webhooks | Webhookを新規作成
*WebhookApi* | [**deleteWebhook**](Apis/WebhookApi.md#deletewebhook) | **DELETE** /webhooks/{webhookId} | Webhookを削除
*WebhookApi* | [**editWebhook**](Apis/WebhookApi.md#editwebhook) | **PATCH** /webhooks/{webhookId} | Webhook情報を変更
*WebhookApi* | [**getWebhook**](Apis/WebhookApi.md#getwebhook) | **GET** /webhooks/{webhookId} | Webhook情報を取得
*WebhookApi* | [**getWebhookIcon**](Apis/WebhookApi.md#getwebhookicon) | **GET** /webhooks/{webhookId}/icon | Webhookのアイコンを取得
*WebhookApi* | [**getWebhookMessages**](Apis/WebhookApi.md#getwebhookmessages) | **GET** /webhooks/{webhookId}/messages | Webhookの投稿メッセージのリストを取得
*WebhookApi* | [**getWebhooks**](Apis/WebhookApi.md#getwebhooks) | **GET** /webhooks | Webhook情報のリストを取得します
*WebhookApi* | [**postWebhook**](Apis/WebhookApi.md#postwebhook) | **POST** /webhooks/{webhookId} | Webhookを送信
*WebrtcApi* | [**getWebRTCState**](Apis/WebrtcApi.md#getwebrtcstate) | **GET** /webrtc/state | WebRTC状態を取得
*WebrtcApi* | [**postWebRTCAuthenticate**](Apis/WebrtcApi.md#postwebrtcauthenticate) | **POST** /webrtc/authenticate | Skyway用認証API

<a name="documentation-for-models"></a>
## Documentation for Models
 - [traQ/models.ActiveOAuth2Token](Models/ActiveOAuth2Token.md)
 - [traQ/models.ActivityTimelineMessage](Models/ActivityTimelineMessage.md)
 - [traQ/models.Bot](Models/Bot.md)
 - [traQ/models.BotDetail](Models/BotDetail.md)
 - [traQ/models.BotEventLog](Models/BotEventLog.md)
 - [traQ/models.BotEventResult](Models/BotEventResult.md)
 - [traQ/models.BotMode](Models/BotMode.md)
 - [traQ/models.BotState](Models/BotState.md)
 - [traQ/models.BotTokens](Models/BotTokens.md)
 - [traQ/models.BotUser](Models/BotUser.md)
 - [traQ/models.Channel](Models/Channel.md)
 - [traQ/models.ChannelEvent](Models/ChannelEvent.md)
 - [traQ/models.ChannelEventDetail](Models/ChannelEventDetail.md)
 - [traQ/models.ChannelList](Models/ChannelList.md)
 - [traQ/models.ChannelStats](Models/ChannelStats.md)
 - [traQ/models.ChannelStatsStamp](Models/ChannelStatsStamp.md)
 - [traQ/models.ChannelStatsUser](Models/ChannelStatsUser.md)
 - [traQ/models.ChannelSubscribeLevel](Models/ChannelSubscribeLevel.md)
 - [traQ/models.ChannelTopic](Models/ChannelTopic.md)
 - [traQ/models.ChannelViewState](Models/ChannelViewState.md)
 - [traQ/models.ChannelViewer](Models/ChannelViewer.md)
 - [traQ/models.ChildCreatedEvent](Models/ChildCreatedEvent.md)
 - [traQ/models.ClipFolder](Models/ClipFolder.md)
 - [traQ/models.ClippedMessage](Models/ClippedMessage.md)
 - [traQ/models.DMChannel](Models/DMChannel.md)
 - [traQ/models.ExternalProviderUser](Models/ExternalProviderUser.md)
 - [traQ/models.FileInfo](Models/FileInfo.md)
 - [traQ/models.FileInfoThumbnail](Models/FileInfoThumbnail.md)
 - [traQ/models.ForcedNotificationChangedEvent](Models/ForcedNotificationChangedEvent.md)
 - [traQ/models.GetBot200Response](Models/GetBot200Response.md)
 - [traQ/models.GetClient200Response](Models/GetClient200Response.md)
 - [traQ/models.GetNotifyCitation](Models/GetNotifyCitation.md)
 - [traQ/models.LoginSession](Models/LoginSession.md)
 - [traQ/models.Message](Models/Message.md)
 - [traQ/models.MessageClip](Models/MessageClip.md)
 - [traQ/models.MessagePin](Models/MessagePin.md)
 - [traQ/models.MessageSearchResult](Models/MessageSearchResult.md)
 - [traQ/models.MessageStamp](Models/MessageStamp.md)
 - [traQ/models.MyChannelViewState](Models/MyChannelViewState.md)
 - [traQ/models.MyUserDetail](Models/MyUserDetail.md)
 - [traQ/models.NameChangedEvent](Models/NameChangedEvent.md)
 - [traQ/models.OAuth2Client](Models/OAuth2Client.md)
 - [traQ/models.OAuth2ClientDetail](Models/OAuth2ClientDetail.md)
 - [traQ/models.OAuth2Prompt](Models/OAuth2Prompt.md)
 - [traQ/models.OAuth2ResponseType](Models/OAuth2ResponseType.md)
 - [traQ/models.OAuth2Scope](Models/OAuth2Scope.md)
 - [traQ/models.OAuth2Token](Models/OAuth2Token.md)
 - [traQ/models.Ogp](Models/Ogp.md)
 - [traQ/models.OgpMedia](Models/OgpMedia.md)
 - [traQ/models.ParentChangedEvent](Models/ParentChangedEvent.md)
 - [traQ/models.PatchBotRequest](Models/PatchBotRequest.md)
 - [traQ/models.PatchChannelRequest](Models/PatchChannelRequest.md)
 - [traQ/models.PatchChannelSubscribersRequest](Models/PatchChannelSubscribersRequest.md)
 - [traQ/models.PatchClientRequest](Models/PatchClientRequest.md)
 - [traQ/models.PatchClipFolderRequest](Models/PatchClipFolderRequest.md)
 - [traQ/models.PatchGroupMemberRequest](Models/PatchGroupMemberRequest.md)
 - [traQ/models.PatchMeRequest](Models/PatchMeRequest.md)
 - [traQ/models.PatchStampPaletteRequest](Models/PatchStampPaletteRequest.md)
 - [traQ/models.PatchStampRequest](Models/PatchStampRequest.md)
 - [traQ/models.PatchUserGroupRequest](Models/PatchUserGroupRequest.md)
 - [traQ/models.PatchUserRequest](Models/PatchUserRequest.md)
 - [traQ/models.PatchUserTagRequest](Models/PatchUserTagRequest.md)
 - [traQ/models.PatchWebhookRequest](Models/PatchWebhookRequest.md)
 - [traQ/models.Pin](Models/Pin.md)
 - [traQ/models.PinAddedEvent](Models/PinAddedEvent.md)
 - [traQ/models.PinRemovedEvent](Models/PinRemovedEvent.md)
 - [traQ/models.PostBotActionJoinRequest](Models/PostBotActionJoinRequest.md)
 - [traQ/models.PostBotActionLeaveRequest](Models/PostBotActionLeaveRequest.md)
 - [traQ/models.PostBotRequest](Models/PostBotRequest.md)
 - [traQ/models.PostChannelRequest](Models/PostChannelRequest.md)
 - [traQ/models.PostClientRequest](Models/PostClientRequest.md)
 - [traQ/models.PostClipFolderMessageRequest](Models/PostClipFolderMessageRequest.md)
 - [traQ/models.PostClipFolderRequest](Models/PostClipFolderRequest.md)
 - [traQ/models.PostLinkExternalAccount](Models/PostLinkExternalAccount.md)
 - [traQ/models.PostLoginRequest](Models/PostLoginRequest.md)
 - [traQ/models.PostMessageRequest](Models/PostMessageRequest.md)
 - [traQ/models.PostMessageStampRequest](Models/PostMessageStampRequest.md)
 - [traQ/models.PostMyFCMDeviceRequest](Models/PostMyFCMDeviceRequest.md)
 - [traQ/models.PostStampPaletteRequest](Models/PostStampPaletteRequest.md)
 - [traQ/models.PostStarRequest](Models/PostStarRequest.md)
 - [traQ/models.PostUnlinkExternalAccount](Models/PostUnlinkExternalAccount.md)
 - [traQ/models.PostUserGroupAdminRequest](Models/PostUserGroupAdminRequest.md)
 - [traQ/models.PostUserGroupRequest](Models/PostUserGroupRequest.md)
 - [traQ/models.PostUserRequest](Models/PostUserRequest.md)
 - [traQ/models.PostUserTagRequest](Models/PostUserTagRequest.md)
 - [traQ/models.PostWebRTCAuthenticateRequest](Models/PostWebRTCAuthenticateRequest.md)
 - [traQ/models.PostWebhookRequest](Models/PostWebhookRequest.md)
 - [traQ/models.PutChannelSubscribeLevelRequest](Models/PutChannelSubscribeLevelRequest.md)
 - [traQ/models.PutChannelSubscribersRequest](Models/PutChannelSubscribersRequest.md)
 - [traQ/models.PutChannelTopicRequest](Models/PutChannelTopicRequest.md)
 - [traQ/models.PutMyPasswordRequest](Models/PutMyPasswordRequest.md)
 - [traQ/models.PutNotifyCitationRequest](Models/PutNotifyCitationRequest.md)
 - [traQ/models.PutUserPasswordRequest](Models/PutUserPasswordRequest.md)
 - [traQ/models.Stamp](Models/Stamp.md)
 - [traQ/models.StampHistoryEntry](Models/StampHistoryEntry.md)
 - [traQ/models.StampPalette](Models/StampPalette.md)
 - [traQ/models.StampStats](Models/StampStats.md)
 - [traQ/models.StampWithThumbnail](Models/StampWithThumbnail.md)
 - [traQ/models.SubscribersChangedEvent](Models/SubscribersChangedEvent.md)
 - [traQ/models.Tag](Models/Tag.md)
 - [traQ/models.ThumbnailInfo](Models/ThumbnailInfo.md)
 - [traQ/models.ThumbnailType](Models/ThumbnailType.md)
 - [traQ/models.TopicChangedEvent](Models/TopicChangedEvent.md)
 - [traQ/models.UnreadChannel](Models/UnreadChannel.md)
 - [traQ/models.User](Models/User.md)
 - [traQ/models.UserAccountState](Models/UserAccountState.md)
 - [traQ/models.UserDetail](Models/UserDetail.md)
 - [traQ/models.UserGroup](Models/UserGroup.md)
 - [traQ/models.UserGroupMember](Models/UserGroupMember.md)
 - [traQ/models.UserPermission](Models/UserPermission.md)
 - [traQ/models.UserSettings](Models/UserSettings.md)
 - [traQ/models.UserStats](Models/UserStats.md)
 - [traQ/models.UserStatsStamp](Models/UserStatsStamp.md)
 - [traQ/models.UserSubscribeState](Models/UserSubscribeState.md)
 - [traQ/models.UserTag](Models/UserTag.md)
 - [traQ/models.Version](Models/Version.md)
 - [traQ/models.VersionFlags](Models/VersionFlags.md)
 - [traQ/models.VisibilityChangedEvent](Models/VisibilityChangedEvent.md)
 - [traQ/models.WebRTCAuthenticateResult](Models/WebRTCAuthenticateResult.md)
 - [traQ/models.WebRTCUserState](Models/WebRTCUserState.md)
 - [traQ/models.WebRTCUserStateSessionsInner](Models/WebRTCUserStateSessionsInner.md)
 - [traQ/models.Webhook](Models/Webhook.md)

<a name="documentation-for-authorization"></a>
## Documentation for Authorization
<a name="cookieAuth"></a>
### cookieAuth
- **Type**: API key
- **API key parameter name**: r_session
- **Location**: 
<a name="OAuth2"></a>
### OAuth2
- **Type**: OAuth
- **Flow**: accessCode
- **Authorization URL**: /api/v3/oauth2/authorize
- **Scopes**: 
  - read: 読み取りスコープ
  - write: 書き込みスコープ
  - manage_bot: bot関連読み書きスコープ
<a name="bearerAuth"></a>
### bearerAuth
- **Type**: HTTP basic authentication
