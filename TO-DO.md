# Minishell TO-DO List

## Legend: 
- ✅ It works, maybe with frees and leaks
- ❌ Wrong
- ⌛ Work in Progress
- 🆓 There are leaks to fix. Waiting for parse.

## Core Setup
- [ ] Set up the project directory structure.
- [ ] Create a `Makefile` with rules: `all`, `clean`, `fclean`, `re`.
- [ ] Include the `libft` library if used.
- [ ] Ensure the project compiles without errors.

---

## Mandatory Features

### 1. Shell Loop
- [ ] Display a prompt (e.g., `minishell> `).
- [ ] Read user input using `readline`.
- [ ] Handle `ctrl-D` (EOF) to exit the shell.

### 2. Command Execution
- [ ] Parse user input into commands and arguments.
- [ ] Search for executables using the `PATH` environment variable.
- [ ] Execute commands using `fork`, `execve`, and `waitpid`.
- [ ] Handle errors for invalid commands or files.

### 3. History
- [ ] Implement a functional history using `add_history`.
- [ ] Allow navigation through history with arrow keys.

### 4. Signal Handling
- [ ] Handle `ctrl-C` (SIGINT) to print a new prompt.
- [ ] Handle `ctrl-\` (SIGQUIT) to do nothing.

### 5. Redirections
- [ ] Implement input redirection (`<`).
- [ ] Implement output redirection (`>`).
- [ ] Implement append output redirection (`>>`).
- [ ] Implement here document (`<<`).

### 6. Pipes
- [ ] Implement pipes (`|`) to connect commands.
- [ ] Manage file descriptors using `pipe`, `dup`, and `dup2`.

### 7. Environment Variables
- [ ] Expand environment variables (e.g., `$HOME`, `$?`).
- [ ] Handle `$?` to expand to the exit status of the last command.

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
- [ ] Use `valgrind` to ensure no memory leaks.

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
- [ ] Run the 42 Norminette to ensure compliance.

### 2. Memory Leak Check
- [ ] Run `valgrind` to ensure no memory leaks.

### 3. Error Handling Check
- [ ] Test all error scenarios to ensure proper handling.

### 4. Bonus Check (if applicable)
- [ ] Ensure bonus features work perfectly if implemented.

---

## Submission

### 1. Git Push
- [ ] Push the final version to the Git repository.

### 2. Defense Preparation
- [ ] Prepare for the project defense by reviewing the code and testing all features.

---

## Notes
- **Mandatory Features**: These are required for the project to be considered complete.
- **Bonus Features**: These are optional and will only be evaluated if the mandatory part is perfect.
- **Testing**: Test thoroughly to ensure all features work as expected and handle edge cases gracefully.