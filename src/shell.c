/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:41 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/06 16:03:57 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				create_shell(t_shell *mini_sh);
t_shell				*init_shell(t_shell *mini_sh);
void				free_shell(t_shell *mini_sh);

t_shell				*init_shell(t_shell *mini_sh)
{
	mini_sh->input = (t_input *)ft_calloc(1, sizeof(t_input));
	if (!mini_sh->input)
		return (NULL);
	mini_sh->env = NULL;
	mini_sh->last_exit_status = 0;
	return (mini_sh);
}

void				create_shell(t_shell *mini_sh)
{
	char *line;
	mini_sh = init_shell(mini_sh);
	while (1)
	{
		line = readline("Minishell > ");
		mini_sh->input = init_input(mini_sh, line);
		if (!line)
			break ;
		printf("%s\n", mini_sh->input->read_line);
	}
	free_shell(mini_sh);
}

void free_shell(t_shell *mini_sh)
{
	if (mini_sh->input)
	{
		if (mini_sh->input->read_line)
			free(mini_sh->input->read_line);
		free(mini_sh->input);
	}
}
