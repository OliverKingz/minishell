/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:26:28 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/26 02:15:22 by ozamora-         ###   ########.fr       */
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

void	revert_mark_variables(char *s)
{
	char	quote;

	while (*s)
	{
		skip_in_quotes(&s);
		if (ft_strnstr(s, "<<", 2))
		{
			s += 2;
			while (*s && ft_isspace(*s))
				s++;
			quote = 0;
			while (*s && !(ft_isspace(*s) && !quote))
			{
				if (!quote && (*s == '\'' || *s == '\"'))
					quote = *s;
				else if (*s == quote)
					quote = 0;
				else if (*s == -1)
					*s = '$';
				s++;
			}
		}
		if (*s)
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
