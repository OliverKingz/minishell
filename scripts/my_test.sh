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

    # Run the test case in Minishell
    echo -n "$test_case" | $MINISHELL > "$TMP_MINISHELL_OUTPUT" 2>&1
    local minishell_exit_code=$?

    # Run the test case in Bash
    echo -n "$test_case" | bash > "$TMP_BASH_OUTPUT" 2>&1
    local bash_exit_code=$?

    # Normalize the outputs by removing the prefix
	sed -i 's/^bash: line [0-9]*: //' "$TMP_MINISHELL_OUTPUT"
	sed -i 's/^bash: line [0-9]*: //' "$TMP_BASH_OUTPUT"

    # Compare the outputs
    diff "$TMP_MINISHELL_OUTPUT" "$TMP_BASH_OUTPUT" > "$DIFF_OUTPUT"
    local diff_exit_code=$?

    if [ $diff_exit_code -eq 0 ] && [ $minishell_exit_code -eq $bash_exit_code ]; then
        echo -en "\033[32mPASS\033[0m\t"
        echo "$test_case"
    else
        echo "----------------------------------------"
        echo "$test_case"
        echo -e "\033[31mFAIL\033[0m: Outputs or exit codes differ\n"
        cat "$DIFF_OUTPUT"
        echo "Minishell exit code:	$minishell_exit_code"
        echo "Bash exit code:		$bash_exit_code"
        echo -e "----------------------------------------\n"
    fi
}

# COLOURS: BOLD RGBYW
BR="\033[1;31m"
BG="\033[1;32m"
BB="\033[1;34m"
BY="\033[1;33m"
BW="\033[1;37m"

# NO COLOR and CLEAR LINE
NC="\033[0;39m"
CL="\033[2K"

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo -e "${BB}Basic Commands${NC}"
run_test "echo \"Hello\"" "Basic echo command"
run_test "ls" "Basic ls command"
run_test "pwd" "Basic pwd command"
run_test "cd .." "Change to parent directory"

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo -e "${BB}Redirections${NC}"
run_test "cat < testfile.txt" "Input redirection"
run_test "echo \"Hello\" > file.txt" "Output redirection"
run_test "echo \"Hello\" >> file.txt" "Append redirection"
run_test "grep \"pattern\" < input.txt" "Input redirection with grep"
run_test "echo \"Hello\" > file.txt 2>&1" "Combined redirection"
run_test "echo \"Hello\" >> file.txt 2>&1" "Combined append redirection"

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo -e "${BB}Pipes${NC}"
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

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo -e "${BB}Quotes and Variables${NC}"
run_test "echo \"Hello 'World'\"" "Mixed quotes"
run_test "echo 'Hello \"World\"'" "Mixed quotes"
run_test "echo \"Hello \$USER\"" "Variable expansion in double quotes"
run_test "echo 'Hello \$USER'" "No variable expansion in single quotes"
run_test "echo \"Hello\tWorld\"" "Tab character"
run_test "echo \"Hello\nWorld\"" "Newline character"
run_test "echo \"Hello\\World\"" "Backslash character"

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo  -e "${BB}Non-existent Files and Directories${NC}"
run_test "ls /nonexistent" "Non-existent directory"
run_test "cat /nonexistent/file.txt" "Non-existent file"
run_test "echo \"Hello\" > /nonexistent/file.txt" "Non-existent file for output redirection"
run_test "cat < /nonexistent/file.txt" "Non-existent file for input redirection"

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo  -e "${BB}Environment Variables${NC}"
run_test "echo \$HOME" "Environment variable"
run_test "echo \$USER" "Environment variable"
run_test "echo \$PATH" "Environment variable"
run_test "echo \$?" "Exit status of last command"
run_test "echo \"\$HOME\"" "Variable in double quotes"
run_test "echo '\$HOME'" "Variable in single quotes"
run_test "echo \"Hello \$USER\"" "Variable expansion in double quotes"
run_test "echo 'Hello \$USER'" "No variable expansion in single quotes"

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo  -e "${BB}Retokenization${NC}"
run_test "$(cat <<EOF
export VAR='ls    -l'
echo \$VAR
EOF
)" "Check retokenization of exported variable"
run_test "$(cat <<EOF
export VAR='ls    -l'
"\$VAR"
EOF
)" "Check retokenization of exported variable"
run_test "$(cat <<EOF
export VAR='ls    -l'
'\$VAR'
EOF
)" "Check retokenization of exported variable"
run_test "$(cat <<EOF
export ALGO='s  -l'
l\$ALGO
EOF
)" "Check retokenization of exported variable"
run_test "$(cat <<EOF
export ALGO='s  -l'
l"\$ALGO"
EOF
)" "Check retokenization of exported variable"
run_test "$(cat <<EOF
export VAR="ls    -l    /tmp"
echo \$VAR
EOF
)" "Check retokenization with multiple spaces"
run_test "$(cat <<EOF
export VAR="ls -l /tmp/special!dir@#"
echo \$VAR
EOF
)" "Check retokenization with special characters"
run_test "$(cat <<EOF
export VAR="echo \$VAR"
echo \$VAR
EOF
)" "Check retokenization with escaped characters"
run_test "$(cat <<EOF
export VAR="ls -l; pwd"
echo \$VAR
EOF
)" "Check retokenization with multiple commands"
run_test "$(cat <<EOF
export VAR="World"
echo 'Hello \$VAR'
EOF
)" "Check variable substitution inside quotes"

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo  -e "${BB}Command Execution${NC}"
run_test "./minishell -c \"ls -l\"" "Command execution"

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo  -e "${BB}Builtin Commands${NC}"
run_test "echo -n \"Hello\"" "Echo with -n option"

