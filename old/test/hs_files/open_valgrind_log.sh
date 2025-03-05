#!/bin/bash

# Get the most recent Valgrind log file
latest_log=$(ls -t test/valgrind_outputs/valgrind_output_*.log | head -n 1)

# Check if the file exists
if [ -f "$latest_log" ]; then
    # Open the file with VSCode
    code "$latest_log"
else
    echo "No Valgrind log file found."
fi
