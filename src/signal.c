/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:55 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/13 23:37:05 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_ctrl_c(int signal_sigint)
{
	(void)signal_sigint;
	ft_putstr_fd("\n", STDIN_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_signal = SIGINT;
}

void	handle_ctrl_backslash(int signal_sigquit)
{
	(void)signal_sigquit;
}

void	set_signals(void)
{
	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, handle_ctrl_backslash);
}

void	set_signal_errors(t_shell *mini_sh)
{
	if (g_signal == SIGINT)
		mini_sh->last_exit_status = 128 + SIGINT;
	else if (g_signal == SIGQUIT)
		mini_sh->last_exit_status = 128 + SIGQUIT;
	g_signal = 0;
}
