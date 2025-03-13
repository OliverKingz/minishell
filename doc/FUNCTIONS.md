### /home/oliverkingz/42-Cursus/minishell/DOCS.md

- **Readline functions**
  - `readline`: Reads a line of input from the user.
  - `rl_clear_history`: Clears the readline history list.
  - `rl_on_new_line`: Informs readline that the cursor is on a new line.
  - `rl_replace_line`: Replaces the contents of the current line with the given text.
  - `rl_redisplay`: Redisplays the current line.
  - `add_history`: Adds a line to the readline history.

  ```c
  char *readline(const char *prompt);
  void rl_clear_history(void);
  void rl_on_new_line(void);
  void rl_replace_line(const char *text, int clear_undo);
  void rl_redisplay(void);
  void add_history(const char *line);
  ```

- **Standard I/O functions**
  - `printf`: Prints formatted output to stdout.
  - `perror`: Prints a description of the last error.

  ```c
  int printf(const char *format, ...);
  void perror(const char *s);
  ```

- **Memory management functions**
  - `malloc`: Allocates memory dynamically.
  - `free`: Frees dynamically allocated memory.

  ```c
  void *malloc(size_t size);
  void free(void *ptr);
  ```

- **File operations**
  - `write`: Writes data to a file descriptor.
  - `access`: Checks a file's accessibility.
  - `open`: Opens a file.
  - `read`: Reads data from a file descriptor.
  - `close`: Closes a file descriptor.
  - `stat`: Gets file status.
  - `lstat`: Gets file status, not following symbolic links.
  - `fstat`: Gets file status of an open file descriptor.
  - `unlink`: Deletes a name from the filesystem.

  ```c
  ssize_t write(int fd, const void *buf, size_t count);
  int access(const char *pathname, int mode);
  int open(const char *pathname, int flags, ...);
  ssize_t read(int fd, void *buf, size_t count);
  int close(int fd);
  ```

- **Process control**
  - `fork`: Creates a new process by duplicating the calling process.
  - `wait`: Waits for a child process to change state.
  - `waitpid`: Waits for a specific child process to change state.
  - `wait3`: Waits for a child process to change state with resource usage information.
  - `wait4`: Waits for a specific child process to change state with resource usage information.
  - `execve`: Executes a program.
  - `exit`: Terminates the calling process.

  ```c
  pid_t fork(void);
  pid_t wait(int *wstatus);
  pid_t waitpid(pid_t pid, int *wstatus, int options);
  pid_t wait3(int *wstatus, int options, struct rusage *rusage);
  pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);
  void exit(int status);
  int execve(const char *pathname, char *const argv[], char *const envp[]);
  ```

- **Signal handling**
  - `signal`: Sets a signal handler for a specific signal.
  - `sigaction`: Examines and changes a signal action.
  - `kill`: Sends a signal to a process or a group of processes.

  ```c
  void (*signal(int signum, void (*handler)(int)))(int);
  int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
  int kill(pid_t pid, int sig);
  ```

- **Directory operations**
  - `getcwd`: Gets the current working directory.
  - `opendir`: Opens a directory stream.
  - `readdir`: Reads a directory entry.
  - `closedir`: Closes a directory stream.

  ```c
  char *getcwd(char *buf, size_t size);
  DIR *opendir(const char *name);
  struct dirent *readdir(DIR *dirp);
  int closedir(DIR *dirp);
  ```

- **Terminal control**
  - `isatty`: Tests whether a file descriptor refers to a terminal.
  - `ttyname`: Returns the name of the terminal associated with a file descriptor.
  - `ttyslot`: Returns the index of the current user's terminal.
  - `ioctl`: Manipulates the underlying device parameters of special files.
  - `tcsetattr`: Sets the parameters associated with the terminal.
  - `tcgetattr`: Gets the parameters associated with the terminal.

  ```c
  int isatty(int fd);
  char *ttyname(int fd);
  int ttyslot(void);
  int ioctl(int fd, unsigned long request, ...);
  int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
  int tcgetattr(int fd, struct termios *termios_p);
  ```

- **Environment**
  - `getenv`: Gets an environment variable.

  ```c
  char *getenv(const char *name);
  ```

- **Termcap functions**
Terminal capability is a library and database used in Unix-like operating systems 
to define the capabilities and control sequences of various types of terminals. 
It allows programs to interact with different terminal types in a consistent way 
without needing to know the specifics of each terminal.
  - `tgetent`: Loads a terminal entry from the termcap database.
  - `tgetflag`: Gets a boolean entry from the termcap database.
  - `tgetnum`: Gets a numeric entry from the termcap database.
  - `tgetstr`: Gets a string entry from the termcap database.
  - `tgoto`: Computes a cursor movement string.
  - `tputs`: Outputs a terminal string with padding.

  ```c
  int tgetent(char *bp, const char *name);
  int tgetflag(const char *id);
  int tgetnum(const char *id);
  char *tgetstr(const char *id, char **area);
  char *tgoto(const char *cap, int col, int row);
  int tputs(const char *str, int affcnt, int (*putc)(int));
  ```

---

