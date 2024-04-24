// Header traQ v3

#ifndef TRAQ__CLIENT_H
#define TRAQ__CLIENT_H

#include <traQ/apis/ActivityApi.h>
#include <traQ/apis/AuthenticationApi.h>
#include <traQ/apis/BotApi.h>
#include <traQ/apis/ChannelApi.h>
#include <traQ/apis/ClipApi.h>
#include <traQ/apis/FileApi.h>
#include <traQ/apis/GroupApi.h>
#include <traQ/apis/MeApi.h>
#include <traQ/apis/MessageApi.h>
#include <traQ/apis/NotificationApi.h>
#include <traQ/apis/Oauth2Api.h>
#include <traQ/apis/OgpApi.h>
#include <traQ/apis/PinApi.h>
#include <traQ/apis/PublicApi.h>
#include <traQ/apis/StampApi.h>
#include <traQ/apis/StarApi.h>
#include <traQ/apis/UserApi.h>
#include <traQ/apis/UserTagApi.h>
#include <traQ/apis/WebhookApi.h>
#include <traQ/apis/WebrtcApi.h>
#include <traQ/models/ActiveOAuth2Token.h>
#include <traQ/models/ActivityTimelineMessage.h>
#include <traQ/models/Bot.h>
#include <traQ/models/BotDetail.h>
#include <traQ/models/BotEventLog.h>
#include <traQ/models/BotEventResult.h>
#include <traQ/models/BotMode.h>
#include <traQ/models/BotState.h>
#include <traQ/models/BotTokens.h>
#include <traQ/models/BotUser.h>
#include <traQ/models/Channel.h>
#include <traQ/models/ChannelEvent.h>
#include <traQ/models/ChannelEventDetail.h>
#include <traQ/models/ChannelList.h>
#include <traQ/models/ChannelStats.h>
#include <traQ/models/ChannelStatsStamp.h>
#include <traQ/models/ChannelStatsUser.h>
#include <traQ/models/ChannelSubscribeLevel.h>
#include <traQ/models/ChannelTopic.h>
#include <traQ/models/ChannelViewState.h>
#include <traQ/models/ChannelViewer.h>
#include <traQ/models/ChildCreatedEvent.h>
#include <traQ/models/ClipFolder.h>
#include <traQ/models/ClippedMessage.h>
#include <traQ/models/DMChannel.h>
#include <traQ/models/ExternalProviderUser.h>
#include <traQ/models/FileInfo.h>
#include <traQ/models/FileInfoThumbnail.h>
#include <traQ/models/ForcedNotificationChangedEvent.h>
#include <traQ/models/GetBot200Response.h>
#include <traQ/models/GetClient200Response.h>
#include <traQ/models/GetNotifyCitation.h>
#include <traQ/models/LoginSession.h>
#include <traQ/models/Message.h>
#include <traQ/models/MessageClip.h>
#include <traQ/models/MessagePin.h>
#include <traQ/models/MessageSearchResult.h>
#include <traQ/models/MessageStamp.h>
#include <traQ/models/MyChannelViewState.h>
#include <traQ/models/MyUserDetail.h>
#include <traQ/models/NameChangedEvent.h>
#include <traQ/models/OAuth2Client.h>
#include <traQ/models/OAuth2ClientDetail.h>
#include <traQ/models/OAuth2Prompt.h>
#include <traQ/models/OAuth2ResponseType.h>
#include <traQ/models/OAuth2Scope.h>
#include <traQ/models/OAuth2Token.h>
#include <traQ/models/Ogp.h>
#include <traQ/models/OgpMedia.h>
#include <traQ/models/ParentChangedEvent.h>
#include <traQ/models/PatchBotRequest.h>
#include <traQ/models/PatchChannelRequest.h>
#include <traQ/models/PatchChannelSubscribersRequest.h>
#include <traQ/models/PatchClientRequest.h>
#include <traQ/models/PatchClipFolderRequest.h>
#include <traQ/models/PatchGroupMemberRequest.h>
#include <traQ/models/PatchMeRequest.h>
#include <traQ/models/PatchStampPaletteRequest.h>
#include <traQ/models/PatchStampRequest.h>
#include <traQ/models/PatchUserGroupRequest.h>
#include <traQ/models/PatchUserRequest.h>
#include <traQ/models/PatchUserTagRequest.h>
#include <traQ/models/PatchWebhookRequest.h>
#include <traQ/models/Pin.h>
#include <traQ/models/PinAddedEvent.h>
#include <traQ/models/PinRemovedEvent.h>
#include <traQ/models/PostBotActionJoinRequest.h>
#include <traQ/models/PostBotActionLeaveRequest.h>
#include <traQ/models/PostBotRequest.h>
#include <traQ/models/PostChannelRequest.h>
#include <traQ/models/PostClientRequest.h>
#include <traQ/models/PostClipFolderMessageRequest.h>
#include <traQ/models/PostClipFolderRequest.h>
#include <traQ/models/PostLinkExternalAccount.h>
#include <traQ/models/PostLoginRequest.h>
#include <traQ/models/PostMessageRequest.h>
#include <traQ/models/PostMessageStampRequest.h>
#include <traQ/models/PostMyFCMDeviceRequest.h>
#include <traQ/models/PostStampPaletteRequest.h>
#include <traQ/models/PostStarRequest.h>
#include <traQ/models/PostUnlinkExternalAccount.h>
#include <traQ/models/PostUserGroupAdminRequest.h>
#include <traQ/models/PostUserGroupRequest.h>
#include <traQ/models/PostUserRequest.h>
#include <traQ/models/PostUserTagRequest.h>
#include <traQ/models/PostWebRTCAuthenticateRequest.h>
#include <traQ/models/PostWebhookRequest.h>
#include <traQ/models/PutChannelSubscribeLevelRequest.h>
#include <traQ/models/PutChannelSubscribersRequest.h>
#include <traQ/models/PutChannelTopicRequest.h>
#include <traQ/models/PutMyPasswordRequest.h>
#include <traQ/models/PutNotifyCitationRequest.h>
#include <traQ/models/PutUserPasswordRequest.h>
#include <traQ/models/Stamp.h>
#include <traQ/models/StampHistoryEntry.h>
#include <traQ/models/StampPalette.h>
#include <traQ/models/StampStats.h>
#include <traQ/models/StampWithThumbnail.h>
#include <traQ/models/SubscribersChangedEvent.h>
#include <traQ/models/Tag.h>
#include <traQ/models/ThumbnailInfo.h>
#include <traQ/models/ThumbnailType.h>
#include <traQ/models/TopicChangedEvent.h>
#include <traQ/models/UnreadChannel.h>
#include <traQ/models/User.h>
#include <traQ/models/UserAccountState.h>
#include <traQ/models/UserDetail.h>
#include <traQ/models/UserGroup.h>
#include <traQ/models/UserGroupMember.h>
#include <traQ/models/UserPermission.h>
#include <traQ/models/UserSettings.h>
#include <traQ/models/UserStats.h>
#include <traQ/models/UserStatsStamp.h>
#include <traQ/models/UserSubscribeState.h>
#include <traQ/models/UserTag.h>
#include <traQ/models/Version.h>
#include <traQ/models/VersionFlags.h>
#include <traQ/models/VisibilityChangedEvent.h>
#include <traQ/models/WebRTCAuthenticateResult.h>
#include <traQ/models/WebRTCUserState.h>
#include <traQ/models/WebRTCUserStateSessionsInner.h>
#include <traQ/models/Webhook.h>

#endif