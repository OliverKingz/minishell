/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:03:32 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/09 02:15:52 by ozamora-         ###   ########.fr       */
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
# include <errno.h>     // to use errno

/* ************************************************************************** */

# define PROMPT "\001\033[1;32m\002Minishell > \001\033[0m\002"

# define READ_END 0
# define WRITE_END 1

# define TRUE 1
# define FALSE 0

# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2

# define ERR_SYNTAX "syntax error\n"
# define ERR_SYNTAX_NL "syntax error near unexpected token `newline'\n"
# define ERR_COMMAND ": command not found\n"
# define ERR_PERMISSION ": permission denied\n"
# define ERR_FILE_DIR ": no such file or directory\n"

/* ************************************************************************** */

extern int			g_sign;

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
	LIMITER,
	S_QUOTE,
	D_QUOTE
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
	char			*cmd_path;
	char			**cmd_args;
}					t_cmd;

typedef struct s_input
{
	char			*read_line;
	t_token			*token_lst;
	int				cmd_count;
	int				hdoc_count;
	int				*heredocs;
	pid_t			*pid;
}					t_input;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_shell
{
	t_input			*input;
	t_env			*env;
	int				last_exit_status;
}					t_shell;

/* ************************************************************************** */

t_input				*init_input(t_shell *mini_sh, char *read_line);
void				free_input(t_shell *mini_sh);

t_shell				*create_shell(char **env);
int					loop_shell(t_shell *mini_sh);
void				free_shell(t_shell *mini_sh);

char				*my_getenv(t_env *start, char *name);
t_env				*create_envnode(char *name, char *value);
t_env				*init_envlist(char **env);
void				addback_envnode(t_env **start, t_env *node);
void				print_envlist(t_env *start);
void				clear_envnode(t_env *node);
void				clear_envlist(t_env **start);

void				my_perr(const char *msg, bool should_exit, int exit_status);
void				my_free(void **mem);
int					my_strchr_pos(const char *s, char c);

bool	validate_rline_syntax(char *read_line);
void	count_cmds_heredocs(t_shell **mini_sh);

void	tokenize(t_shell *mini_sh);
void	classify_word_token(t_shell *mini_sh);
void	classify_condition(t_token *current, int *last_type, bool *single_cmd);

void	handle_quotes(t_shell *mini_sh, char *current, int i[2], int *state); // Falta var_exp
void	handle_redir(t_shell *mini_sh, char *current, int i[2], int *state);
void	handle_pipe_space(t_shell *mini_sh, char *current, int i[2], int *state);
//void	handle_var_expansion(t_shell *mini_sh, char *current, int i[2], int *state); // Falta hacer

t_token				*create_token(char *content, t_type token_type);
t_token				*init_tokenlist(t_shell *mini_sh);
void				addback_token(t_shell *mini_sh, char *content, t_type token_type);
void				print_tokenslist(t_token *token_lst);
void				print_tokenslist_short(t_token *token_lst);
void				clear_tokenlist(t_token **token_lst);

#endif