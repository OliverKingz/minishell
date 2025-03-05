## Minishell subject TO-DO List (Updated)

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

---

## Mandatory Features

### 1. Shell Loop
- [ ] Display a prompt (e.g., `minishell> `).
- [ ] Read user input using `readline`.
- [ ] Handle `ctrl-D` (EOF) to exit the shell.
- [ ] Handle `ctrl-C` (SIGINT) to print a new prompt on a new line.
- [ ] Handle `ctrl-\` (SIGQUIT) to do nothing.

### 2. Command Execution
- [ ] Parse user input into commands and arguments.
- [ ] Search for executables using the `PATH` environment variable or relative/absolute paths.
- [ ] Execute commands using `fork`, `execve`, and `waitpid`.
- [ ] Handle errors for invalid commands or files.

### 3. History
- [ ] Implement a functional history using `add_history`.
- [ ] Allow navigation through history with arrow keys.

### 4. Signal Handling
- [ ] Handle `ctrl-C` (SIGINT) to print a new prompt.
- [ ] Handle `ctrl-\` (SIGQUIT) to do nothing.
- [ ] Use only **one global variable** to indicate signal reception (e.g., signal number).

### 5. Redirections
- [ ] Implement input redirection (`<`).
- [ ] Implement output redirection (`>`).
- [ ] Implement append output redirection (`>>`).
- [ ] Implement here document (`<<`) with a delimiter.

### 6. Pipes
- [ ] Implement pipes (`|`) to connect commands.
- [ ] Manage file descriptors using `pipe`, `dup`, and `dup2`.

### 7. Environment Variables
- [ ] Expand environment variables (e.g., `$HOME`, `$PATH`).
- [ ] Handle `$?` to expand to the exit status of the last command.
- [ ] Handle `export`, `unset`, and `env` built-ins for environment variables.

### 8. Quoting
- [ ] Handle single quotes (`'`) to prevent interpretation of metacaracters.
- [ ] Handle double quotes (`"`) to prevent interpretation of metacaracters except `$`.
- [ ] Detect and handle unclosed quotes.

### 9. Built-in Commands
- [ ] Implement `echo` with the `-n` option.
- [ ] Implement `cd` with relative or absolute paths.
- [ ] Implement `pwd` to print the current working directory.
- [ ] Implement `export` to set environment variables.
- [ ] Implement `unset` to unset environment variables.
- [ ] Implement `env` to print the environment.
- [ ] Implement `exit` to terminate the shell.

---

## Bonus Features (Optional)

### 1. Logical Operators
- [ ] Implement `&&` to execute the next command only if the previous one succeeds.
- [ ] Implement `||` to execute the next command only if the previous one fails.
- [ ] Support parentheses for priority (e.g., `(echo A && echo B) || echo C`).

### 2. Wildcards
- [ ] Implement `*` wildcard to match files in the current directory (e.g., `ls *.c`).

---

## Testing and Debugging

### 1. Unit Tests
- [ ] Create test cases for each feature (e.g., redirections, pipes, built-ins).
- [ ] Test edge cases (e.g., empty input, invalid commands, unclosed quotes).

### 2. Integration Tests
- [ ] Test combinations of features (e.g., `ls | grep .c > output.txt`).
- [ ] Test signal handling (e.g., `ctrl-C`, `ctrl-D`).

### 3. Memory Leak Testing
- [ ] Use `valgrind` to ensure no memory leaks (except for `readline` leaks, which are allowed).

---

## Documentation

### 1. README
- [ ] Write a detailed README explaining the project, features, and how to run it.
- [ ] Include examples and expected outputs.

### 2. Code Comments
- [ ] Add comments to explain complex parts of the code.

---

## Final Checks

### 1. Norm Check
- [ ] Run the 42 Norminette to ensure compliance with the coding standards.

### 2. Memory Leak Check
- [ ] Run `valgrind` to ensure no memory leaks (except for `readline`).

### 3. Error Handling Check
- [ ] Test all error scenarios to ensure proper handling.

### 4. Bonus Check (if applicable)
- [ ] Ensure bonus features work perfectly if implemented.

---

## Submission

### 1. Git Push
- [ ] Push the final version to the Git repository.
- [ ] Ensure the repository contains only the required files (`Makefile`, `*.h`, `*.c`).

### 2. Defense Preparation
- [ ] Prepare for the project defense by reviewing the code and testing all features.

---

## Notes
- **Mandatory Features**: These are required for the project to be considered complete. Ensure all mandatory features are implemented and tested thoroughly.
- **Bonus Features**: These are optional and will only be evaluated if the mandatory part is **perfect**. Focus on completing the mandatory part first.
- **Testing**: Test thoroughly to ensure all features work as expected and handle edge cases gracefully.
- **Memory Management**: Ensure all allocated memory is freed properly, except for `readline` leaks, which are allowed.

---

### Key Adjustments Based on `minishell.pdf`:
1. **Global Variable Limitation**: Only one global variable is allowed for signal handling. Ensure no other global variables are used.
2. **Quoting and Special Characters**: Ensure proper handling of single and double quotes, and avoid interpreting unclosed quotes or unspecified special characters.
3. **Redirections and Pipes**: Ensure all redirections (`<`, `>`, `>>`, `<<`) and pipes (`|`) are implemented correctly.
4. **Built-ins**: Ensure all required built-ins (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`) are implemented.
5. **Bonus Features**: Only implement bonus features if the mandatory part is **perfect**. Focus on logical operators (`&&`, `||`) and wildcards (`*`).
