/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:15:01 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/26 02:18:20 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_strchr_pos(const char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	my_strnstr_pos(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_length;

	little_length = ft_strlen(little);
	if (little_length == 0)
		return (0);
	i = 0;
	while (big[i] && i + little_length <= len)
	{
		if (ft_strncmp(&big[i], little, little_length) == 0)
			return (i);
		i++;
	}
	return (-1);
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
