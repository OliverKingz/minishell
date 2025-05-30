/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:07:03 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/24 11:46:48 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal = 0;

int	main(int argc, char **argv, char **env)
{
	t_shell	*mini_sh;
	int		exit_code;
	int		interactive;

	(void)argv;
	if (argc != 1)
		(ft_puterr("Usage: ./minishell\n"), exit(EXIT_FAILURE));
	mini_sh = create_shell(env);
	if (!mini_sh)
		return (EXIT_FAILURE);
	interactive = isatty(STDIN_FILENO);
	if (interactive)
		exit_code = loop_shell(mini_sh);
	else
		exit_code = loop_shell_non_interactive(mini_sh);
	return (free_shell(mini_sh), exit_code);
}
