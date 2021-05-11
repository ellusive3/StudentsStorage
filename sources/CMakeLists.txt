SET(TARGET StudentsStorageMain)

add_executable(${TARGET}
    ./stdafx.cpp
    ./main.cpp
    ./App.cpp
    ./User.cpp
    ./City.cpp
    ./Event.cpp
    ./Object.cpp
    ./Theme.cpp
    ./Link.cpp
    ./State.cpp
    ./Attribute.cpp
    ./Row.cpp
    ./Gui.cpp
    ./DbManager.cpp
)

MESSAGE("TOOLSET IS " ${MSVC_TOOLSET_VERSION})


target_include_directories(${TARGET} PRIVATE
    ./include
)

IF (WIN32)
target_link_libraries(${TARGET} PRIVATE
)
ELSE()
target_compile_options(${TARGET} PRIVATE
)
ENDIF()
