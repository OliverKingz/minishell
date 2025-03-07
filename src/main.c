/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:07:03 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/07 13:47:48 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(void)
// {
// 	char	*line;

// 	while (1)
// 	{
// 		line = readline("Minishell > ");
// 		if (!line)
// 			break ;
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	return (0);
// }

int	main(int argc, char **argv, char **env)
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