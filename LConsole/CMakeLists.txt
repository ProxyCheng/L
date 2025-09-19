file(GLOB_RECURSE LCONSOLE_SOURCES
    "src/*.cpp"
    "*.cpp"
)

file(GLOB_RECURSE LCONSOLE_HEADERS
    "include/*.hpp"
    "include/*.h"
    "*.hpp"
    "*.h"
    # ${ROOT_DIR}
)

add_executable(LConsole ${LCONSOLE_SOURCES} ${LCONSOLE_HEADERS})

target_link_libraries(LConsole PRIVATE L)

target_include_directories(LConsole PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(LConsole PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)