```c
char *readline(const char *prompt);
void rl_clear_history(void);
void rl_on_new_line(void);
void rl_replace_line(const char *text, int clear_undo);
void rl_redisplay(void);
void add_history(const char *line);

int printf(const char *format, ...);
char *strerror(int errnum);
void perror(const char *s);

ssize_t write(int fd, const void *buf, size_t count);
int access(const char *pathname, int mode);
int open(const char *pathname, int flags, ...);
ssize_t read(int fd, void *buf, size_t count);
int close(int fd);

pid_t fork(void);
pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *wstatus, int options);
pid_t wait3(int *wstatus, int options, struct rusage *rusage);
pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);
void exit(int status);
int execve(const char *pathname, char *const argv[], char *const envp[]);

void (*signal(int signum, void (*handler)(int)))(int);
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
int kill(pid_t pid, int sig);

int chdir(const char *path);
int stat(const char *pathname, struct stat *statbuf);
int lstat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);
int unlink(const char *pathname);
int dup(int oldfd);
int dup2(int oldfd, int newfd);
int pipe(int pipefd[2]);

char *getcwd(char *buf, size_t size);
DIR *opendir(const char *name);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);

int isatty(int fd);
char *ttyname(int fd);
int ttyslot(void);
int ioctl(int fd, unsigned long request, ...);
int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
int tcgetattr(int fd, struct termios *termios_p);

char *getenv(const char *name);

int tgetent(char *bp, const char *name);
int tgetflag(const char *id);
int tgetnum(const char *id);
char *tgetstr(const char *id, char **area);
char *tgoto(const char *cap, int col, int row);
int tputs(const char *str, int affcnt, int (*putc)(int));
```

---

### Readline Functions

```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    // Read a line of input from the user
    input = readline("Enter something: ");
    if (input && *input) {
        // Add the input to the history
        add_history(input);
    }

    // Replace the current line with a new text
    rl_replace_line("New text", 1);

    // Inform readline that the cursor is on a new line
    rl_on_new_line();

    // Redisplay the current line
    rl_redisplay();

    // Clear the readline history
    rl_clear_history();

    // Free the input
    free(input);

    return 0;
}

/*
Tested functions:
- readline
- add_history
- rl_replace_line
- rl_on_new_line
- rl_redisplay
- rl_clear_history

Functions still to be tested:
- None
*/
```

### File Operations

```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main() {
    int fd;
    char buffer[100];

    // Check file accessibility
    if (access("example.txt", F_OK) == -1) {
        perror("File does not exist");
        return 1;
    }

    // Open a file
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    // Get file status
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("Failed to get file status");
        close(fd);
        return 1;
    }

    // Read data from the file
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("Failed to read file");
        close(fd);
        return 1;
    }

    // Null-terminate the buffer and print it
    buffer[bytes_read] = '\0';
    printf("File content: %s\n", buffer);

    // Close the file
    close(fd);

    return 0;
}

/*
Tested functions:
- access
- open
- fstat
- read
- close

Functions still to be tested:
- write
- stat
- lstat
- unlink
*/
```

### Process Control

```c
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Failed to fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process\n");
        execlp("ls", "ls", NULL);
        perror("Failed to exec");
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}

/*
Tested functions:
- fork
- waitpid
- execlp
- exit

Functions still to be tested:
- wait
- wait3
- wait4
- execve
*/
```

### Signal Handling

```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_signal(int signal) {
    printf("Received signal %d\n", signal);
}

int main() {
    // Set a signal handler for SIGINT
    signal(SIGINT, handle_signal);

    // Wait for a signal
    printf("Waiting for SIGINT (Ctrl+C)...\n");
    pause();

    return 0;
}

/*
Tested functions:
- signal

Functions still to be tested:
- sigaction
- kill
*/
```

### Directory Operations

```c
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    char cwd[1024];

    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    // Open a directory stream
    dir = opendir(".");
    if (!dir) {
        perror("Failed to open directory");
        return 1;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL) {
        printf("Found file: %s\n", entry->d_name);
    }

    // Close the directory stream
    closedir(dir);

    return 0;
}

/*
Tested functions:
- getcwd
- opendir
- readdir
- closedir

Functions still to be tested:
- None
*/
```

### Terminal Control

```c
#include <unistd.h>
#include <stdio.h>
#include <termios.h>

int main() {
    struct termios term;

    // Check if the file descriptor refers to a terminal
    if (isatty(STDIN_FILENO)) {
        printf("stdin is a terminal\n");
    } else {
        printf("stdin is not a terminal\n");
    }

    // Get the terminal attributes
    if (tcgetattr(STDIN_FILENO, &term) == -1) {
        perror("Failed to get terminal attributes");
        return 1;
    }

    // Modify the terminal attributes (e.g., disable echo)
    term.c_lflag &= ~ECHO;
    if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1) {
        perror("Failed to set terminal attributes");
        return 1;
    }

    printf("Echo disabled. Type something: ");
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    printf("\nYou typed: %s\n", buffer);

    // Restore the terminal attributes
    term.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    return 0;
}

/*
Tested functions:
- isatty
- tcgetattr
- tcsetattr

Functions still to be tested:
- ttyname
- ttyslot
- ioctl
*/
```

### Environment

```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    // Get an environment variable
    char *path = getenv("PATH");
    if (path) {
        printf("PATH: %s\n", path);
    } else {
        printf("PATH not set\n");
    }

    return 0;
}

/*
Tested functions:
- getenv

Functions still to be tested:
- None
*/
```

### Termcap Functions

```c
#include <termcap.h>
#include <stdio.h>

int main() {
    char term_buffer[2048];
    char *term_type = getenv("TERM");

    if (!term_type) {
        fprintf(stderr, "TERM environment variable not set\n");
        return 1;
    }

    // Load a terminal entry from the termcap database
    if (tgetent(term_buffer, term_type) != 1) {
        fprintf(stderr, "Could not access the termcap database\n");
        return 1;
    }

    // Get a string entry from the termcap database
    char *clear_screen = tgetstr("cl", NULL);
    if (clear_screen) {
        printf("Clear screen sequence: %s\n", clear_screen);
    } else {
        printf("Clear screen sequence not found\n");
    }

    return 0;
}

/*
Tested functions:
- tgetent
- tgetstr

Functions still to be tested:
- tgetflag
- tgetnum
- tgoto
- tputs
*/
```