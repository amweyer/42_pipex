#!/bin/bash

# Couleurs pour un affichage visuel amélioré
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # Pas de couleur

# Liste des commandes à tester
commands=(
	# "time ./pipex_bonus infile.txt 'sleep 4' 'sleep 1' 'sleep 3' /dev/stdout"
	# "time ./pipex_bonus infile.txt 'sleep 1' 'sleep 2' 'sleep 3' /dev/stdout"
    "./pipex_bonus infile.txt 'cat' 'grep And' 'wc -l' /dev/stdout"
    "./pipex_bonus infile.txt 'echo 'bonjour'' 'tr 'a-z' 'A-Z'' 'grep B' /dev/stdout"
    "./pipex_bonus infile.txt 'cat' 'grep And' 'tr a-z A-Z' 'wc -w' /dev/stdout"
    "./pipex_bonus infile.txt 'ls -l' 'grep ^-' 'sort -k 5' 'tail -n 3' /dev/stdout"
    "./pipex_bonus infile.txt 'grep -E (error|warning)' 'sort' 'uniq -c' 'wc -c' /dev/stdout"
    "./pipex_bonus infile.txt 'cat' 'tr -s \"1\"' 'sort' 'uniq -c' 'sort -nr' /dev/stdout"
    "./pipex_bonus infile.txt 'cat' 'grep -oE \"[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+\"' 'sort' 'uniq -c' 'sort -nr' 'head -n 5' /dev/stdout"
)

# Liste des commandes à comparer (vrai pipex)
true_pipe=(
	# "time <infile.txt sleep 4 | sleep 1 | sleep 3 > /dev/stdout"
	# "time <infile.txt sleep 1 | sleep 2 | sleep 3 > /dev/stdout"
    "<infile.txt cat | grep And | wc -l> /dev/stdout"
    "<infile.txt echo 'bonjour' | tr 'a-z' 'A-Z' | grep B> /dev/stdout"
    "<infile.txt cat | grep And | tr a-z A-Z | wc -w > /dev/stdout"
    "<infile.txt ls -l | grep ^- | sort -k 5 | tail -n 3 > /dev/stdout"
    "<infile.txt grep -E \"(error|warning)\" | sort | uniq -c | wc -c > /dev/stdout"
    "<infile.txt cat | tr -s \"1\" | sort | uniq -c | sort -nr > /dev/stdout"
    "<infile.txt cat | grep -oE \"[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+\" | sort | uniq -c | sort -nr | head -n 5 > /dev/stdout"
)

# Comparaison des sorties standard entre le vrai pipex et ton programme
echo -e "${BLUE}--- Comparaison des sorties entre vrai pipex et pipex ---${NC}"

for i in "${!commands[@]}"; do
    true_cmd="${true_pipe[$i]}"
    pipex_cmd="${commands[$i]}"

    echo -e "${YELLOW}Comparaison de la commande :${NC} $true_cmd"
    
    # Exécution du vrai pipex et capture de la sortie
    echo -e "${GREEN}Exécution du vrai pipex :${NC} $true_cmd"
    eval "$true_cmd" > true_pipe_out.txt 2> true_pipe_err.txt
    if [ $? -ne 0 ]; then
        echo -e "${RED}Erreur avec la commande vraie pipex${NC}"
    fi

    # Exécution de ton programme pipex et capture de la sortie	
    echo -e "${GREEN}Exécution de pipex :${NC} $pipex_cmd"
    eval "$pipex_cmd" > pipex_out.txt 2> pipex_err.txt
    if [ $? -ne 0 ]; then
        echo -e "${RED}Erreur avec la commande pipex${NC}"
    fi

    # Comparaison des sorties
    if diff true_pipe_out.txt pipex_out.txt > /dev/null && diff true_pipe_err.txt pipex_err.txt > /dev/null; then
        echo -e "${GREEN}Sorties identiques pour la commande :${NC} $pipex_cmd"
    else
        echo -e "${RED}Différences trouvées pour la commande :${NC} $pipex_cmd"
        echo -e "${YELLOW}Différences dans stdout:${NC}"
        echo "true one :"
        cat true_pipe_out.txt
        echo "yours :"
        cat pipex_out.txt
        echo -e "${YELLOW}Différences dans stderr:${NC}"
        echo "true one :"
        cat true_pipe_err.txt
        echo "yours :"
        cat pipex_err.txt
    fi

    echo -e "${BLUE}--------------------------------------------------${NC}"
done

# Tests avec valgrind uniquement pour ton programme pipex
echo -e "${BLUE}--- Tests avec Valgrind sur pipex ---${NC}"
for cmd in "${commands[@]}"; do
    valgrind_cmd="valgrind --trace-children=yes --track-fds=all --leak-check=full -q $cmd"
    cmd1=$(echo "$cmd" | awk '{print $3}')
    cmd2=$(echo "$cmd" | awk '{print $4}')
    echo -e "${YELLOW}Valgrind pour pipex:${NC} $valgrind_cmd"

    # Exécuter Valgrind et afficher la sortie en direct
    eval "$valgrind_cmd"
    if [ $? -ne 0 ]; then
        echo -e "${RED}Valgrind a enregistré un code de retour d'erreur.${NC}"
    fi
done

# Tests avec funcheck uniquement pour ton programme pipex
echo -e "${BLUE}--- Tests avec Funcheck sur pipex_bonus ---${NC}"
for cmd in "${commands[@]}"; do
    funcheck_cmd="funcheck $cmd"
    cmd1=$(echo "$cmd" | awk '{print $3}')
    cmd2=$(echo "$cmd" | awk '{print $4}')
    echo -e "${YELLOW}Funcheck pour pipex_bonus:${NC} $funcheck_cmd"
    eval "$funcheck_cmd"
    if [ $? -ne 0 ]; then
        echo -e "${RED}Funcheck a échoué.${NC}"
        continue
    fi
done

# Nettoyage des fichiers temporaires
cd ..
rm -f true_pipe_out.txt pipex_out.txt true_pipe_err.txt pipex_err.txt