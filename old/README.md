# Minishell

Minishell is a 42 school team project to create a basic shell program in C. It implements redirections and pipes, as well as environment variable expansions and the `cd`, `echo`, `env`, `exit`, `export`, `pwd` and `unset` builtin commands.

## Authorized functions

| **Name Function**       | **Prototype Function**                                   | **Description**                                                                                                                                   | **Parameters**                                                                                             | **Return**                                  |
|--------------------------|---------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|---------------------------------------------|
| `readline` ✔️               | `char *readline(const char *prompt)`                     | Reads a line of text from the user.                                                                                                               | `const char *prompt`: Prompt text shown to the user.                                                      | Pointer to the string read.                 |
| `rl_clear_history`        | `void rl_clear_history(void)`                            | Clears the history list.                                                                                                                          | None                                                                                                       | None                                        |
| `rl_on_new_line`          | `int rl_on_new_line(void)`                               | Updates internal state when the user moves to a new line.                                                                                         | None                                                                                                       | 0 on success, non-zero on failure.          |
| `rl_replace_line`         | `int rl_replace_line(const char *text, int clear_undo)`  | Replaces the current line with the provided text.                                                                                                 | `const char *text`: Text to replace. `int clear_undo`: Whether to clear undo information.                  | 0 on success, non-zero on failure.          |
| `rl_redisplay`            | `void rl_redisplay(void)`                                | Redraws the current input line.                                                                                                                   | None                                                                                                       | None                                        |
| `add_history`             | `void add_history(const char *line)`                     | Adds a line to the history list.                                                                                                                  | `const char *line`: The line to add.                                                                       | None                                        |
| `printf` ✔️                  | `int printf(const char *format, ...)`                   | Prints formatted output to standard output.                                                                                                       | `const char *format`: Format string. Additional arguments: Values to format.                               | Number of characters printed.               |
| `malloc` ✔️                  | `void *malloc(size_t size)`                             | Allocates memory dynamically.                                                                                                                     | `size_t size`: Number of bytes to allocate.                                                               | Pointer to allocated memory or `NULL`.      |
| `free` ✔️                    | `void free(void *ptr)`                                  | Frees dynamically allocated memory.                                                                                                               | `void *ptr`: Pointer to memory to free.                                                                   | None                                        |
| `write` ✔️                   | `ssize_t write(int fd, const void *buf, size_t count)`   | Writes data to a file descriptor.                                                                                                                 | `int fd`: File descriptor. `const void *buf`: Data to write. `size_t count`: Number of bytes to write.     | Number of bytes written or -1 on error.     |
| `access` ✔️                 | `int access(const char *pathname, int mode)`            | Checks file accessibility.                                                                                                                        | `const char *pathname`: Path to the file. `int mode`: Access mode to check.                                | 0 on success, -1 on error.                  |
| `open` ✔️                   | `int open(const char *pathname, int flags, ...mode_t)`   | Opens a file.                                                                                                                                     | `const char *pathname`: Path to the file. `int flags`: Opening flags. `mode_t`: Optional mode (permissions).| File descriptor on success, -1 on error.    |
| `read` ✔️                    | `ssize_t read(int fd, void *buf, size_t count)`          | Reads data from a file descriptor.                                                                                                                | `int fd`: File descriptor. `void *buf`: Buffer for reading. `size_t count`: Max bytes to read.             | Number of bytes read or -1 on error.        |
| `close` ✔️                   | `int close(int fd)`                                     | Closes a file descriptor.                                                                                                                         | `int fd`: File descriptor to close.                                                                        | 0 on success, -1 on error.                  |
| `fork` ✔️                    | `pid_t fork(void)`                                      | Creates a new process by duplicating the calling process.                                                                                         | None                                                                                                       | Process ID of the child process.            |
| `wait` ✔️                   | `pid_t wait(int *status)`                               | Waits for a child process to change state.                                                                                                        | `int *status`: Pointer to store the child's status.                                                       | Process ID of the terminated child.         |
| `execve` ✔️                 | `int execve(const char *pathname, char *const argv[], char *const envp[])` | Executes a program.                                                                                                                               | `const char *pathname`: Path to the program. `argv[]`: Argument list. `envp[]`: Environment variables.     | Does not return on success, -1 on error.    |
| `getenv` ✔️                 | `char *getenv(const char *name)`                        | Retrieves the value of an environment variable.                                                                                                   | `const char *name`: Name of the environment variable.                                                     | Pointer to the value or `NULL`.             |
| `waitpid` ✔️ | `pid_t waitpid(pid_t pid, int *status, int options);` | Suspends execution of the calling process until a child specified by `pid` terminates. | `pid`: Process ID, `status`: Pointer to store status, `options`: Flags to modify behavior | Process ID or -1 on error |
| `wait3` ✔️ | `pid_t wait3(int *status, int options, struct rusage *rusage);` | Waits for child process to change state and provides resource usage statistics. | `status`: Pointer to store status, `options`: Flags, `rusage`: Resource usage info | Process ID or -1 on error |
| `wait4` ✔️ | `pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);` | Similar to `wait3`, but allows specifying a specific child process. | `pid`: Process ID, `status`: Pointer to store status, `options`: Flags, `rusage`: Resource usage info | Process ID or -1 on error |
| `signal` | `void (*signal(int signum, void (*handler)(int)))(int);` | Sets a function to handle a specific signal. | `signum`: Signal number, `handler`: Function to handle signal | Previous handler or `SIG_ERR` |
| `sigaction` | `int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);` | Examines or changes the action associated with a signal. | `signum`: Signal number, `act`: New action, `oldact`: Old action | 0 on success, -1 on error |
| `kill` | `int kill(pid_t pid, int sig);` | Sends a signal to a process or group of processes. | `pid`: Process ID, `sig`: Signal to send | 0 on success, -1 on error |
| `exit` ✔️ | `void exit(int status);` | Terminates the calling process immediately. | `status`: Exit status | No return |
| `getcwd` | `char *getcwd(char *buf, size_t size);` | Gets the current working directory. | `buf`: Buffer to store path, `size`: Buffer size | Pointer to `buf` or NULL on error |
| `chdir` | `int chdir(const char *path);` | Changes the current working directory. | `path`: New directory path | 0 on success, -1 on error |
| `stat` | `int stat(const char *path, struct stat *buf);` | Retrieves information about a file. | `path`: File path, `buf`: Pointer to store file info | 0 on success, -1 on error |
| `lstat` | `int lstat(const char *path, struct stat *buf);` | Like `stat`, but does not follow symbolic links. | `path`: File path, `buf`: Pointer to store file info | 0 on success, -1 on error |
| `fstat` | `int fstat(int fd, struct stat *buf);` | Gets file status based on file descriptor. | `fd`: File descriptor, `buf`: Pointer to store file info | 0 on success, -1 on error |
| `unlink` ✔️ | `int unlink(const char *path);` | Deletes a file. | `path`: File path | 0 on success, -1 on error |
| `dup` ✔️ | `int dup(int oldfd);` | Duplicates a file descriptor. | `oldfd`: Existing file descriptor | New file descriptor or -1 on error |
| `dup2` ✔️ | `int dup2(int oldfd, int newfd);` | Duplicates `oldfd` to `newfd`. | `oldfd`: Existing file descriptor, `newfd`: Target file descriptor | `newfd` or -1 on error |
| `pipe` ✔️ | `int pipe(int pipefd[2]);` | Creates a pair of file descriptors for interprocess communication. | `pipefd`: Array of two file descriptors | 0 on success, -1 on error |
| `opendir` | `DIR *opendir(const char *name);` | Opens a directory stream. | `name`: Directory path | Pointer to `DIR` or NULL on error |
| `readdir` | `struct dirent *readdir(DIR *dirp);` | Reads a directory entry. | `dirp`: Directory stream | Pointer to `dirent` or NULL on end/error |
| `closedir` | `int closedir(DIR *dirp);` | Closes a directory stream. | `dirp`: Directory stream | 0 on success, -1 on error |
| `strerror` ✔️ | `char *strerror(int errnum);` | Returns an error message for a given error number. | `errnum`: Error number | Pointer to error message string |
| `perror` ✔️ | `void perror(const char *s);` | Prints an error message to `stderr`. | `s`: Custom message prefix | No return |
| `isatty` | `int isatty(int fd);` | Checks if a file descriptor refers to a terminal. | `fd`: File descriptor | 1 if terminal, 0 otherwise |
| `ttyname` | `char *ttyname(int fd);` | Gets the terminal name associated with a file descriptor. | `fd`: File descriptor | Pointer to terminal name or NULL |
| `ttyslot` | `int ttyslot(void);` | Gets the terminal slot number. | None | Terminal slot number or 0 |
| `ioctl` | `int ioctl(int fd, unsigned long request, ...);` | Controls device parameters. | `fd`: File descriptor, `request`: Control command | Varies by request, -1 on error |
| `tcsetattr` | `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);` | Sets terminal parameters. | `fd`: File descriptor, `optional_actions`: When to apply settings, `termios_p`: New settings | 0 on success, -1 on error |
| `tcgetattr` | `int tcgetattr(int fd, struct termios *termios_p);` | Gets terminal parameters. | `fd`: File descriptor, `termios_p`: Buffer for settings | 0 on success, -1 on error |
| `tgetent` | `int tgetent(char *bp, const char *name);` | Retrieves the terminal entry from the termcap database. | `bp`: Buffer, `name`: Terminal name | 1 on success, 0 if not found, -1 on error |
| `tgetflag` | `int tgetflag(const char *id);` | Gets boolean terminal capability. | `id`: Capability ID | 1 if true, 0 if false, -1 on error |
| `tgetnum` | `int tgetnum(const char *id);` | Gets numeric terminal capability. | `id`: Capability ID | Capability value or -1 on error |
| `tgetstr` | `char *tgetstr(const char *id, char **area);` | Gets string terminal capability. | `id`: Capability ID, `area`: Storage buffer | Pointer to string or NULL |
| `tgoto` | `char *tgoto(const char *cap, int col, int row);` | Returns cursor positioning string. | `cap`: Capability string, `col`: Column, `row`: Row | Pointer to string |
| `tputs` | `int tputs(const char *str, int affcnt, int (*putc)(int));` | Outputs a terminal capability string. | `str`: String, `affcnt`: Affected lines, `putc`: Output function | 0 on success, -1 on error |

