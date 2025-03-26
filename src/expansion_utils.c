/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:15:09 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/26 02:18:28 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_in_quotes(char **s)
{
	char	quote;

	if (**s == '\'' || **s == '\"')
	{
		quote = **s;
		(*s)++;
		my_skip(s, quote);
	}
}

void	my_skip(char **s, char c)
{
	if (!s || !*s)
		return ;
	while (**s && **s != c)
		(*s)++;
}

size_t	my_strlen_idname(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (ft_isalnum(s[i]) || ft_strchr("_", s[i])))
		i++;
	return (i);
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
		return (ft_puterr("str calloc"), NULL);
	ft_memcpy(s, og, pos);
	ft_memcpy(&s[pos], rep, ft_strlen(rep));
	ft_memcpy(&s[pos + ft_strlen(rep)], &og[pos + ft_strlen(target)],
		ft_strlen(&og[pos + ft_strlen(target)]));
	return (s);
}
