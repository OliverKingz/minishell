/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:41:39 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/17 15:48:34 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_atoi_circular(const char *nptr, int min, int max)
{
	int	nbr;
	int	range;

	nbr = ft_atoi(nptr);
	range = max - min + 1;
	if (nbr < min)
		nbr = nbr + range * ((min - nbr) / range + 1);
	else if (nbr > max)
		nbr = nbr - range * ((nbr - max) / range + 1);
	return (nbr);
}


int	bi_exit(t_shell *mini_sh, t_token *node)
{
	char	**args;
	int		argc;
	int		exit_code;

	args = get_args(node);
	argc = 1 + count_token_type(node, CMD_ARG);
	if (!args)
		return (2); //Consultar
	printf("exit\n");
	if (argc == 1)
		exit_code = EXIT_SUCCESS;
	else if (argc == 2)
	{
		if (ft_issigned_nbr(args[1]))
			exit_code = my_atoi_circular(args[1], 0, 255);
		else
			exit_code = STDERR_FILENO;
	}
	else
		(exit_code = EXIT_FAILURE, ft_puterr("exit"), ft_puterr(ERR_ARGS));
	(my_free2d((void ***)&args), free_shell(mini_sh), exit(exit_code));
	return (exit_code);
}
