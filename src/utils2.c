/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:15:01 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/16 12:44:53 by ozamora-         ###   ########.fr       */
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
	bool	is_double_quote;

	little_length = ft_strlen(little);
	if (little_length == 0)
		return (0);
	i = 0;
	is_double_quote = false;
	while (big[i] && i + little_length <= len)
	{
		if (big[i] == '\'' && !is_double_quote)
		{
			i++;
			while (big[i] && big[i] != '\'')
				i++;
		}
		else if (ft_strncmp(&big[i], little, little_length) == 0)
			return (i);
		else if (big[i] == '\"')
			is_double_quote = !is_double_quote;
		i++;
	}
	return (-1);
}

char	*my_replace_first(char *og, char *target, char *rep)
{
	int		pos;
	size_t	size;
	char	*s;

	if (!og || !target || !rep)
		return (NULL);
	pos = my_strnstr_pos(og, target, ft_strlen(og));
	if (pos == -1)
		return (ft_strdup(og));
	size = ft_strlen(og) - ft_strlen(target) + ft_strlen(rep);
	s = ft_calloc(size + 1, sizeof(char));
	if (!s)
		return (NULL);
	ft_memcpy(s, og, pos);
	ft_memcpy(&s[pos], rep, ft_strlen(rep));
	ft_memcpy(&s[pos + ft_strlen(rep)], &og[pos + ft_strlen(target)],
		ft_strlen(&og[pos + ft_strlen(target)]));
	return (s);
}

char	*my_replace(char *og, char *target, char *rep)
{
	char	*s;
	char	*temp;

	if (!og || !target || !rep)
		return (NULL);
	s = ft_strdup(og);
	while (s && ft_strnstr(s, target, ft_strlen(s)))
	{
		temp = s;
		s = my_replace_first(temp, target, rep);
		my_free((void **)&temp);
	}
	return (s);
}

void	my_skip(char **s, char c)
{
	if (!s || !*s)
		return ;
	while (**s && **s != c)
		(*s)++;
}
