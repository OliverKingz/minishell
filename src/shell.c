/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:41 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/07 15:22:43 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_shell(t_shell *mini_sh, char **env)
{
	mini_sh = (t_shell *)ft_calloc(1, sizeof(t_shell));
	if (!mini_sh)
		my_perr("Failed to malloc mini_sh", true);
	mini_sh->env = env;
	mini_sh->last_exit_status = 0;
	mini_sh->input = NULL;
}

void	loop_shell(t_shell *mini_sh)
{
	char	*line;

	while (1)
	{
		line = readline("Minishell > ");
		mini_sh->input = init_input(mini_sh, &line);
		if (!line)
			break ;
		ft_printf("%s\n", mini_sh->input->read_line);
	}
}

void	free_shell(t_shell *mini_sh)
{
	if (!mini_sh)
		return ;
	if (mini_sh->input)
		free_input(mini_sh);
	(free(mini_sh), mini_sh = NULL);
}
