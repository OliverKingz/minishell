/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:55 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/13 15:57:32 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	*handle_ctrl_c(int signal_sigint, t_shell *mini_sh)
// {
// 	ft_putstr_fd("\n", STDIN_FILENO);
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	rl_redisplay();
// 	mini_sh->last_exit_status = 128 + SIGINT;
// 	g_sign = signal_sigint;
// 	return (NULL);
// }

// void	*handle_ctrl_backslash(int signal_sigquit)
// {
// 	(void)signal_sigquit;
// }

// void	set_signals(t_shell *mini_sh)
// {
// 	signal(SIGINT, handle_ctrl_c(SIGINT, mini_sh));
// 	// signal(SIGQUIT, handle_ctrl_backslash);
// }