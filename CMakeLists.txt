cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

project("HS-Alexstrasza-Rogue-Cal")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_definitions(-DWindows)
    add_executable(
            ${PROJECT_NAME}
            "source/basic.cpp" "source/basic.h"
            "source/offer.cpp" "source/offer.h"
            "source/trans.cpp" "source/trans.h"
            "source/output.cpp" "source/output.h"
            "source/formula.cpp" "source/formula.h"
            "source/solve_refresh.cpp" "source/solve_refresh.h"
            "source/gen.cpp" "source/gen.h"
            "source/pre.cpp" "source/pre.h"
            "source/deck.h" "source/deck.cpp"
            "source/auto.h" "source/auto.cpp"
            "source/ui.cpp" "source/ui.h"
            "source/adapt.cpp" "source/adapt.h"
            "source/HSSPRCAL.cpp"
            source/language.cpp
            source/language.h
    )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_definitions(-DLinux)
    add_executable(
            ${PROJECT_NAME}
            "source/basic.cpp" "source/basic.h"
            "source/offer.cpp" "source/offer.h"
            "source/trans.cpp" "source/trans.h"
            "source/output.cpp" "source/output.h"
            "source/formula.cpp" "source/formula.h"
            "source/solve.cpp" "source/solve.h"
            "source/gen.cpp" "source/gen.h"
            "source/pre.cpp" "source/pre.h"
            "source/HSSPRCAL.cpp"
            source/language.cpp
            source/language.h
    )
endif ()

target_include_directories(${PROJECT_NAME}
        PRIVATE source
        PRIVATE ./include
)
target_link_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/lib")
target_link_libraries(${PROJECT_NAME} graphics gdi32 gdiplus)

