/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:03:32 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/05 17:37:09 by ozamora-         ###   ########.fr       */
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

// Errores que no puedo forzar que salgan. Necesario añadir?
// file: Exec format error
// export: 'var': not a valid identifier

/* ************************************************************************** */

extern int			g_sign;

/* ************************************************************************** */

typedef enum
{
	temp,
	command,
	option,
	argument,
	pipe,
	var,
	redir_in,
	redir_out,
	redir_append,
	redir_heredoc,
	limiter
}					t_type;

typedef struct s_token
{
	char			*content;
	t_type			type;
	int				index;
	struct s_token	*next;
}					t_token;

typedef struct s_cmd
{
	int				in_fd;
	int				out_fd;
	int				close_fd[2];
	char			*route;
	char			**args;
	char			**env;
}					t_cmd;

typedef struct s_shell
{
	t_token			*token_lst;
	int				cmd_count;
	int				hdoc_count;
	int				*heredocs;
	pid_t			*pid;
	int				last_exit_status;
}					t_shell;

/* ************************************************************************** */
#endif