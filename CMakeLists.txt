cmake_minimum_required(VERSION 3.16)

<<<<<<< HEAD
project(protoc-deneme VERSION 0.1 LANGUAGES CXX)
=======
project(Client VERSION 0.1 LANGUAGES CXX)
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Protobuf Network Concurrent )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Protobuf Network Concurrent )

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
<<<<<<< HEAD
qt_add_executable(protoc-deneme
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        server.h server.cpp

    )

    qt_add_protobuf(protobuf_messages
        PROTO_FILES
            message.proto
    )

=======
    qt_add_executable(Client
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            testclient.h testclient.cpp
            )

    qt_add_protobuf(protobuf_messages
        PROTO_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/message.proto
    )




>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
target_sources(protobuf_messages
  PRIVATE


)

# Define target properties for Android with Qt 6 as:
<<<<<<< HEAD
#    set_property(TARGET protoc-deneme APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
=======
#    set_property(TARGET Client APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
<<<<<<< HEAD
        add_library(protoc-deneme SHARED
=======
        add_library(Client SHARED
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
<<<<<<< HEAD
        add_executable(protoc-deneme
=======
        add_executable(Client
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
            ${PROJECT_SOURCES}
        )
    endif()
endif()

<<<<<<< HEAD
target_link_libraries(protoc-deneme PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Protobuf protobuf_messages Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Concurrent )
=======
target_link_libraries(Client PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Protobuf protobuf_messages Qt${QT_VERSION_MAJOR}::Network Qt${QT_VERSION_MAJOR}::Concurrent )
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
<<<<<<< HEAD
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.protoc-deneme)
endif()
set_target_properties(protoc-deneme PROPERTIES
=======
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Client)
endif()
set_target_properties(Client PROPERTIES
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
<<<<<<< HEAD
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS protoc-deneme
=======
    WIN32_EXECUTABLE FALSE
)

include(GNUInstallDirs)
install(TARGETS Client
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
<<<<<<< HEAD
    qt_finalize_executable(protoc-deneme)
=======
    qt_finalize_executable(Client)
>>>>>>> 8e0bf03bf710e49b8dd4d040a9e8952fb22c9c2a
endif()
