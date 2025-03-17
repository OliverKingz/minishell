/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:01:51 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/17 15:45:36 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_echo(t_shell *mini_sh, t_token *node)
{
	char	**args;
	bool	n_flag;
	int		i;

	(void)mini_sh;
	args = get_args(node);
	if (!args)
		return (2); // Consultar
	i = 1;
	n_flag = false;
	if (args[1] && ft_strncmp(args[1], "-n", 2) == 0)
		(n_flag = true, i++);
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (n_flag == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	my_free2d((void ***)&args);
	return (EXIT_SUCCESS);
}
