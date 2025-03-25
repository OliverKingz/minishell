/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:36:12 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/25 22:18:28 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm_hdoc_files(t_shell *mini_sh)
{
	char	*file;
	char	*num;
	int		i;

	i = 0;
	while (i < mini_sh->input->hdoc_count)
	{
		num = ft_itoa(i);
		file = ft_strjoin("hdoc_minish", num);
		unlink(file);
		my_free((void **)&num);
		my_free((void **)&file);
		i++;
	}
}
