set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

set(SOURCES
    main.cpp
    store.cpp
    mainwindow.cpp
    )

add_executable(store ${SOURCES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

find_package(Qt5Widgets 5.7 CONFIG REQUIRED)
target_link_libraries(store Qt5::Widgets)
