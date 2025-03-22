#!/bin/bash

# Inicia una nueva sesión de tmux llamada "my_session"
tmux new-session -d -s my_session

# Divide la ventana en dos paneles (uno a la izquierda y otro a la derecha)
tmux split-window -h
tmux send-keys -t my_session:0.0 'bash' C-m
tmux send-keys -t my_session:0.1 'make' C-m
tmux send-keys -t my_session:0.1 './minishell' C-m
tmux send-keys -t my_session:0.0 'clear' C-m
tmux send-keys -t my_session:0.1 'clear' C-m
# Sincroniza los paneles para que ambos reciban las mismas entradas
tmux setw synchronize-panes on

# Adjunta la sesión de tmux para que la puedas ver en la terminal
tmux attach-session -t my_session
