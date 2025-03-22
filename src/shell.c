/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:41 by ozamora-          #+#    #+#             */
/*   Updated: 2025/03/22 22:56:31 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	loop_shell(t_shell *mini_sh)
{
	char	*read_line;
	int		loop_status;

	set_signals();
	while (1)
	{
		read_line = readline(PROMPT);
		set_signal_errors(mini_sh);
		loop_status = handle_readline_input(mini_sh, &read_line);
		if (loop_status == BREAK_LOOP)
			break ;
		else if (loop_status == CONTINUE_LOOP)
			continue ;
		handle_heredocs(mini_sh);
		print_tokenslist_short(mini_sh->input->token_lst);
		execution(mini_sh);
		rm_hdoc_files(mini_sh);
		(my_free((void **)&read_line), free_input(&mini_sh));
	}
	ft_putendl_fd("exit", STDOUT_FILENO);
	return (mini_sh->exit_code);
}

int	handle_readline_input(t_shell *mini_sh, char **readline)
{
	if (!readline || !*readline)
		return (BREAK_LOOP);
	if (ft_strncmp(*readline, "", -1) == 0)
		return (CONTINUE_LOOP);
	else
		add_history(*readline);
	if (!validate_rline_syntax(*readline))
		return (my_free((void **)readline), CONTINUE_LOOP);
	mini_sh->input = init_input(mini_sh, *readline);
	if (!mini_sh->input)
		return (my_free((void **)readline), CONTINUE_LOOP);
	return (OKAY_LOOP);
}

int	loop_shell_non_interactive(t_shell *mini_sh)
{
	char	*read_line;
	char	*temp;
	int		loop_status;

	while (1)
	{
		temp = get_next_line(STDIN_FILENO);
		read_line = my_replace_first(temp, "\n", "\0");
		my_free((void **)&temp);
		loop_status = handle_readline_input(mini_sh, &read_line);
		my_free((void **)&read_line);
		if (loop_status == BREAK_LOOP)
			break ;
		else if (loop_status == CONTINUE_LOOP)
			continue ;
		handle_heredocs(mini_sh);
		execution(mini_sh);
		rm_hdoc_files(mini_sh);
		(my_free((void **)&read_line), free_input(&mini_sh));
	}
	return (mini_sh->exit_code);
}

t_shell	*create_shell(char **env)
{
	t_shell	*mini_sh;

	mini_sh = (t_shell *)ft_calloc(1, sizeof(t_shell));
	if (!mini_sh)
		return (my_perr("create mini_sh", false, errno), NULL);
	mini_sh->exit_code = 0;
	mini_sh->input = NULL;
	mini_sh->env = init_envlist(env);
	if (!mini_sh->env)
		init_emergency_env(mini_sh);
	increase_shlvl(mini_sh);
	return (mini_sh);
}

void	free_shell(t_shell *mini_sh)
{
	if (!mini_sh)
		return ;
	if (mini_sh->input)
		free_input(&mini_sh);
	if (mini_sh->env)
		clear_envlist(&(mini_sh->env));
	my_free((void **)&mini_sh);
}
