/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:36:12 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/24 12:37:15 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm_hdoc_files(t_shell *mini_sh)
{
	char	*file;
	char	*num;
	char	*err;
	int		i;

	i = 0;
	while (i < mini_sh->input->hdoc_count)
	{
		num = ft_itoa(i);
		file = ft_strjoin("hdoc_minish", num);
		if (unlink(file) == -1 && g_signal != SIGINT)
		{
			err = ft_strjoin("Error deleting: ", file);
			perror(err);
			my_free((void **)&err);
			mini_sh->exit_code = 1;
		}
		my_free((void **)&num);
		my_free((void **)&file);
		i++;
	}
}
