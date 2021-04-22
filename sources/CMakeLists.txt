SET(TARGET StudentsStorageMain)

add_executable(${TARGET}
    ./stdafx.cpp
    ./App.cpp
    ./User.cpp
    ./City.cpp
    ./Event.cpp
)

target_include_directories(${TARGET} PRIVATE
    ./include
)

IF (WIN32)
target_link_libraries(${TARGET} PRIVATE
    stdlib
)

target_compile_options(${TARGET} PRIVATE
    -std=c++11
    -stdlib=libc++
    -g3
)
ENDIF()