run_test "export TEST_VAR=test" "Set environment variable"

run_test "echo \$TEST_VAR" "Print environment variable"
run_test "unset TEST_VAR" "Unset environment variable"
run_test "unset" "Unset without options"

run_test "env | grep PATH" "Print environment variables and filter PATH"

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo  -e "${BB}CD builtin${NC}"
run_test "cd /" "Change to root directory"
run_test "cd -" "Change to previous directory"
run_test "cd /tmp | pwd" "Doesn't cd and print working directory"
run_test "cd .." "Change to relative path"
run_test "cd src/" "Change to absolute path"
run_test "cd README.md" "Change to file instead of a directory"
run_test "cd /nonexistent" "Change to non-existent directory"

# Test: Change to a non-existent directory
mkdir /tmp/testdir_nonexistent 2>/dev/null || true
run_test "cd /tmp/testdir_nonexistent" "Change to non-existent directory"
rm -rf /tmp/testdir_nonexistent

# Test: Permission denied error (create a directory and remove permissions)
mkdir /tmp/testdir_noaccess
chmod 000 /tmp/testdir_noaccess
run_test "cd /tmp/testdir_noaccess" "Change to a directory with no read/write/execute permissions"
chmod 755 /tmp/testdir_noaccess  # Reset permissions
rm -rf /tmp/testdir_noaccess

# Test: Change to a directory with spaces in the name
mkdir '/tmp/My Directory with Spaces'
run_test "cd '/tmp/My Directory with Spaces'" "Change to directory with spaces"
rm -rf '/tmp/My Directory with Spaces'

# Test: Change to a directory with special characters in the name
mkdir '/tmp/special!dir@#'
run_test "cd '/tmp/special!dir@#'" "Change to directory with special characters"
rm -rf '/tmp/special!dir@#'

# Test: Change to home directory when called with no arguments
export HOME=/tmp/test_home
mkdir $HOME
run_test "cd" "Change to home directory without arguments"
rm -rf /tmp/test_home

# Test: Change to a relative directory
mkdir /tmp/testdir_relative
run_test "cd /tmp/testdir_relative" "Change to relative directory"
rm -rf /tmp/testdir_relative

# Test: Change to a non-readable directory
mkdir /tmp/testdir_nonreadable
chmod 000 /tmp/testdir_nonreadable
run_test "cd /tmp/testdir_nonreadable" "Change to non-readable directory"
chmod 755 /tmp/testdir_nonreadable  # Reset permissions
rm -rf /tmp/testdir_nonreadable

# Test: Symbolic link pointing to a directory
mkdir /tmp/symlink_dir
ln -s /tmp/symlink_dir /tmp/symlink_test
run_test "cd /tmp/symlink_test" "Change to symbolic link directory"
rm -rf /tmp/symlink_dir /tmp/symlink_test

