# Minishell TO-DO List (Ordered by Priority)

## Legend:
- ✅ It works, maybe with frees and leaks
- ❌ Wrong
- ⌛ Work in Progress
- 🆓 There are leaks to fix. Waiting for parse.
- ❓ No se si tiene que contemplarse

---
## **Priority 0: Project Setup**
- [✅] Create the project directory structure.
  - [✅] Separate source files (`src`), headers (`includes`), and tests (`tests`).
- [✅] Set up the `Makefile` with rules: `all`, `clean`, `fclean`, `re`.
  - [✅] Ensure the `Makefile` compiles with `-Wall`, `-Werror`, and `-Wextra`.
  - [✅] Include `libft` if used, and ensure it compiles first.
- [✅] Ensure the project compiles without errors and does not relink.

## **Priority 1: Parser**

### **1. Basic Tokenization**
- [✅] Split input into tokens by spaces (e.g., `ls -l > file.txt` → `["ls", "-l", ">", "file.txt"]`).
  - [✅] Handle multiple spaces and tabs.
  - [✅] Ignore leading and trailing spaces.
  - [⌛] Check edge cases
- [✅] Identify special tokens (e.g., `>`, `<`, `|`, `>>`, `<<`).
  - [✅] Handle consecutive special tokens (e.g., `>>`, `<<`).
- [✅] Store tokens in a data structure (e.g., linked list).
  - [✅] Ensure the structure is easy to traverse and manipulate.

### **2. Command Parsing**
- [✅] Group tokens into commands and arguments.
  - [✅] Separate commands by pipes (`|`).
  - [✅] Handle redirections (`<`, `>`, `>>`, `<<`) within commands.
- [✅] Handle basic redirections:
  - [✅] `<` for input redirection.
  - [✅] `>` for output redirection.
  - [✅] `>>` for append output redirection.
  - [✅] `<<` for here document (read input until delimiter).
- [✅] Handle pipes (`|`):
  - [✅] Connect the output of one command to the input of the next.

### **3. Syntax Validation**
- [✅] Check for invalid syntax:
  - [✅] Double pipes (`||`).
  - [✅] Unclosed quotes (`'`, `"`).
  - [✅] Invalid redirections (e.g., `> > file.txt`).
- [✅] Print error messages for invalid syntax.
  - [✅] Use `perror` or custom error messages.
  - [✅] Ensure the shell continues running after an error.

### **4. Advanced Tokenization**
- [✅] Handle quotes (`'`, `"`):
  - [✅] Single quotes: Prevent interpretation of metacaracters.
  - [✅] Double quotes: Prevent interpretation of metacaracters except `$`.
- [✅] Handle special characters (e.g., `\`, `$`):
  - [❓] Escape characters (e.g., `\n`, `\t`).
  - [✅] Expand environment variables (e.g., `$HOME`).
  - [❌] Handle `$?` to expand to the exit status of the last command.

### **5. Command Structure**
- [✅] Create a data structure to represent commands:
  - [✅] Command name (e.g., `ls`).
  - [✅] Arguments (e.g., `-l`).
  - [✅] Redirections (e.g., `> file.txt`).
  - [✅] Pipes (e.g., `| grep .c`).
  - [✅] Input/output file descriptors for redirections and pipes.

---

## **Priority 2: Core Shell Functionality**

### **1. Basic Shell Loop**
- [✅] Display a prompt (e.g., `minishell> `).
  - [❌] Customize the prompt if needed.
- [✅] Read user input using `readline`.
  - [✅] Handle `ctrl-D` (EOF) to exit the shell.
  - [✅] Add input to history using `add_history`.
- [✅] Print the input back to the user (for testing purposes).

### **2. Command Execution**
- [] Execute commands using `fork`, `execve`, and `waitpid`.
  - [] Search for executables using the `PATH` environment variable.
  - [] Handle errors for invalid commands or files (e.g., `command not found`).
- [] Handle relative and absolute paths for executables.

### **3. Signal Handling**
- [✅] Handle `ctrl-C` (SIGINT) to print a new prompt.
  - [✅] Ensure the signal handler resets the prompt on a new line.
- [✅] Handle `ctrl-\` (SIGQUIT) to do nothing.
- [✅] Use only **one global variable** to indicate signal reception (e.g., signal number).

### **4. Environment Variables**
- [] Retrieve environment variables using `getenv`.
  - [] Handle `PATH` to locate executables.
- [] Print the environment using a basic `env` built-in.
  - [] Ensure it prints all environment variables.

### **5. Basic Built-ins**
- [] Implement `echo` with the `-n` option.
  - [] Handle multiple arguments and the `-n` flag.
- [] Implement `exit` to terminate the shell.
  - [] Handle optional exit status (e.g., `exit 42`).

---

## **Priority 3: Advanced Features**

### **1. Built-in Commands**
- [] Implement `cd`:
  - [] Handle relative and absolute paths.
  - [] Handle errors (e.g., non-existent directory).
  - [] Update `PWD` and `OLDPWD` environment variables.
- [] Implement `pwd`:
  - [] Print the current working directory using `getcwd`.
- [] Implement `export`:
  - [] Set environment variables.
  - [] Handle invalid variable names (e.g., `export 123=abc`).
- [] Implement `unset`:
  - [] Unset environment variables.
  - [] Handle invalid variable names.

### **2. Environment Variable Expansion**
- [] Expand `$HOME`, `$PATH`, etc., to their values.
  - [] Handle nested variables (e.g., `$USER$HOME`).
- [] Handle `$?` to expand to the exit status of the last command.
  - [] Update `$?` after each command execution.

### **3. Error Handling**
- [] Handle errors for invalid commands, files, or syntax.
  - [] Print meaningful error messages (e.g., `minishell: command not found: ls123`).
- [] Ensure the shell continues running after errors.

---

## **Priority 4: Bonus Features (Optional)**

### **1. Logical Operators**
- [] Implement `&&`:
  - [] Execute the next command only if the previous one succeeds.
- [] Implement `||`:
  - [] Execute the next command only if the previous one fails.
- [] Support parentheses for priority (e.g., `(echo A && echo B) || echo C`).

### **2. Wildcards**
- [] Implement `*` wildcard:
  - [] Match files in the current directory (e.g., `ls *.c`).
  - [] Handle multiple wildcards (e.g., `ls */*.c`).

---

## **Priority 5: Testing and Final Checks**

### **1. Testing**
- [] Create a testing script to automate testing.
  - [] Test basic commands, redirections, and pipes.
  - [] Test edge cases (e.g., empty input, unclosed quotes).
- [] Test signal handling (e.g., `ctrl-C`, `ctrl-D`).

### **2. Norm Check**
- [] Run the 42 Norminette to ensure compliance.
  - [] Fix all norm errors before submission.

### **3. Memory Leak Check**
- [] Run `valgrind` to ensure no memory leaks.
  - [] Fix all leaks except for `readline` leaks (allowed).

### **4. Error Handling Check**
- [] Test all error scenarios to ensure proper handling.
  - [] Ensure the shell does not crash on invalid input.

### **5. Bonus Check (if applicable)**
- [] Ensure bonus features work perfectly if implemented.
  - [] Test logical operators and wildcards thoroughly.

---