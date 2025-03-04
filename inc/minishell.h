/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:03:32 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/04 19:45:07 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */

# include "libft.h"

// Includes already at libft.h
//# include <stdio.h>  // printf, perror
//# include <stdlib.h> // malloc, free, exit
//# include <unistd.h> // write, access, open, read, close, fork, getcwd, chdir
					   // unlink, execve, dup, dup2, pipe
					   // isatty, ttyname, ttyslot, getenv

# include <string.h>            // strerror
# include <readline/history.h>  // add_history
# include <readline/readline.h> // readline, rl_clear_history
								// rl_on_new_line, rl_replace_line, rl_redisplay

# include <curses.h>    // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <dirent.h>    // opendir, readdir, closedir
# include <signal.h>    // signal, sigaction, kill
# include <sys/ioctl.h> // ioctl
# include <sys/stat.h>  // stat, lstat, fstat
# include <sys/wait.h>  // wait, waitpid, wait3, wait4
# include <termios.h>   // tcsetattr, tcgetattr

/* ************************************************************************** */
/*
- Readline functions
readline: Reads a line of input from the user.
rl_clear_history: Clears the readline history list.
rl_on_new_line: Informs readline that the cursor is on a new line.
rl_replace_line: Replaces the contents of the current line with the given text.
rl_redisplay: Redisplays the current line.
add_history: Adds a line to the readline history.

// char			*readline(const char *prompt);
// void			rl_clear_history(void);
// void			rl_on_new_line(void);
// void			rl_replace_line(const char *text, int clear_undo);
// void			rl_redisplay(void);
// void			add_history(const char *line);

- Standard I/O functions
printf: Prints formatted output to stdout.
perror: Prints a description of the last error.

// int				printf(const char *format, ...);
// void			perror(const char *s);

- Memory management functions
malloc: Allocates memory dynamically.
free: Frees dynamically allocated memory.

// void			*malloc(size_t size);
// void			free(void *ptr);

- File operations
write: Writes data to a file descriptor.
access: Checks a file's accessibility.
open: Opens a file.
read: Reads data from a file descriptor.
close: Closes a file descriptor.
stat: Gets file status.
lstat: Gets file status, not following symbolic links.
fstat: Gets file status of an open file descriptor.
unlink: Deletes a name from the filesystem.

// ssize_t			write(int fd, const void *buf, size_t count);
// int				access(const char *pathname, int mode);
// int				open(const char *pathname, int flags, ...);
// ssize_t			read(int fd, void *buf, size_t count);
// int				close(int fd);

- Process control
fork: Creates a new process by duplicating the calling process.
wait: Waits for a child process to change state.
waitpid: Waits for a specific child process to change state.
wait3: Waits for a child process to change state with resource usage information.
wait4: Waits for a specific child process to change state with resource usage information.
execve: Executes a program.
exit: Terminates the calling process.

// pid_t			fork(void);
// pid_t			wait(int *wstatus);
// pid_t			waitpid(pid_t pid, int *wstatus, int options);
// pid_t			wait3(int *wstatus, int options, struct rusage *rusage);
// pid_t			wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);
// void			exit(int status);
// int				execve(const char *pathname, char *const argv[], char *const envp[]);

- Signal handling
signal: Sets a signal handler for a specific signal.
sigaction: Examines and changes a signal action.
kill: Sends a signal to a process or a group of processes.

// void (*signal(int signum, void (*handler)(int)))(int);
// int				sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
// int				kill(pid_t pid, int sig);

- Directory operations
getcwd: Gets the current working directory.
opendir: Opens a directory stream.
readdir: Reads a directory entry.
closedir: Closes a directory stream.

// char			*getcwd(char *buf, size_t size);
// DIR				*opendir(const char *name);
// struct dirent	*readdir(DIR *dirp);
// int				closedir(DIR *dirp);

- Terminal control
isatty: Tests whether a file descriptor refers to a terminal.
ttyname: Returns the name of the terminal associated with a file descriptor.
ttyslot: Returns the index of the current user's terminal.
ioctl: Manipulates the underlying device parameters of special files.
tcsetattr: Sets the parameters associated with the terminal.
tcgetattr: Gets the parameters associated with the terminal.

// int				isatty(int fd);
// char			*ttyname(int fd);
// int				ttyslot(void);
// int				ioctl(int fd, unsigned long request, ...);
// int				tcsetattr(int fd, int optional_actions, const struct termios *termios_p);
// int				tcgetattr(int fd, struct termios *termios_p);

- Environment
getenv: Gets an environment variable.

// char			*getenv(const char *name);

- Termcap functions
tgetent: Loads a terminal entry from the termcap database.
tgetflag: Gets a boolean entry from the termcap database.
tgetnum: Gets a numeric entry from the termcap database.
tgetstr: Gets a string entry from the termcap database.
tgoto: Computes a cursor movement string.
tputs: Outputs a terminal string with padding.

// int				tgetent(char *bp, const char *name);
// int				tgetflag(const char *id);
// int				tgetnum(const char *id);
// char			*tgetstr(const char *id, char **area);
// char			*tgoto(const char *cap, int col, int row);
// int				tputs(const char *str, int affcnt, int (*putc)(int));

*/

/* ************************************************************************** */

#endif