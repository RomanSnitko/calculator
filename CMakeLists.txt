cmake_minimum_required(VERSION 3.16)

project(calculator)

set(CMAKE_CXX_STANDARD 17)

# Ищем Qt6 и модуль Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Файлы проекта
set(SOURCES
    main.cpp
    mainwindow.cpp
)

set(HEADERS
    mainwindow.h
)

set(UI
    mainwindow.ui
)

# Генерация кода из .ui
qt_wrap_ui(UI_HEADERS ${UI})

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UI_HEADERS})

# Линкуем Qt6::Widgets
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
