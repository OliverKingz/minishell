/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:41 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/08 17:27:56 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*create_shell(char **env)
{
	t_shell	*mini_sh;

	mini_sh = (t_shell *)ft_calloc(1, sizeof(t_shell));
	if (!mini_sh)
		my_perr("Failed to malloc mini_sh", true, errno);
	mini_sh->env = init_envlist(env); //Mirar env de emergencia y PATH de emergencia
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
		read_line = readline("\033[1;32mMinishell > \033[0m");
		if (!read_line)
			return (ft_puterr("readline returned NULL\n"), EXIT_FAILURE); //Deberia hacer exit(2)?
		if (!validate_rline_syntax(read_line))
		{
			free(read_line);
			continue ;
		}
		mini_sh->input = init_input(mini_sh, read_line);
		if (!mini_sh->input)
			return (ft_puterr("init_input failed\n"), free_shell(mini_sh), EXIT_FAILURE);
		//ft_printf("%s\n", mini_sh->input->read_line);
		//print_tokenslist(mini_sh->input->token_lst);
		//print
		(free(read_line), free_input(mini_sh));
		mini_sh->input = NULL;
	}
	exit_status = mini_sh->last_exit_status;
	free_shell(mini_sh);
	return (exit_status);
}

void	free_shell(t_shell *mini_sh)
{
	if (!mini_sh)
		return ;
	if (mini_sh->input)
		free_input(mini_sh);
	clear_envlist(&(mini_sh->env));
	(free(mini_sh), mini_sh = NULL);
}