This document serves as a quick reference guide for working with these functions in C programming.







## Usage


To compile:

```shell
make
```
```shell
./minishell
```

To run the program:

```shell
./minishell
```

For example:

```shell
$ bash -c 'echo hello world | cat -e'
hello world$
$ ./minishell -c 'echo hello world | cat -e'
hello world$
```

Test:
```shell
make test
```


## Supported Features

Minishell is a miniature shell program based on Bash. Minishell supports:
* Prompt display
* Command history (up and down arrows)
* System executables available from the environment (`ls`, `cat`, `grep`, etc.)
* Local executables (`./minishell`)
* Builtin commands :
  * `echo`: display a line of text. (and option `-n`: do not output the trailing newline (no mostrar la última línea).)
  * `cd`: change the working directory (with only a relative or absolute path)
  * `pwd`: print name of current/working directory (no options)
  * `export`: set the export attribute for variables (no options)
  * `unset`: unset values and attributes of variables and functions (no options)
  * `env`:run a program in a modified environment (no options or arguments)
  * `exit`: cause the shell to exit (with exit number but no other options) 
* Pipes `|` which redirect output from one command to input for the next
* Redirections:
  * `>` redirects output
  * `>>` redirects output in append mode
  * `<` redirects input
  * `<< DELIMITER` displays a new prompt, reads user input until reaching `DELIMITER`, redirects user input to command input (does not update history)
