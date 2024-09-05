project(dark_networking)

file(GLOB SRC "src/*.cpp" "src/*.h")
file(GLOB PROJECT_FILES FILES ${SRC})

add_library(dark_networking ${PROJECT_FILES})
target_include_directories(dark_networking
    PUBLIC
        "include"
    PRIVATE
        "src"
)

target_link_libraries(dark_networking PUBLIC "$<LINK_LIBRARY:WHOLE_ARCHIVE,protos>")