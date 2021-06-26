cmake_minimum_required (VERSION 3.14)

project (hello_world VERSION 0.0.1 LANGUAGES C CXX)
#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lstdc++")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set (CMAKE_PREFIX_PATH "C:/msys64/mingw64/lib/cmake/Qt5")
#
##option (DJSONCPP_WITH_CMAKE_PACKAGE "Use jsoncpp" ON)
#
##option(BUILD_TESTS "Build the tests" ON)
##option(BUILD_SCRIPTS "Build the scripts" ON)
##option(BUILD_GUI "Build GUI" ON)
#
set (Qt5Core_DIR "C:/msys64/mingw64/lib/cmake/Qt5Core")
set (Qt5_DIR "C:/msys64/mingw64/lib/cmake/Qt5")
##set(QT_QMAKE_EXECUTABLE "C:/msys64/mingw64/bin/qmake.exe")
#set (jsoncpp_DIR "C:/msys64/mingw64/lib/cmake/jsoncpp")

find_package(Qt5Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)

include(GenerateExportHeader)
#
#add_executable(${PROJECT_NAME} main.cpp)

#add_subdirectory(appcore)
#add_subdirectory(appgui)
#
if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)
#
#target_include_directories(PUBLIC ${Qt5Widgets_INCLUDE_DIRS})
#
add_executable(hello_world main.cpp
        appcore/Vector2.cpp
        appcore/Vertex.cpp
        appcore/Face.cpp
        appcore/Epsilon.cpp
        appcore/Halfedge.cpp
        appcore/DCEL.cpp
        appcore/Storage.cpp
        appcore/ActionsProcessor.cpp
        appcore/SelectionProcessor.cpp
        Session.cpp
        appgui/GUITrace.cpp
        appgui/GUIPoint.cpp
        appgui/GraphicsScene.cpp
        appgui/GraphicsView.cpp
        appgui/MainWindow.cpp
        appgui/Widgets/ActionsLayout.cpp
        appgui/Widgets/MouseCoords.cpp
        )

target_link_libraries(hello_world Qt5::Widgets)
