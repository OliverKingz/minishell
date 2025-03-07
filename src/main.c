/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:07:03 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/07 15:21:14 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* int	main(int argc, char **argv, char **env)
{
	char	*line;

	while (1)
	{
		line = readline("Minishell > ");
		if (!line)
			break ;
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
 */

/* int	main(int argc, char **argv, char **env)
{
	t_envnode *start = NULL;

	(void)argc;
	(void)argv;	
	init_envlist(env, &start);

	while (start)
	{
		printf("%s=%s, ", start->name, start->value);
		start = start->next;
	}
	printf("\n");
	return (0);
}
 */

int	main(int argc, char **argv, char **env)
{
	t_shell	mini_sh;

	(void)argv;
	if (argc != 1)
		(ft_puterr("Usage: ./minishell"), exit(EXIT_FAILURE));
	create_shell(&mini_sh, env);
	loop_shell(&mini_sh);
	free_shell(&mini_sh);
	return(mini_sh.last_exit_status);
}
