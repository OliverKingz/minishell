/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:03:32 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/07 15:19:22 by ozamora-         ###   ########.fr       */
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

# include <readline/history.h>  // add_history
# include <readline/readline.h> // readline, rl_clear_history
# include <string.h>            // strerror
								// rl_on_new_line, rl_replace_line, rl_redisplay

# include <curses.h>    // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <dirent.h>    // opendir, readdir, closedir
# include <signal.h>    // signal, sigaction, kill
# include <sys/ioctl.h> // ioctl
# include <sys/stat.h>  // stat, lstat, fstat
# include <sys/wait.h>  // wait, waitpid, wait3, wait4
# include <termios.h>   // tcsetattr, tcgetattr

/* ************************************************************************** */

# define READ_END 0
# define WRITE_END 1

# define TRUE 1
# define FALSE 0

# define STDIN_FILENO 0
# define STDOUT_FILENO 1

# define ERR_SYNTAX "bash: syntax error near unexpected token\n"
# define ERR_COMMAND ": command not found\n"
# define ERR_PERMISSION ": permission denied\n"
# define ERR_FILE_DIR ": no such file or directory\n"

// bash: syntax error near unexpected token `newline'/`|'/`>'
// command: command not found
// filename: Permission denied
// cd/cat: folder: No such file or directory

/* ************************************************************************** */

extern int				g_sign;

/* ************************************************************************** */

typedef enum
{
	WORD,
	COMMAND,
	ARG,
	OP_PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APP,
	REDIR_HD,
	FILE_PATH,
	LIMITER
}						t_type;

typedef struct s_token
{
	char				*content;
	t_type				type;
	int					index;
	struct s_token		*next;
}						t_token;

typedef struct s_cmd
{
	int					in_fd;
	int					out_fd;
	int					close_fd[2];
	char				*cmd_path;
	char				**cmd_args;
}						t_cmd;

typedef struct s_input
{
	char				*read_line;
	t_token				*token_lst;
	int					cmd_count;
	int					hdoc_count;
	int					*heredocs;
	pid_t				*pid;
}						t_input;

typedef struct s_shell
{
	t_input				*input;
	char				**env;
	int					last_exit_status;
}						t_shell;

typedef struct s_envnode
{
	char				*name;
	char				*value;
	struct s_envnode	*next;
}						t_envnode;

/* ************************************************************************** */

t_input					*init_input(t_shell *mini_sh, char **read_line);
void					free_input(t_shell *mini_sh);

void					create_shell(t_shell *mini_sh, char **env);
void					loop_shell(t_shell *mini_sh);
void					free_shell(t_shell *mini_sh);

t_envnode				*create_envnode(char *name, char *value);
void					addback_envnode(t_envnode **start, t_envnode *node);
void					init_envlist(char **env, t_envnode **start);

void					my_perr(const char *msg, bool should_exit);

#endif