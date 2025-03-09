/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:26:28 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/09 23:12:31 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while(s && ft_strnstr(s, target, ft_strlen(s)))
	{
		temp = s;
		s = my_replace_first(temp, target, rep);
		free(temp);
	}
	return (s);
}

size_t	my_strlen_chr(char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return(i);
}

char	*extract_first_var(char *s)
{
	int		i;
	size_t	size;
	char	*var;

	if (!s)
		return(NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] != '\0' && !ft_isspace(s[i + 1]))
		{
			size = my_strlen_chr(&s[i], ' ');
			var = ft_substr(&s[i], 0, size);
			return(var);
		}
		i++;
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
			break;
		value = my_getenv(node, &var[1]);
		temp = str;
		if (value)
			str = my_replace(temp, var, value);
		else
			str = my_replace(temp, var, "");
		free(temp);
		free(var);
	}
	return (str);
}

/*
int	main(int argc, char **args, char **env)
{
	char	*s;
	t_env	*node;

	(void)argc;
	(void)args;
	node = init_envlist(env);
	s = expand_vars("echo $USER $ hola $PWD :) \n", node);
	ft_putstr_fd(s, STDOUT_FILENO);
	free(s);
	clear_envlist(&node);
	return (0);
}
*/