* Environment variables (i.e. `$USER` or `$VAR`) that expand to their values.
  * `$?` expands to the exit status of the most recently executed foreground pipeline.
* User keyboard signals:
  * `ctrl-c` displays a new prompt line.
  * `ctrl-d` exits minishell
  * `ctrl-\` does nothing

However, Minishell does not support `\`, `;`, `&&`, `||`, or wildcards.
---

# Concepts

<b>Bash</b> is the shell, or command language interpreter, for the gnu operating system.

A Unix <b>shell</b> is both a command interpreter and a programming language.

## chapter 2_ Bash Reference Manual:

- <b>control operator</b>: A <b>token</b> that performs a control function. It is a newline or one of the following: ‘||’, ‘&&’, ‘&’, ‘;’, ‘;;’, ‘;&’, ‘;;&’, ‘|’, ‘|&’, ‘(’, or ‘)’.

  * <b>token</b>: A sequence of characters considered a single unit by the shell. It is either a word or an operator.

      * <b>operator</b>: A control operator or a redirection operator. See Section 3.6 page 38, for a list of redirection operators. Operators contain at least one unquoted metacharacter.
          * <b>metacharacter</b>: A character that, when unquoted, separates words. A metacharacter is a space, tab, newline, or one of the following characters: ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’.
      * <b>word</b>:  A sequence of characters treated as a unit by the shell. Words may not include unquoted metacharacters.


      [see <b>token</b> PART](https://medium.com/@dkwok94/how-a-shell-works-what-happens-when-ls-l-is-typed-df4eb468a030#:~:text=The%20shell%20tokenizes%20the%20string%20command%20entered%20by%20the%20user&text=A%20token%20is%20an%20element,each%20token%20is%20one%20word): 

    Typically, this is done using a getline() function which saves the user-entered line from STDIN into a buffer, including the newline character. A token is an element between a delimiter. In this case, the delimiter is typically a space character such that each token is one word. The delimiters are replaced with a \0 null byte so that each token is its own string. So for instance, for `ls -l`, `ls` is a token, and `-l` is another token because they are separated by spaces and each token ends with a null byte. These tokens are typically stored in an array of strings with a terminating NULL pointer for accurate parsing.

    The shell checks if the first token (the main command itself) is an alias, and if so, replaces the alias with the actual command. The shell will typically look in its system files for defined aliases. If the `ls` command is an alias for something else, the shell will replace the ls token with the string for the command that ls represents so that the correct operation takes place in the subsequent steps.

    The shell checks if the entered command matches any of the built-ins. Built-ins are commands that are explicitly coded into the shell itself. The actual code is not from an executable, but actually exists in the source code of the shell. Examples include `exit`, `cd`, and `env`. Since `ls` does not match any built-ins, it must be an executable. 

    When the command does not match any built-ins, the shell then implements the $PATH variable. 
    The $PATH variable is basically a list of directories that the shell looks through for executables. The shell picks this specific variable from the environment variable and uses the : as a delimiter to split the variable up into tokens. The way we did this in our shell was split the environment variable up into a singly linked list.

    The shell appends the command entered to the end of each directory and checks if the executable exists. If the executable does not exist in any $PATH directories, an error is thrown.

    The shell then goes through each directory in the $PATH variable and appends the `ls` command to the end of them. For example, the first directory is `/usr/local/sbin`, so the shell will combine this directory with `ls` to create the following: `/usr/local/sbin/ls` . The shell then puts this string into functions called `access()` (with an argument `F_OK`) or `stat()` which returns 0V if the file exists and `-1` if the file does not. The shell would then check if the file it found is an executable using `access()` with a `X_OK` argument. If the file does not exist or is not executable, it moves to the next directory and does the same thing. If it reaches the end of the $PATH variable, this means the executable does not exist and an error is thrown.

     When the executable is found, the parent process is then forked to create a child process. The child process executes the command while the parent process waits for it to finish. 
     If the executable is found, the shell goes into an execution function. The concept of child and parent processes is then used. The following three commands are most important for this:

    - fork()

    - wait()

    - execve()

    After running a command, the shell executes any shutdown commands programmed into it, frees any allocated memory from its operations, and re-prompts the user for input.


## chapter 3_: Basic Shell Features

When the shell reads input, it proceeds through a sequence of operations. If the input indicates the beginning of a comment, the shell ignores the comment symbol (‘#’), and the rest of that line.

Otherwise, roughly speaking, the shell reads its input and divides the input into words and operators, employing the quoting rules to select which meanings to assign various words and characters.

The shell then parses these tokens into commands and other constructs, removes the special meaning of certain words or characters, expands others, redirects input and output
as needed, executes the specified command, waits for the command’s exit status, and makes that exit status available for further inspection or processing.




### **Shell Command Analysis Process:** 

  * 1. **Reading Input**
  The shell reads input from the user (via standard input) or from a script file. 
  Reads its input from a file (see Section 3.8 [Shell Scripts], page 46), from a string supplied as an argument to the -c invocation option (see Section 6.1 [Invoking Bash], page 91), or from the user’s terminal.

  * 2. **Tokenization**
  Breaks the input into words and operators, obeying the quoting rules described in Section 3.1.2, page 6. These tokens are separated by metacharacters. Alias expansion is performed by this step (see Section 6.6, page 100).

      The input is broken down into **words and operators**, using whitespace and `metacharacters` as delimiters.
      
      
      Examples: see test/commands.txt


  * 3. **Parses the tokens**
  Parses the tokens into **simple** and **compound commands** (see Section 3.2 [Shell Commands], page 9). The shell constructs **commands and syntax structures**, interpreting **keywords**, **control structures**, and **operators**. In this part the pipes are processed: `|` 

      ```
      ls | grep ".txt"
      ```
      It becomes a pipeline of three commands, with the output of each passing to the next:
      ```
      ls (command)
      | (pipe operator)
      grep (command)
      ".txt" (argument, treated as a single token due to quotes)
      ```
        

  * 4. **Quoting and Expansion Handling**
  The shell processes quotes to determine which parts of the input should be treated as **literals**.  
  See Seccion 3.1.2 [Quoting], pages 6 - 9. Performs the various shell expansions (see Section 3.5 [Shell Expansions], page 24), breaking the expanded tokens into lists of filenames (see Section 3.5.8 [Filename Expansion], page 35) and commands and arguments.
  Then, various types of **expansions** take place, including:
        - **Variable expansion** (`$VAR` → its value)
        - **Tilde expansion** (`~` → home directory) 
 

  * 5. **Redirections Processing**
  The shell identifies and processes **input and output redirections**:
        - `< file` (input redirection)
        - `> file` (output redirection, overwrite)
        - `>> file` (output redirection, append)
        - `<<`

  * 6. **Command Execution**
  The shell executes the parsed command by:
        - Searching for the command in **built-ins** or the system’s **PATH**.
        - **Forking** a new process if necessary.
        - Executing the command using **exec()** system calls.

  * 7. **Waiting for Command Completion**
The shell waits for the command to finish execution, unless it is running in the **background** (`command &`).

  * 8. **Retrieving Exit Status**
  Once the command completes, the shell captures its **exit status**, which determines success (`0`) or failure (`>0`).

  * 9. **Making Exit Status Available**
  he exit status is stored in the special variable `$?`, allowing it to be checked or used in **conditional statements**.


### **Shell Error Handling Process**


  * 1. **Syntax Errors Detection**
        - The shell identifies **syntax errors** during the parsing phase.
        - Example: Missing quotes or unexpected tokens (`echo "Hello` → error: unexpected EOF).

  * 2. **Command Not Found**
        - If a command is not found in the **built-ins** or `PATH`, the shell returns an error.
        - Example: `unknowncommand` → `command not found`.

  * 3. **Permission Errors**
        - If the user does not have the required permissions to execute a file, the shell displays a permission error.
        - Example: `./script.sh` (without execute permissions) → `Permission denied`.

  * 4. **Redirection Failures**
        - Errors occur when input or output redirection fails, such as when a file does not exist.
        - Example: `cat < non_existent_file` → `No such file or directory`.

  * 5. **Exit Status Propagation**
        - Commands return an **exit status code** (`$?`) which indicates success (`0`) or failure (`>0`).
        - Example: `grep 'text' file.txt || echo "Error: text not found"`.

  * 6. **Signal Handling**
        - The shell detects **termination signals** (e.g., `SIGINT` for `Ctrl+C`) and handles them appropriately.
        - Example: Pressing `Ctrl+C` while running a command sends `SIGINT` to terminate it.

  * 7. **Handling Subshell and Pipelined Errors**
        - Errors in **subshells** or **pipelines** (`command1 | command2`) can be managed with `set -o pipefail`.
        - Example: `cat file.txt | nonexistentcommand` → Proper error propagation.

  * 8. **Custom Error Handling with Traps**
        - The `trap` command allows handling specific signals or errors.
        - Example: `trap 'echo "Error occurred!"' ERR`.

