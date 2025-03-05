#!/bin/bash

# Script para eliminar archivos :Zone.Identifier en directorios y subdirectorios.

echo "🔍 Buscando archivos ':Zone.Identifier' en el directorio actual y subdirectorios..."

# Encuentra archivos con la extensión ':Zone.Identifier' y los elimina.
find . -type f -name "*:Zone.Identifier" -print -exec rm -f {} \;

# Mensaje final.
echo "✅ Archivos ':Zone.Identifier' eliminados con éxito."
