/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:01:51 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/18 14:18:22 by raperez-         ###   ########.fr       */
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

int	bi_echo2(t_shell *mini_sh, t_cmd *cmd)
{
	bool	n_flag;
	int		i;

	(void)mini_sh;
	i = 1;
	n_flag = false;
	if (cmd->cmd_args[1] && ft_strncmp(cmd->cmd_args[1], "-n", 2) == 0)
		(n_flag = true, i++);
	while (cmd->cmd_args[i])
	{
		ft_putstr_fd(cmd->cmd_args[i], STDOUT_FILENO);
		if (cmd->cmd_args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (n_flag == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
