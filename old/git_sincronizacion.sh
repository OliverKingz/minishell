#!/bin/bash

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
MAGENTA='\033[0;35m'
BLUE='\033[0;34m'
RESET='\033[0m' # No color

#CON SINCRONIZACION DE REPO LOCAL Y REMOTA

#Guarda tus cambios localmente:
git stash

#Obtén los últimos cambios de la rama remota:
git pull --rebase origin main

#Aplica de nuevo mis cambios:
git stash pop

git status

#Confirma los cambios y envíalos al repositorio remoto:
git add .
read -p "Introduce el comentario para el commit: " commit_message
git commit -m "$commit_message"
git push origin main

echo -e "${MAGENTA}ultima revision de pendientes: status${RESET}" 
git status