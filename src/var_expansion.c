/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:26:28 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/16 12:53:00 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		else if (*s == '$' && s[1] == '?')
			return (ft_strdup("$?"));
		else if (*s == '$' && s[1] != '\0' && ft_isalnum(s[1]))
		{
			size = my_strlen_word(&s[1]);
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
	while (1)
	{
		var = extract_first_var(str);
		if (!var)
			break ;
		if (ft_strncmp(var, "$?", -1) == 0)
			value = ft_itoa(mini_sh->exit_code);
		else
			value = ft_strdup(my_getenv(mini_sh->env, &var[1]));
		temp = str;
		str = my_replace_first(temp, var, value);
		my_free((void **)&temp);
		my_free((void **)&var);
		my_free((void **)&value);
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
// 	my_free((void **)&s);
// 	clear_envlist(&node);
// 	return (0);
// }
