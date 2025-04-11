#!/bin/bash

# Répertoire cible pour les fichiers source
SRC_DIR="./src"

# Vérifier si le répertoire src existe
if [ ! -d "$SRC_DIR" ]; then
    echo "Création du répertoire $SRC_DIR..."
    mkdir -p "$SRC_DIR"
fi

# Liste des fichiers à créer
FILE_NAMES=("main" "utils" "network" "download" "logger")

# Créer les fichiers *.cpp et *.h
for FILE in "${FILE_NAMES[@]}"; do
    CPP_FILE="$SRC_DIR/$FILE.cpp"
    HEADER_FILE="$SRC_DIR/$FILE.h"

    # Créer le fichier .cpp si non existant
    if [ ! -f "$CPP_FILE" ]; then
        echo "Création de $CPP_FILE..."
        cat << 'EOL' > "$CPP_FILE"
#include "$FILE.h"

int main() {
    // TODO: Implémentation de $FILE
    return 0;
}
EOL
    else
        echo "$CPP_FILE existe déjà."
    fi

    # Créer le fichier .h si non existant
    if [ ! -f "$HEADER_FILE" ]; then
        echo "Création de $HEADER_FILE..."
        cat << 'EOL' > "$HEADER_FILE"
#ifndef ${FILE^^}_H
#define ${FILE^^}_H

// TODO: Déclarations pour $FILE

#endif // ${FILE^^}_H
EOL
    else
        echo "$HEADER_FILE existe déjà."
    fi
done

echo "Tous les fichiers ont été créés dans $SRC_DIR."
