/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:07:03 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/07 17:14:12 by ozamora-         ###   ########.fr       */
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
	t_shell	*mini_sh;
	int		exit_status;

	(void)argv;
	if (argc != 1)
		(ft_puterr("Usage: ./minishell"), exit(EXIT_FAILURE));
	mini_sh = create_shell(env);
	if (!mini_sh)
		return (EXIT_FAILURE);
	exit_status = loop_shell(mini_sh);
	return(exit_status);
}
