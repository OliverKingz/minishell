/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:26:28 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/25 12:46:40 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mark_variables(char *s, int skip_quote)
{
	bool	is_double_quote;

	if (!s)
		return ;
	is_double_quote = false;
	while (*s)
	{
		if (skip_quote && *s == '\'' && !is_double_quote)
		{
			s++;
			my_skip(&s, '\'');
		}
		else if (*s == '$' && (ft_isalpha(s[1]) || s[1] == '_' || s[1] == '?'))
			*s = -1;
		else if (*s == '\"')
			is_double_quote = !is_double_quote;
		s++;
	}
}

char	*extract_first_var(char *s)
{
	size_t	size;

	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == -1 && s[1] == '?')
			return (ft_strdup("\xFF?"));
		else if (*s == -1)
		{
			size = my_strlen_idname(&s[1]);
			return (ft_substr(s, 0, size + 1));
		}
		s++;
	}
	return (NULL);
}

void	revert_security_mark(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] == -2)
			s[i] = '\'';
		else if (s[i] == -3)
			s[i] = '\"';
		else if (s[i] == -4)
			s[i] = '|';
		else if (s[i] == -5)
			s[i] = '<';
		else if (s[i] == -6)
			s[i] = '>';
		i++;
	}
}

static void	security_mark(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			s[i] = -2;
		else if (s[i] == '\"')
			s[i] = -3;
		else if (s[i] == '|')
			s[i] = -4;
		else if (s[i] == '<')
			s[i] = -5;
		else if (s[i] == '>')
			s[i] = -6;
		i++;
	}
}

char	*expand_vars(char *og, t_shell *mini_sh, bool safe_exp)
{
	char	*var;
	char	*value;
	char	*str;
	char	*temp;

	str = ft_strdup(og);
	var = extract_first_var(str);
	while (var)
	{
		if (ft_strncmp(var, "\xFF?", -1) == 0)
			value = ft_itoa(mini_sh->exit_code);
		else
			value = ft_strdup(my_getenv(mini_sh->env, &var[1]));
		if (safe_exp)
			security_mark(value);
		temp = str;
		if (value)
			str = my_replace_first(temp, var, value);
		else
			str = my_replace_first(temp, var, "");
		(my_free((void **)&temp), my_free((void **)&var));
		my_free((void **)&value);
		var = extract_first_var(str);
	}
	return (str);
}
