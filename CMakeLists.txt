cmake_minimum_required(VERSION 3.12)
project(aria2 VERSION 1.37.0 LANGUAGES CXX C)

# Set C++ standard (using C++14 instead of C++11 for better performance/features)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags for optimization
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -DNDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3 -march=native -DNDEBUG")

# Add debug symbols to Debug build
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DDEBUG")

# Check for platform-specific settings
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
    # Avoid deprecation warnings on macOS
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

# Find required dependencies
find_package(Threads REQUIRED)
find_package(ZLIB REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(LibXml2 REQUIRED)

# Optional packages with appropriate fallbacks
find_package(LibCares)
find_package(SQLite3)
find_package(LibSSH2)
find_package(GCrypt)
find_package(GMP)
find_package(LibGnuTLS)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${ZLIB_INCLUDE_DIRS}
    ${OPENSSL_INCLUDE_DIR}
    ${LIBXML2_INCLUDE_DIR}
)

# Find all source files
file(GLOB_RECURSE ARIA2_SRCS 
    "src/*.cc"
    "src/*.c"
    "src/*.cpp"
)

# Create the main executable
add_executable(aria2c ${ARIA2_SRCS})

# Set target properties for better optimization
set_target_properties(aria2c PROPERTIES
    INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE
    POSITION_INDEPENDENT_CODE TRUE
)

# Link libraries
target_link_libraries(aria2c
    PRIVATE
    Threads::Threads
    ${ZLIB_LIBRARIES}
    ${OPENSSL_LIBRARIES}
    ${LIBXML2_LIBRARIES}
)

# Add optional libraries if found
if(LibCares_FOUND)
    target_compile_definitions(aria2c PRIVATE HAVE_LIBCARES)
    target_include_directories(aria2c PRIVATE ${LIBCARES_INCLUDE_DIRS})
    target_link_libraries(aria2c PRIVATE ${LIBCARES_LIBRARIES})
endif()

if(SQLite3_FOUND)
    target_compile_definitions(aria2c PRIVATE HAVE_SQLITE3)
    target_include_directories(aria2c PRIVATE ${SQLITE3_INCLUDE_DIRS})
    target_link_libraries(aria2c PRIVATE ${SQLITE3_LIBRARIES})
endif()

if(LibSSH2_FOUND)
    target_compile_definitions(aria2c PRIVATE HAVE_LIBSSH2)
    target_include_directories(aria2c PRIVATE ${LIBSSH2_INCLUDE_DIRS})
    target_link_libraries(aria2c PRIVATE ${LIBSSH2_LIBRARIES})
endif()

if(GCrypt_FOUND)
    target_compile_definitions(aria2c PRIVATE HAVE_LIBGCRYPT)
    target_include_directories(aria2c PRIVATE ${GCRYPT_INCLUDE_DIRS})
    target_link_libraries(aria2c PRIVATE ${GCRYPT_LIBRARIES})
endif()

if(GMP_FOUND)
    target_compile_definitions(aria2c PRIVATE HAVE_LIBGMP)
    target_include_directories(aria2c PRIVATE ${GMP_INCLUDE_DIRS})
    target_link_libraries(aria2c PRIVATE ${GMP_LIBRARIES})
endif()

if(LibGnuTLS_FOUND)
    target_compile_definitions(aria2c PRIVATE HAVE_LIBGNUTLS)
    target_include_directories(aria2c PRIVATE ${GNUTLS_INCLUDE_DIRS})
    target_link_libraries(aria2c PRIVATE ${GNUTLS_LIBRARIES})
endif()

# Installation rules
install(TARGETS aria2c DESTINATION bin)
install(FILES doc/man/aria2c.1 DESTINATION share/man/man1 OPTIONAL)

# Display configuration summary
message(STATUS "")
message(STATUS "aria2 ${PROJECT_VERSION} configuration summary:")
message(STATUS "")
message(STATUS "Installation prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "CXX Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "CXX flags: ${CMAKE_CXX_FLAGS}")
message(STATUS "")
