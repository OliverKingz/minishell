/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:56:59 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/20 19:22:11 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	man_redirections(t_token *node, t_cmd *cmd)
{
	while (node && node->type != OP_PIPE)
	{
		if (node->type == REDIR_OUT || node->type == REDIR_APP)
		{
			my_close(&(cmd->out_fd));
			if (node->type == REDIR_OUT)
				cmd->out_fd = open(node->next->content,
						O_CREAT | O_WRONLY | O_TRUNC, 0644);
			else
				cmd->out_fd = open(node->next->content,
						O_CREAT | O_WRONLY | O_APPEND, 0644);
		}
		else if (node->type == REDIR_IN || node->type == REDIR_APP)
		{
			my_close(&(cmd->in_fd));
			if (node->type == REDIR_IN)
				cmd->in_fd = open(node->next->content, O_RDONLY);
		}
		if (cmd->in_fd < 0 || cmd->out_fd < 0)
			return (perror(node->next->content), 1);
		node = node->next;
	}
	return (0);
}

int	create_hdoc_file(int id)
{
	char	*num;
	char	*file;
	int		fd;

	num = ft_itoa(id);
	file = ft_strjoin("minish_hdoc", num);
	fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		perror(file);
	my_free((void **)&num);
	my_free((void **)&file);
	return (fd);
}

pid_t	hdoc_child(t_shell *mini_sh, char *limiter, int id)
{
	int		fd;
	char	*line;
	pid_t	pid;

	pid = fork();
	if (pid != 0)
		return (pid);
	signal(SIGINT, SIG_DFL);
	fd = create_hdoc_file(id);
	while (1)
	{
		line = readline("> ");
		if (ft_strncmp(limiter, line, -1) == 0)
			break;
		else if (!line)
			break; //Falta warning
		else
			ft_putendl_fd(line, fd);
		my_free((void **)&line);
	}
	free_shell(mini_sh);
	my_close(&fd);
	exit(0);
	return (0);
}

void	man_heredocs(t_shell *mini_sh)
{
	int		id;
	t_token	*node;
	pid_t	pid;
	
	id = 0;
	node = mini_sh->input->token_lst;
	while (node)
	{
		if (node->type == REDIR_HD)
		{
			pid = hdoc_child(mini_sh, node->next->content, id++);
			waitpid(pid, NULL, 0);
		}
		node = node->next;
	}
}
