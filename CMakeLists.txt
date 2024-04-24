cmake_minimum_required(VERSION 3.5)
project(traQApi)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Helper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/ActivityApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/AuthenticationApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/BotApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/ChannelApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/ClipApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/FileApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/GroupApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/MeApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/MessageApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/NotificationApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/Oauth2Api.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/OgpApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/PinApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/PublicApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/StampApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/StarApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/UserApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/UserTagApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/WebhookApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apis/WebrtcApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ActiveOAuth2Token.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ActivityTimelineMessage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/Bot.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/BotDetail.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/BotEventLog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/BotEventResult.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/BotMode.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/BotState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/BotTokens.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/BotUser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/Channel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChannelEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChannelEventDetail.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChannelList.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChannelStats.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChannelStatsStamp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChannelStatsUser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChannelSubscribeLevel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChannelTopic.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChannelViewState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChannelViewer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ChildCreatedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ClipFolder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ClippedMessage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/DMChannel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ExternalProviderUser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/FileInfo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/FileInfoThumbnail.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ForcedNotificationChangedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/GetBot200Response.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/GetClient200Response.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/GetNotifyCitation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/LoginSession.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/Message.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/MessageClip.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/MessagePin.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/MessageSearchResult.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/MessageStamp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/MyChannelViewState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/MyUserDetail.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/NameChangedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/OAuth2Client.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/OAuth2ClientDetail.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/OAuth2Prompt.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/OAuth2ResponseType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/OAuth2Scope.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/OAuth2Token.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/Ogp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/OgpMedia.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ParentChangedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchBotRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchChannelRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchChannelSubscribersRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchClientRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchClipFolderRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchGroupMemberRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchMeRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchStampPaletteRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchStampRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchUserGroupRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchUserRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchUserTagRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PatchWebhookRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/Pin.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PinAddedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PinRemovedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostBotActionJoinRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostBotActionLeaveRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostBotRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostChannelRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostClientRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostClipFolderMessageRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostClipFolderRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostLinkExternalAccount.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostLoginRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostMessageRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostMessageStampRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostMyFCMDeviceRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostStampPaletteRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostStarRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostUnlinkExternalAccount.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostUserGroupAdminRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostUserGroupRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostUserRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostUserTagRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostWebRTCAuthenticateRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PostWebhookRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PutChannelSubscribeLevelRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PutChannelSubscribersRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PutChannelTopicRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PutMyPasswordRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PutNotifyCitationRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/PutUserPasswordRequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/Stamp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/StampHistoryEntry.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/StampPalette.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/StampStats.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/StampWithThumbnail.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/SubscribersChangedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/Tag.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ThumbnailInfo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/ThumbnailType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/TopicChangedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UnreadChannel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/User.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UserAccountState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UserDetail.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UserGroup.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UserGroupMember.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UserPermission.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UserSettings.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UserStats.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UserStatsStamp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UserSubscribeState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/UserTag.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/Version.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/VersionFlags.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/VisibilityChangedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/WebRTCAuthenticateResult.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/WebRTCUserState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/WebRTCUserStateSessionsInner.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models/Webhook.cpp
)

find_package(Drogon CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)

set(PACKAGE_NAME ${PROJECT_NAME})
# define includes
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# install binary
install(TARGETS ${PROJECT_NAME} EXPORT ${PACKAGE_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# install headers
install(DIRECTORY include/ DESTINATION include)

# install config
install(EXPORT ${PACKAGE_NAME}Targets
    FILE ${PACKAGE_NAME}Config.cmake
    NAMESPACE ${PACKAGE_NAME}::
    DESTINATION lib/cmake/${PACKAGE_NAME}
)
