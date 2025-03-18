/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:00:01 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/18 23:15:18 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_pwd(t_shell *mini_sh, t_cmd *cmd)
{
	int		exit_code;
	char	buffer[1024];

	(void)mini_sh;
	(void)cmd;
	exit_code = EXIT_SUCCESS;
	if (getcwd(buffer, sizeof(buffer)) != NULL)
		ft_putendl_fd(buffer, STDOUT_FILENO);
	else
		(perror("pwd"), exit_code = EXIT_FAILURE);
	return (exit_code);
}
