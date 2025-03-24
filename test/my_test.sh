#!/bin/bash

# Define the path to your Minishell executable
MINISHELL="./minishell"

# Define a temporary file to store outputs
TMP_MINISHELL_OUTPUT=$(mktemp)
TMP_BASH_OUTPUT=$(mktemp)
DIFF_OUTPUT=$(mktemp)

# Function to run a test case
run_test() {
    local test_case="$1"
    local description="$2"

    echo "Running test: $description"
    echo "Test case: $test_case"

    # Run the test case in Minishell
    echo -n "$test_case" | $MINISHELL > "$TMP_MINISHELL_OUTPUT" 2>&1
    local minishell_exit_code=$?

    # Run the test case in Bash
    echo -n "$test_case" | bash > "$TMP_BASH_OUTPUT" 2>&1
    local bash_exit_code=$?

    # Normalize the outputs by removing the prefix
    # sed -i 's/^bash: line 1: //' "$TMP_MINISHELL_OUTPUT"
    # sed -i 's/^bash: line 1: //' "$TMP_BASH_OUTPUT"

    # Compare the outputs
    diff "$TMP_MINISHELL_OUTPUT" "$TMP_BASH_OUTPUT" > "$DIFF_OUTPUT"
    local diff_exit_code=$?

    if [ $diff_exit_code -eq 0 ] && [ $minishell_exit_code -eq $bash_exit_code ]; then
        echo -e "\033[32mPASS\033[0m: Outputs and exit codes match"
    else
        echo -e "\033[31mFAIL\033[0m: Outputs or exit codes differ"
        cat "$DIFF_OUTPUT"
        echo "Minishell exit code: $minishell_exit_code"
        echo "Bash exit code: $bash_exit_code"
    fi

    echo "----------------------------------------"
}

# Basic Commands
run_test "echo \"Hello\"" "Basic echo command"
run_test "ls" "Basic ls command"
run_test "pwd" "Basic pwd command"
run_test "cd .." "Change to parent directory"

# Redirections
run_test "cat < testfile.txt" "Input redirection"
run_test "echo \"Hello\" > file.txt" "Output redirection"
run_test "echo \"Hello\" >> file.txt" "Append redirection"
run_test "grep \"pattern\" < input.txt" "Input redirection with grep"
run_test "echo \"Hello\" > file.txt 2>&1" "Combined redirection"
run_test "echo \"Hello\" >> file.txt 2>&1" "Combined append redirection"

# Pipes
run_test "ls | wc -l" "Basic pipe usage"
run_test "echo \"Hello\" | cat" "Pipe with cat"
run_test "echo \"Hello\" | cat | wc -l" "Multiple pipes"
run_test "ls | grep \"txt\" > output.txt" "Pipe with redirection"
run_test "ls | grep \"txt\" >> output.txt" "Pipe with append redirection"
run_test "ls | grep \"txt\" | wc -l > count.txt" "Multiple pipes with redirection"
run_test "ls | grep \"txt\" | wc -l >> count.txt" "Multiple pipes with append redirection"
run_test "echo \"Hello\" | grep \"H\"" "Pipe with grep"
run_test "echo \"Hello\" | grep \"H\" | wc -l" "Multiple pipes with grep and wc"
run_test "echo \"Hello\" | grep \"H\" > output.txt" "Pipe with redirection to file"
run_test "echo \"Hello\" | grep \"H\" >> output.txt" "Pipe with append redirection to file"
run_test "echo \"Hello\" | grep \"H\" | wc -l > count.txt" "Multiple pipes with redirection to file"
run_test "echo \"Hello\" | grep \"H\" | wc -l >> count.txt" "Multiple pipes with append redirection to file"
run_test "echo \"Hello\" | grep \"H\" | tee file.txt | wc -l" "Pipe with grep, tee, and wc"
run_test "echo \"Hello\" | tee file.txt | cat -n" "Pipe with tee and cat"

