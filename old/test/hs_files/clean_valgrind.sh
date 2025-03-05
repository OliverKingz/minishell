#!/bin/bash

# Define red color for warning message
RED='\033[1;31m'
RESET='\033[0m'

# Warning message
echo -e "${RED}🛑 Warning: Are you sure you want to delete all Valgrind log files? (y/n)${RESET}"

# Read user input
read -r confirm

# Check if the user confirmed
if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
    echo -e "Deleting all valgrind log files..."
    rm -f test/valgrind_outputs/valgrind_output_*.log
    echo -e "All Valgrind log files have been deleted."
else
    echo -e "Operation cancelled. No files were deleted."
fi
