set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/store/store.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/store/storeinteger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/store/storestring.cpp
    )

add_executable(store ${SOURCES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

find_package(Qt5Widgets CONFIG REQUIRED)
target_link_libraries(store Qt5::Widgets)
