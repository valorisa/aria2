#!/bin/bash

# Répertoire source
SRC_DIR="./src"
CMAKE_FILE="./CMakeLists.txt"

# Étape 1 : Corriger les inclusions dans les fichiers *.cpp
echo "Correction des inclusions dans les fichiers source..."
for FILE in "$SRC_DIR"/*.cpp; do
    BASENAME=$(basename "$FILE" .cpp)
    HEADER_FILE="${SRC_DIR}/${BASENAME}.h"
    if [ -f "$HEADER_FILE" ]; then
        sed -i '' "s|#include \"\$FILE.h\"|#include \"${BASENAME}.h\"|g" "$FILE"
        echo "Corrigé : $FILE"
    else
        echo "Aucun fichier en-tête trouvé pour $FILE. Ignoré."
    fi
done

# Étape 2 : Corriger timespec.h pour éviter les redéfinitions
TIMESPEC_FILE="${SRC_DIR}/timespec.h"
if [ -f "$TIMESPEC_FILE" ]; then
    echo "Modification de $TIMESPEC_FILE pour éviter les redéfinitions..."
    sed -i '' '/struct timespec {/i\
#ifndef _STRUCT_TIMESPEC
' "$TIMESPEC_FILE"
    sed -i '' '/};/a\
#endif
' "$TIMESPEC_FILE"
    echo "timespec.h corrigé."
else
    echo "$TIMESPEC_FILE introuvable. Ignoré."
fi

# Étape 3 : Ajouter le support de C++11 dans CMakeLists.txt
echo "Ajout du support de C++11 dans $CMAKE_FILE..."
if grep -q "set(CMAKE_CXX_STANDARD" "$CMAKE_FILE"; then
    echo "Le standard C++ est déjà configuré dans $CMAKE_FILE."
else
    echo -e "\n# Activer le support de C++11" >> "$CMAKE_FILE"
    echo "set(CMAKE_CXX_STANDARD 11)" >> "$CMAKE_FILE"
    echo "set(CMAKE_CXX_STANDARD_REQUIRED ON)" >> "$CMAKE_FILE"
    echo "Support de C++11 ajouté."
fi

echo "Toutes les corrections ont été appliquées avec succès."
