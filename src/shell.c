/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:41 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/12 16:43:22 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*create_shell(char **env)
{
	t_shell	*mini_sh;

	mini_sh = (t_shell *)ft_calloc(1, sizeof(t_shell));
	if (!mini_sh)
		return (my_perr("create mini_sh", false, errno), NULL);
	mini_sh->env = init_envlist(env);
	// Mirar env de emergencia y PATH de emergencia
	// Mirar que pasa cuando init devuelve NULL
	mini_sh->last_exit_status = 0;
	mini_sh->input = NULL;
	return (mini_sh);
}

int	loop_shell(t_shell *mini_sh)
{
	char	*read_line;
	int		exit_status;

	while (1)
	{
		read_line = readline(PROMPT);
		if (!read_line)
			break ;
		if (ft_strncmp(read_line, "", -1) == 0)
			continue ;
		else
			add_history(read_line);
		if (!validate_rline_syntax(read_line))
		{
			free(read_line), read_line = NULL;
			continue ;
		}
		mini_sh->input = init_input(mini_sh, read_line);
		if (!mini_sh->input)
		{
			free(read_line), read_line = NULL;
			continue ;
		}
		print_tokenslist_short(mini_sh->input->token_lst);
		// print_envlist(mini_sh->env);
		(free(read_line), free_input(&mini_sh));
	}
	exit_status = mini_sh->last_exit_status;
	return (free_shell(mini_sh), exit_status);
}

void	free_shell(t_shell *mini_sh)
{
	if (!mini_sh)
		return ;
	if (mini_sh->input)
		free_input(&mini_sh);
	clear_envlist(&(mini_sh->env));
	free(mini_sh);
}
