set(CMAKE_CXX_STANDARD 17)

set(DEMO demo)
set(SOURCES
    main.cpp
    mystore.cpp
    mainwindow.cpp
    )

add_executable(${DEMO} ${SOURCES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

find_package(Qt5Widgets 5.7 CONFIG REQUIRED)
target_link_libraries(${DEMO} Qt5::Widgets)
