cmake_minimum_required(VERSION 3.19)
project(Adbms LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Adbms
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    lexer.h lexer.cpp
    parser.h parser.cpp
    statement.h
    exception.h
    dmlparser.h
    dmlparser.cpp
    ddlparser.h
    ddlparser.cpp
    executor.h executor.cpp
    login.h login.cpp login.ui
    database.h database.cpp
    table.h table.cpp
    user.h user.cpp # 添加的文件
)

target_link_libraries(Adbms
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Adbms
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Adbms
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
