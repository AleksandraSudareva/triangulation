set(SOURCES
        Vector2.cpp
        Vertex.cpp
        Face.cpp
        Epsilon.cpp
        Halfedge.cpp
        DCEL.cpp
        Storage.cpp
        ../Session.cpp
        )

add_library(appcore ${SOURCES})

generate_export_header(appcore EXPORT_FILE_NAME core_exports.h)


target_include_directories(appcore PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_CURRENT_BINARY_DIR}")

#if (BUILD_TESTS)
#    add_executable(
#            )
#
#
#    target_link_libraries(pcbcore_test PRIVATE pcbcore gtest gtest_main)
#    gtest_discover_tests(pcbcore_test)
#endif ()
