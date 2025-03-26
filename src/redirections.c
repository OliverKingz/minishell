/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:56:59 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/26 02:45:47 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_hdoc_file(t_shell *mini_sh, t_cmd *cmd)
{
	char	*file;
	char	*num;

	my_close(&(cmd->in_fd));
	num = ft_itoa(mini_sh->input->hdoc_used++);
	file = ft_strjoin("hdoc_minish", num);
	cmd->in_fd = open(file, O_RDONLY);
	my_free((void **)&num);
	my_free((void **)&file);
	if (cmd->in_fd < 0)
	{
		perror("error opening heredoc file");
	}
}

void	open_outfile(t_token *node, t_cmd *cmd)
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
}

void	open_infile(t_token *node, t_cmd *cmd)
{
	if (node->type == REDIR_IN)
	{
		my_close(&(cmd->in_fd));
		if (node->type == REDIR_IN)
			cmd->in_fd = open(node->next->content, O_RDONLY);
	}
}

int	handle_redirections(t_shell *mini_sh, t_token *node, t_cmd *cmd)
{
	while (node && node->type != OP_PIPE)
	{
		open_outfile(node, cmd);
		open_infile(node, cmd);
		if (cmd->in_fd < 0 || cmd->out_fd < 0)
			return (perror(node->next->content), 1);
		if (node->type == REDIR_HD)
			open_hdoc_file(mini_sh, cmd);
		if (cmd->in_fd < 0)
			return (1);
		node = node->next;
	}
	return (0);
}