---
**Parses the tokens**

By using single quotes ('') you explicitly tell the shell not
to interfere with the string at all. If you use double quotes (""), some shell substitutions
do take place (variable, arithmetic, and tilde expansions and command substitutions),
but since we have none in this example, the shell has nothing to change.

```
You don't want the output to preserve your spacing
$ echo this was   very     widely     spaced
this was very widely spaced
$


You want the output to preserve your spacing.
$ echo "this was   very   widely        spaced"
this was   very   widely        spaced
$

or:

$ echo 'this   was very widely      spaced'
this   was very widely      spaced
$
```




```

```


```

```




---
---
### Useful Resources for the Minishell Project

:us: Articles in English about the concepts tackled in this project: 

* [Creating and Killing Child Processes in C](https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/)
* [Pipe: an Inter-Process Communication Method](https://www.codequoi.com/en/pipe-an-inter-process-communication-method/)
* [Sending and Intercepting a Signal in C](https://www.codequoi.com/en/sending-and-intercepting-a-signal-in-c/)
* [Handling a File by its Descriptor in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
* [Errno and Error Management in C](https://www.codequoi.com/en/errno-and-error-management-in-c/)

Other useful links:

* [Bash reference manual](https://www.gnu.org/software/bash/manual/bash.html)
* Introduction to Systems Programming: a Hands-on Approach, [Chapter 5. Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
* [Stephen Brennan's Tutorial - Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
* The Open Group Base Specifications, [Shell Command Language](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)
* [A Guide to Unix Shell Quoting](https://rg1-teaching.mpi-inf.mpg.de/unixffb-ss98/quoting-guide.html)
* [Austin Tripp's Quick Tutorial on Bash Quotes](https://www.austintripp.ca/blog/2019/07/18/bash-quotes)



Other Linux:
 * [ubuntu-cheatsheet](https://github.com/JREAM/ubuntu-cheatsheet)
 * [linux_lib](https://github.com/media-lib/linux_lib/tree/master/books)

---

## ➾ Contributing

* Check the open issues or open a new issue to start a discussion around your feature idea or the bug you found. 
* Fork the repository, make your changes, and add yourself to AUTHORS.md
* Send a pull request.

## ➾ Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 


## ➾ Authors

* [Karma Faber](https://github.com/KarmaFaber).
* [RaulPerezDEV](https://github.com/RaulPerezDEV).

## ➾ License

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or distribute this software, either in source code form or as a compiled binary, for any purpose, commercial or non-commercial, and by any means.

In jurisdictions that recognize copyright laws, the author or authors of this software dedicate any and all copyright interest in the software to the public domain. We make this dedication for the benefit of the public at large and to the detriment of our heirs and successors. We intend this dedication to be an overt act of relinquishment in perpetuity of all present and future rights to this software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
