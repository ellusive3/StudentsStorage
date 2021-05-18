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

find_package(PostgreSQL REQUIRED)
IF (PostgreSQL_FOUND)
	MESSAGE("FOUND PostgreSQL!")
ELSE()
	MESSAGE("PostgreSQL NOT FOUND!")
ENDIF()


target_include_directories(${TARGET} PRIVATE
    ./include
)

IF (WIN32)
target_link_libraries(${TARGET} PRIVATE
	libpq
)
ELSE()
target_compile_options(${TARGET} PRIVATE
)
ENDIF()
