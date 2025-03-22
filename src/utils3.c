/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:54:45 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/22 23:54:47 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_close(int *fd)
{
	if (*fd != -1 && *fd != STDOUT_FILENO && *fd != STDIN_FILENO)
		close(*fd);
	*fd = -1;
}

char	*my_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*joined;
	int		s1_len;
	int		s2_len;
	int		s3_len;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3_len = ft_strlen(s3);
	joined = (char *)ft_calloc((s1_len + s2_len + s3_len + 1), sizeof(char));
	if (!joined)
		return (ft_puterr("str calloc"), NULL);
	i = -1;
	while (++i < s1_len)
		joined[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		joined[s1_len + i] = s2[i];
	i = -1;
	while (++i < s3_len)
		joined[s1_len + s2_len + i] = s3[i];
	joined[s1_len + s2_len + s3_len] = '\0';
	return (joined);
}

char	*my_strjoin4(char const *s1, char const *s2, char const *s3,
		char const *s4)
{
	char	*joined;
	char	*aux;

	joined = ft_strjoin(s1, s2);
	aux = ft_strjoin(joined, s3);
	my_free((void **)&joined);
	joined = ft_strjoin(aux, s4);
	my_free((void **)&aux);
	return (joined);
}