# Quotes and Variables
run_test "echo \"Hello 'World'\"" "Mixed quotes"
run_test "echo 'Hello \"World\"'" "Mixed quotes"
run_test "echo \"Hello \$USER\"" "Variable expansion in double quotes"
run_test "echo 'Hello \$USER'" "No variable expansion in single quotes"
run_test "echo \"Hello\tWorld\"" "Tab character"
run_test "echo \"Hello\nWorld\"" "Newline character"
run_test "echo \"Hello\\World\"" "Backslash character"

# Non-existent Files and Directories
run_test "ls /nonexistent" "Non-existent directory"
run_test "cat /nonexistent/file.txt" "Non-existent file"
run_test "echo \"Hello\" > /nonexistent/file.txt" "Non-existent file for output redirection"
run_test "cat < /nonexistent/file.txt" "Non-existent file for input redirection"

# Environment Variables
run_test "echo \$HOME" "Environment variable"
run_test "echo \$USER" "Environment variable"
run_test "echo \$PATH" "Environment variable"
run_test "echo \$?" "Exit status of last command"
run_test "echo \"\$HOME\"" "Variable in double quotes"
run_test "echo '\$HOME'" "Variable in single quotes"
run_test "echo \"Hello \$USER\"" "Variable expansion in double quotes"
run_test "echo 'Hello \$USER'" "No variable expansion in single quotes"

# Command Execution
run_test "./minishell -c \"ls -l\"" "Command execution"

# Builtin Commands
run_test "cd /" "Change to root directory"
run_test "cd ~" "Change to home directory"
run_test "cd -" "Change to previous directory"
run_test "cd /tmp | pwd" "Doesn't cd and print working directory"
run_test "cd .." "Change to relative path"
run_test "cd src/" "Change to absolute path"

run_test "echo -n \"Hello\"" "Echo with -n option"

run_test "export TEST_VAR=test" "Set environment variable"

run_test "echo \$TEST_VAR" "Print environment variable"
run_test "unset TEST_VAR" "Unset environment variable"
run_test "unset" "Unset without options"

run_test "env | grep PATH" "Print environment variables and filter PATH"

# Errors detected
run_test "cd /nonexistent" "Change to non-existent directory"

# Errors but are okay
run_test "exit" "Exit the shell"
run_test "exit 42" "Exit the shell with status 42"
run_test "env" "Print all environment variables"

# Unkown if it should work
# run_test "exec ls" "Exec command"
# run_test "ps | grep minishell" "Process listing"
# run_test "kill -9 \$(pidof minishell)" "Process termination"

# Syntax errors or Errors known and chosen
# run_test "export" "Export without options"

# run_test "echo |" "Syntax Error: Pipe at the end"
# run_test "echo &&" "Syntax Error: Double ampersand"
# run_test "echo ||" "Syntax Error: Double pipe"
# run_test "echo >" "Syntax Error: Redirection without file"
# run_test "echo <" "Syntax Error: Input redirection without file"
# run_test "echo \"Hello\" >" "Syntax Error: Incomplete redirection"
# run_test "echo \"Hello\" <" "Syntax Error: Incomplete input redirection"
# run_test "echo \"Hello\" >>" "Syntax Error: Incomplete append redirection"
# run_test "echo \"Hello\" | |" "Syntax Error: Pipe at the end"
# run_test "echo \"Hello\" &&" "Syntax Error: Incomplete logical AND"
# run_test "echo \"Hello\" ||" "Syntax Error: Incomplete logical OR"

# run_test "echo \"Hello\" 2> error.txt" "Error redirection"
# run_test "echo \"Hello\" 2>> error.txt" "Append error redirection"
# run_test "echo \"Hello\" > file.txt 2>&1" "Combined redirection"
# run_test "echo \"Hello\" >> file.txt 2>&1" "Combined append redirection"

# Bonus tests
# run_test "sleep 3 &" "Background process"
# run_test "echo \"Hello \$(whoami)\"" "Command substitution in double quotes"
# run_test "echo 'Hello \$(whoami)'" "No command substitution in single quotes"

# Clean up temporary files
rm "$TMP_MINISHELL_OUTPUT" "$TMP_BASH_OUTPUT" "$DIFF_OUTPUT"
rm file.txt output.txt count.txt "&1"

echo "|          All tests completed         |"
echo "----------------------------------------"