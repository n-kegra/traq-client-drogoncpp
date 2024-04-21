target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/Helper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/ActivityApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/AuthenticationApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/BotApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/ChannelApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/ClipApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/FileApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/GroupApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/MeApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/MessageApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/NotificationApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/Oauth2Api.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/OgpApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/PinApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/PublicApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/StampApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/StarApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/UserApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/UserTagApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/WebhookApi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/traQ/apis/WebrtcApi.cpp
)
