/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:52:55 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/22 22:58:49 by raperez-         ###   ########.fr       */
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

void	set_signals(void)
{
	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signal_errors(t_shell *mini_sh)
{
	if (g_signal == SIGINT)
		mini_sh->exit_code = 128 + SIGINT;
	g_signal = 0;
}

void	just_save_signal(int sign)
{
	g_signal = sign;
}

void	hdoc_child_ctrl_c(int sign)
{
	g_signal = sign;
	ft_putstr_fd("^C", STDOUT_FILENO);
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}
