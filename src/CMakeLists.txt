# Version minimale requise de CMake
cmake_minimum_required(VERSION 3.10)

# Nom du projet et langage utilisé
project(aria2 LANGUAGES CXX)

# Ajouter les fichiers source
file(GLOB_RECURSE SOURCES "*.cpp" "*.h")

# Créer un exécutable avec les fichiers source
add_executable(aria2 ${SOURCES})

# Lier les bibliothèques nécessaires
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)
target_link_libraries(aria2 OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB)
