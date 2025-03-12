/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:26:28 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/12 16:30:02 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
