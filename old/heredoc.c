/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:48:01 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/05 14:28:32 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_hdoc(t_program *program)
{
	int			i;
	t_pipe		pipe1;
	t_tokens	*token;

	token = program->start_token;
	program->heredocs = (int *) ft_calloc(program->hdoc_cont, sizeof(int));
	program->hdoc_used = 0;
	i = 0;
	while(token && g_sign != SIGINT)
	{
		if (token->type == redir_l_d && token->next->type == heredoc_delimiter)
		{
			pipe(pipe1);
			ft_hdoc(token->next->content, pipe1);
			ft_close_fd(pipe1[WRITE_END]);
			program->heredocs[i] = pipe1[READ_END];
			i++;
		}
		token = token->next;
		wait(NULL);
	}	
}

void	ft_hdoc(char *limiter, t_pipe pipe_hdoc)
{
	pid_t	pid;
	char	*line;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		ft_close_fd(pipe_hdoc[READ_END]);
		line = readline("> ");
		while (line && !(ft_strncmp(line, limiter, -1) == 0))
		{
			ft_putstr_fd(line, pipe_hdoc[WRITE_END]);
			ft_putchar_fd('\n', pipe_hdoc[WRITE_END]);
			free(line);
			line = readline("> ");
		}
		if (!line)
			ft_putstr_fd("minishell: warning: here-document delimited by end-of-file\n", 2); //Arreglar mensaje de error
		else
			free(line);
		ft_close_fd(pipe_hdoc[WRITE_END]);
		exit (0);
	}
}
