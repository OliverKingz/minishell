## Minishell subject TO-DO List

### Legend:
- ✅ It works, maybe with frees and leaks
- ❌ Wrong
- ⌛ Work in Progress
- 🆓 There are leaks to fix. Waiting for parse.

---

## Core Setup
- [ ] Set up the project directory structure.
- [ ] Create a `Makefile` with rules: `NAME`, `all`, `clean`, `fclean`, `re`.
- [ ] Ensure the `Makefile` compiles with `-Wall`, `-Werror`, and `-Wextra`.
- [ ] Include the `libft` library if used, and ensure it compiles first.
- [ ] Ensure the project compiles without errors and does not relink.
- [ ] Use `make -n` to verify that the compilation uses `-Wall`, `-Wextra`, and `-Werror`.

---

## Mandatory Features

### 1. Shell Loop
- [ ] Display a prompt (e.g., `minishell> `).
- [ ] Read user input using `readline`.
- [ ] Handle `ctrl-D` (EOF) to exit the shell.
- [ ] Handle `ctrl-C` (SIGINT) to print a new prompt on a new line.
- [ ] Handle `ctrl-\` (SIGQUIT) to do nothing.

#### Tests for Shell Loop:
- [ ] Test `ctrl-D` in an empty prompt (should exit the shell).
- [ ] Test `ctrl-C` in an empty prompt (should print a new prompt).
- [ ] Test `ctrl-\` in an empty prompt (should do nothing).
- [ ] Test `ctrl-C` after typing some text (should clear the input and print a new prompt).
- [ ] Test `ctrl-D` after typing some text (should do nothing).
- [ ] Test `ctrl-\` after typing some text (should do nothing).
- [ ] Test `ctrl-C` during a blocking command like `cat` (should interrupt the command and print a new prompt).
- [ ] Test `ctrl-\` during a blocking command like `cat` (should do nothing).
- [ ] Test `ctrl-D` during a blocking command like `cat` (should quit the shell).

---

### 2. Command Execution
- [ ] Parse user input into commands and arguments.
- [ ] Search for executables using the `PATH` environment variable or relative/absolute paths.
- [ ] Execute commands using `fork`, `execve`, and `waitpid`.
- [ ] Handle errors for invalid commands or files.

#### Tests for Command Execution:
- [ ] Test a simple command with an absolute path (e.g., `/bin/ls`).
- [ ] Test a simple command with arguments (e.g., `/bin/ls -la`).
- [ ] Test an empty command (should do nothing).
- [ ] Test a command with only spaces or tabs (should do nothing).
- [ ] Test a command that does not exist (e.g., `/bin/nonexistent`).
- [ ] Test a command with a relative path (e.g., `./minishell`).
- [ ] Test a command with a complex relative path (e.g., `../../bin/ls`).
- [ ] Test a command with a non-executable file (e.g., `/etc/passwd`).

---

### 3. History
- [ ] Implement a functional history using `add_history`.
- [ ] Allow navigation through history with arrow keys.

#### Tests for History:
- [ ] Test adding commands to history.
- [ ] Test navigating through history with up and down arrows.
- [ ] Test executing a command from history.
- [ ] Test clearing the history buffer after `ctrl-C`.

---

### 4. Signal Handling
- [ ] Handle `ctrl-C` (SIGINT) to print a new prompt.
- [ ] Handle `ctrl-\` (SIGQUIT) to do nothing.
- [ ] Use only **one global variable** to indicate signal reception (e.g., signal number).

#### Tests for Signal Handling:
- [ ] Test `ctrl-C` in an empty prompt (should print a new prompt).
- [ ] Test `ctrl-\` in an empty prompt (should do nothing).
- [ ] Test `ctrl-C` after typing some text (should clear the input and print a new prompt).
- [ ] Test `ctrl-\` after typing some text (should quit the shell).
- [ ] Test `ctrl-C` during a blocking command like `cat` (should interrupt the command and print a new prompt).
- [ ] Test `ctrl-\` during a blocking command like `cat` (should quit the shell).

---

### 5. Redirections
- [ ] Implement input redirection (`<`).
- [ ] Implement output redirection (`>`).
- [ ] Implement append output redirection (`>>`).
- [ ] Implement here document (`<<`) with a delimiter.

#### Tests for Redirections:
- [ ] Test input redirection (e.g., `cat < file.txt`).
- [ ] Test output redirection (e.g., `ls > output.txt`).
- [ ] Test append output redirection (e.g., `ls >> output.txt`).
- [ ] Test here document (e.g., `cat << EOF`).
- [ ] Test multiple redirections (e.g., `cat < input.txt > output.txt`).
- [ ] Test invalid redirections (e.g., `cat < nonexistent.txt`).

---

### 6. Pipes
- [ ] Implement pipes (`|`) to connect commands.
- [ ] Manage file descriptors using `pipe`, `dup`, and `dup2`.

#### Tests for Pipes:
- [ ] Test a simple pipe (e.g., `cat file.txt | grep hello`).
- [ ] Test multiple pipes (e.g., `cat file.txt | grep hello | wc -l`).
- [ ] Test a failing command in a pipe (e.g., `ls nonexistent | grep hello`).
- [ ] Test mixing pipes and redirections (e.g., `cat file.txt | grep hello > output.txt`).

---

### 7. Environment Variables
- [ ] Expand environment variables (e.g., `$HOME`, `$PATH`).
- [ ] Handle `$?` to expand to the exit status of the last command.
- [ ] Handle `export`, `unset`, and `env` built-ins for environment variables.

#### Tests for Environment Variables:
- [ ] Test `echo $HOME` (should print the home directory).
- [ ] Test `echo $?` after a successful command (should print `0`).
- [ ] Test `echo $?` after a failing command (should print a non-zero value).
- [ ] Test `export VAR=value` and `echo $VAR` (should print `value`).
- [ ] Test `unset VAR` and `echo $VAR` (should print nothing).
- [ ] Test `env` (should print the current environment variables).

---

### 8. Quoting
- [ ] Handle single quotes (`'`) to prevent interpretation of metacharacters.
- [ ] Handle double quotes (`"`) to prevent interpretation of metacharacters except `$`.
- [ ] Detect and handle unclosed quotes.

