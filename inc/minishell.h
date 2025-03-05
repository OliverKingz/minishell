/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:03:32 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/05 15:19:10 by ozamora-         ###   ########.fr       */
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

# define READ_END 0
# define WRITE_END 1

# define SYNTAX_ERR "❌ syntax error\n"

# define ERR_SYNTAX "bash: syntax error near unexpected token" //	syntax error near unexpected token	-> bash: syntax error near unexpected token `newline', `|',  `>', etc
# define ERR_COMMAND ": command not found\n" //Comando inexistente	-> command: command not found
# define ERR_IDENTIF "not a valid identifier" //Variable inválida en export	-> export: 'var': not a valid identifier
# define ERR_PERMISSION ": permission denied" //Permiso denegado	-> filename: Permission denied
# define ERR_F_OR_D	": no such file or directory" //cd/cat: folder: No such file or directory

//Redirección sin archivo	-> bash: syntax error near unexpected token 'newline'
//add ERR_MSG

//Archivo no ejecutable	-> file: Exec format error
//add ERR_MSG

/* ************************************************************************** */

extern int g_sign;

/* ************************************************************************** */

#endif