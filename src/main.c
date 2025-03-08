/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:07:03 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/08 16:44:21 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* int	main(int argc, char **argv, char **env)
{
	t_envnode *start = NULL;

	(void)argc;
	(void)argv;	
	init_envlist(env, &start);

	printf("%s\n", my_getenv(start, "USER"));
	clear_envlist(&start);
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