# Test: Symbolic link pointing to a file (should fail with 'Not a directory')
touch /tmp/testfile_symlink
ln -s /tmp/testfile_symlink /tmp/symlink_file
run_test "cd /tmp/symlink_file" "Change to symbolic link to file"
rm -f /tmp/testfile_symlink /tmp/symlink_file

# Test: Path with a backslash character (escaping special characters)
mkdir '/tmp/dir_with\backslash'
run_test "cd '/tmp/dir_with\backslash'" "Change to path with backslash character"
rm -rf '/tmp/dir_with\backslash'

# Test: Change to a directory with no execute permission (permission denied)
mkdir /tmp/testdir_noexec
chmod 000 /tmp/testdir_noexec
run_test "cd /tmp/testdir_noexec" "Change to directory with no execute permission"
chmod 755 /tmp/testdir_noexec  # Reset permissions
rm -rf /tmp/testdir_noexec

run_test "cd '  '" "Change to directory with spaces as path"

echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
echo  -e "${BB}Errors detected${NC}"
run_test "$(cat <<EOF
export VAR="'hello' | ls"
echo \$VAR
EOF
)" "Err"

run_test "$(cat <<EOF
export VAR="echo 'Hello' > output.txt"
echo \$VAR
EOF
)" "Err"

run_test "$(cat <<EOF
mkdir -p t1/t2/t3
cd t1/t2/t3
rm -rf ../../../t1
pwd
cd ..
cd ..
cd ..
pwd
EOF
)" "Err"

run_test "$(cat <<EOF
mkdir -p t1/t2/t3
cd t1/t2/t3
rm -rf ../../../t1
pwd
cd ..
cd -
cd -
cd ..
cd ..
pwd
EOF
)" "Err"

run_test "$(cat <<EOF
mkdir -p t1/t2/t3
cd t1/t2/t3
rm -rf ../../../t1
env | grep PWD
cd ..
env | grep PWD
cd ..
env | grep PWD
cd ..
env | grep PWD
EOF
)" "Err"


# echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
# Errors but are okay
# run_test "cd ~" "Change to home directory"
# run_test "exit" "Exit the shell"
# run_test "exit 42" "Exit the shell with status 42"
# run_test "env" "Print all environment variables"


# echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
# Unkown if it should work
# run_test "exec ls" "Exec command"
# run_test "ps | grep minishell" "Process listing"
# run_test "kill -9 \$(pidof minishell)" "Process termination"

# mkdir '/tmp/path_with_newline
# '
# run_test "cd '/tmp/path_with_newline
# '" "Change to path with newline character"
# rm -rf '/tmp/path_with_newline
# '

# echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
# Errors not suported
# run_test "$(cat <<EOF
# export VAR="echo 'Hello' | grep 'Hello'"
# echo \$VAR
# EOF
# )" "Check retokenization with pipe symCheck retokenization with escaped single quotesbol"
# run_test "$(cat <<EOF
# export VAR="ls -l \$(which bash)"
# echo \$VAR
# EOF
# )" "Check retokenization with command substitution"
# run_test "$(cat <<EOF
# export VAR="echo 'Hello' \n echo 'World'"
# echo \$VAR
# EOF
# )" "Check retokenization with newline character"
# run_test "$(cat <<EOF
# export VAR="It's \"working\" now"
# echo \$VAR
# EOF
# )" "Check retokenization with escaped single quotes"

# echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
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

# echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
# Bonus tests
# run_test "sleep 3 &" "Background process"
# run_test "echo \"Hello \$(whoami)\"" "Command substitution in double quotes"
# run_test "echo 'Hello \$(whoami)'" "No command substitution in single quotes"

# echo  -e "\n${BB}--------------------------------------------------------------------------------${NC}"
# Clean up temporary files
rm "$TMP_MINISHELL_OUTPUT" "$TMP_BASH_OUTPUT" "$DIFF_OUTPUT"
rm file.txt output.txt count.txt "&1"

echo  -e "\n${BB}-----------------------------------------------------------------------------------${NC}"
echo  -e "${BB}|                            All tests completed                                  |${NC}"
echo  -e "${BB}-----------------------------------------------------------------------------------${NC}"