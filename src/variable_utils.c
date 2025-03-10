/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:26:28 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/10 20:51:21 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

/*
En memoria de esta fncion que solo causó bugs
char	*my_replace(char *og, char *target, char *rep)
{
	char	*s;
	char	*temp;

	if (!og || !target || !rep)
		return (NULL);
	s = ft_strdup(og);
	while(s && ft_strnstr(s, target, ft_strlen(s)))
	{
		temp = s;
		s = my_replace_first(temp, target, rep);
		free(temp);
	}
	return (s);
}
*/

size_t	my_strlen_word(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_isalnum(s[i]))
		i++;
	return (i);
}

void	my_skip(char **s, char c)
{
	if (!s || !*s)
		return ;
	while (**s && **s != c)
		(*s)++;
}

char	*extract_first_var(char *s)
{
	size_t	size;
	char	*var;
	bool	is_double_quote;

	if (!s)
		return (NULL);
	is_double_quote = false;
	while (*s)
	{
		if (*s == '\'' && !is_double_quote)
		{
			s++;
			my_skip(&s, '\'');
		}
		else if (*s == '$' && s[1] != '\0' && ft_isalnum(s[1]))
		{
			size = my_strlen_word(&s[1]);
			var = ft_substr(s, 0, size + 1);
			return (var);
		}
		else if (*s == '\"')
			is_double_quote = !is_double_quote;
		s++;
	}
	return (NULL);
}

char	*expand_vars(char *og, t_env *node)
{
	char	*var;
	char	*value;
	char	*str;
	char	*temp;

	str = ft_strdup(og);
	while (1)
	{
		var = extract_first_var(str);
		if (!var)
			break ;
		value = my_getenv(node, &var[1]);
		temp = str;
		if (value)
			str = my_replace_first(temp, var, value);
		else
			str = my_replace_first(temp, var, "");
		free(temp);
		free(var);
	}
	return (str);
}

// int	main(int argc, char **args, char **env)
// {
// 	char	*s;
// 	t_env	*node;

// 	(void)argc;
// 	(void)args;
// 	node = init_envlist(env);
// 	s = expand_vars("hola '$USER'$USER :) \n", node);
// 	ft_putstr_fd(s, STDOUT_FILENO);
// 	free(s);
// 	clear_envlist(&node);
// 	return (0);
// }
