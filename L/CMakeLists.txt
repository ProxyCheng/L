file(GLOB_RECURSE L_SOURCES
    "src/*.cpp"
    "*.cpp"
)

file(GLOB_RECURSE L_HEADERS
    "include/*.hpp"
    "include/*.h"
    "*.hpp"
    "*.h"
    ".."
)

add_library(L SHARED ${L_SOURCES} ${L_HEADERS})

target_include_directories(L PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/L
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(L PRIVATE
    L_EXPORTS
)

set_target_properties(L PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set_target_properties(L PROPERTIES
    VERSION 0.0.1
    SOVERSION 1
)