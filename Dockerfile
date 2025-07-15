# Utilise Ubuntu comme base
FROM ubuntu:22.04

# Met à jour les paquets et installe Valgrind, g++ et GDB
RUN apt update && apt install -y valgrind build-essential gdb

# Dossier de travail
WORKDIR /pipex_github

# Lancer un shell interactif par défaut
CMD ["/bin/bash"]
