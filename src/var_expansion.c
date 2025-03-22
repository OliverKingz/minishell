/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:26:28 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/23 00:02:08 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mark_variables(char *s)
{
	bool	is_double_quote;

	if (!s)
		return ;
	is_double_quote = false;
	while (*s)
	{
		if (*s == '\'' && !is_double_quote)
		{
			s++;
			my_skip(&s, '\'');
		}
		else if (*s == '$' && (ft_isalpha(s[1]) || ft_strchr("_?", s[1])))
			*s = -1;
		else if (*s == '\"')
			is_double_quote = !is_double_quote;
		s++;
	}
}

char	*extract_first_var(char *s)
{
	size_t	size;
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
		else if (*s == -1 && s[1] == '?')
			return (ft_strdup("\xFF?"));
		else if (*s == -1 && (ft_isalpha(s[1]) || s[1] == '_'))
		{
			size = my_strlen_idname(&s[1]);
			return (ft_substr(s, 0, size + 1));
		}
		else if (*s == '\"')
			is_double_quote = !is_double_quote;
		s++;
	}
	return (NULL);
}

char	*expand_vars(char *og, t_shell *mini_sh)
{
	char	*var;
	char	*value;
	char	*str;
	char	*temp;

	str = ft_strdup(og);
	mark_variables(str);
	while (1)
	{
		var = extract_first_var(str);
		if (!var)
			break ;
		if (ft_strncmp(var, "\xFF?", -1) == 0)
			value = ft_itoa(mini_sh->exit_code);
		else
			value = ft_strdup(my_getenv(mini_sh->env, &var[1]));
		temp = str;
		if (value)
			str = my_replace_first(temp, var, value);
		else
			str = my_replace_first(temp, var, "");
		(my_free((void **)&temp), my_free((void **)&var));
		my_free((void **)&value);
	}
	return (str);
}
