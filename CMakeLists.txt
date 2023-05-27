add_library(traQApi)
target_include_directories(traQApi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(traQApi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/traQ/Helper.cpp)

target_link_libraries(traQApi PRIVATE Drogon::Drogon)