#### Tests for Quoting:
- [ ] Test `echo 'hello world'` (should print `hello world`).
- [ ] Test `echo "$HOME"` (should print the home directory).
- [ ] Test `echo '$HOME'` (should print `$HOME`).
- [ ] Test unclosed quotes (e.g., `echo "hello`).

---

### 9. Built-in Commands
- [ ] Implement `echo` with the `-n` option.
- [ ] Implement `cd` with relative or absolute paths.
- [ ] Implement `pwd` to print the current working directory.
- [ ] Implement `export` to set environment variables.
- [ ] Implement `unset` to unset environment variables.
- [ ] Implement `env` to print the environment.
- [ ] Implement `exit` to terminate the shell.

#### Tests for Built-in Commands:
- [ ] Test `echo hello` (should print `hello`).
- [ ] Test `echo -n hello` (should print `hello` without a newline).
- [ ] Test `cd /tmp` and `pwd` (should print `/tmp`).
- [ ] Test `cd ..` and `pwd` (should print the parent directory).
- [ ] Test `export VAR=value` and `env` (should include `VAR=value`).
- [ ] Test `unset VAR` and `env` (should not include `VAR`).
- [ ] Test `exit` (should terminate the shell).
- [ ] Test `exit 42` (should terminate the shell with exit code `42`).

---

## Bonus Features (Optional)

### 1. Logical Operators
- [ ] Implement `&&` to execute the next command only if the previous one succeeds.
- [ ] Implement `||` to execute the next command only if the previous one fails.
- [ ] Support parentheses for priority (e.g., `(echo A && echo B) || echo C`).

#### Tests for Logical Operators:
- [ ] Test `echo A && echo B` (should print `A` and `B`).
- [ ] Test `false && echo B` (should not print `B`).
- [ ] Test `false || echo B` (should print `B`).
- [ ] Test `(echo A && echo B) || echo C` (should print `A` and `B`).

---

### 2. Wildcards
- [ ] Implement `*` wildcard to match files in the current directory (e.g., `ls *.c`).

#### Tests for Wildcards:
- [ ] Test `ls *.c` (should list all `.c` files).
- [ ] Test `echo *.c` (should print all `.c` files).

---

## Final Checks
- [ ] Run the 42 Norminette to ensure compliance with the coding standards.
- [ ] Run `valgrind` to ensure no memory leaks (except for `readline`).
- [ ] Test all error scenarios to ensure proper handling.
- [ ] Ensure bonus features work perfectly if implemented.

---
