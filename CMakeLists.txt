cmake_minimum_required(VERSION 3.30)

project(craftgame)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

file(GLOB INCLUDES include/*.h include/*.cpp)
file(GLOB SOURCES src/*.h src/*.cpp)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#add_executable(${PROJECT_NAME} WIN32 src/main.cpp ${GLAD_SOURCES} ${INCLUDES} ${SOURCES})
add_executable(${PROJECT_NAME} src/main.cpp ${INCLUDES} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

