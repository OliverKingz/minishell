#!/bin/bash

# Start a new tmux session named "my_session"
tmux new-session -d -s my_session

# Split the window into two panes (one on the left and one on the right)
tmux split-window -h
tmux send-keys -t my_session:0.0 'bash' C-m
tmux send-keys -t my_session:0.1 'make' C-m
tmux send-keys -t my_session:0.1 './minishell' C-m
tmux send-keys -t my_session:0.0 'clear' C-m
tmux send-keys -t my_session:0.1 'clear' C-m

# Synchronize the panes so that both receive the same inputs
tmux setw synchronize-panes on

# Attach the tmux session so you can see it in the terminal
tmux attach-session -t my_session