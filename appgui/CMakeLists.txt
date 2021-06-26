set(SOURCES
        GUIPoint.cpp
        GUITrace.cpp
        )

add_library(appgui ${SOURCES})

target_include_directories(appgui PUBLIC ${Qt5Widgets_INCLUDE_DIRS})
target_link_libraries(appgui PRIVATE appcore Qt5::Widgets )

target_include_directories(appgui PUBLIC
"${CMAKE_CURRENT_SOURCE_DIR}"
"${CMAKE_CURRENT_BINARY_DIR}")
