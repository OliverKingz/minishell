/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:56:59 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/21 15:08:20 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redirections(t_token *node, t_cmd *cmd)
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

void	hdoc_child(t_shell *mini_sh, char *limiter, int id)
{
	int		fd;
	char	*line;
	pid_t	pid;

	pid = fork();
	if (pid != 0)
		return ;
	rl_catch_signals = 0;
	signal(SIGINT, hdoc_child_ctrl_c);
	fd = create_hdoc_file(id);
	while (g_signal != SIGINT)
	{
		line = readline("> ");
		if (!line)
			break ;
		else if (ft_strncmp(limiter, line, -1) == 0)
			break ;
		else
			ft_putendl_fd(line, fd);
		my_free((void **)&line);
	}
	free_shell(mini_sh);
	my_close(&fd);
	exit(0);
}

void	handle_heredocs(t_shell *mini_sh)
{
	int		id;
	t_token	*node;
	
	id = 0;
	node = mini_sh->input->token_lst;
	signal(SIGINT, hdoc_parent_ctrl_c);
	while (node && g_signal != SIGINT)
	{
		if (node->type == REDIR_HD)
		{
			hdoc_child(mini_sh, node->next->content, id++);
			wait(NULL);
		}
		node = node->next;
	}
	signal(SIGINT, handle_ctrl_c);
}
