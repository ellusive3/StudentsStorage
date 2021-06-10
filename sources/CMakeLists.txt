SET(TARGET StudentsStorageMain)

add_executable(${TARGET}
    ${CMAKE_CURRENT_SOURCE_DIR}/stdafx.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/App.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/User.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/City.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Event.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Object.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Theme.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Link.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/State.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Attribute.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Row.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Gui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DbManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/AddUserDialog.cpp
)

MESSAGE("TOOLSET IS " ${MSVC_TOOLSET_VERSION})
SET(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH C:/Qt/Qt5.9.9/5.9.9/msvc2017_64/lib/cmake/Qt5)


find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

IF (NOT Qt5_FOUND)
	MESSAGE(FATAL_ERROR "Qt5 package not found! Please install Qt5 or place headers and libs in certainly dirs this project")
ELSE()
	MESSAGE("Qt5 package has been found")
ENDIF()

target_include_directories(${TARGET} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
)

IF (WIN32)
target_link_libraries(${TARGET} PUBLIC Qt5::Widgets)
target_link_libraries(${TARGET} PRIVATE
	libpq
	user32
	version
	oleaut32
	ole32
	sqlapis
	sqlapius
)
ELSE()
target_compile_options(${TARGET} PRIVATE
)
ENDIF()

#add_custom_command(TARGET libpq POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:libpq> ${targetfile}
#)
