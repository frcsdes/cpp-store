set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

set(SOURCES
    main.cpp
    mainwindow.cpp
    )

add_executable(store ${SOURCES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

find_package(Qt5Widgets CONFIG REQUIRED)
target_link_libraries(store Qt5::Widgets)
