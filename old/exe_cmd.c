/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:59:32 by raperez-          #+#    #+#             */
/*   Updated: 2025/03/05 14:47:00 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Función para esperar a todos los hijos
void	ft_wait_children(t_program *program)
{
	int	i;

	i = 0;
	while (program->pid[i])
	{
		waitpid(program->pid[i], &program->last_exit_status, 0);
		i++;
	}
	program->last_exit_status = WEXITSTATUS(program->last_exit_status);
	free(program->pid);
	program->pid = NULL;
}

//Función para contar cuantos nodo de un tipo hay
int	count_node_type(t_tokens *start, t_type type)
{
	int	cont;

	cont = 0;
	while (start)
	{
		if (start->type == type)
			cont++;
		start = start->next;
	}
	return (cont);
}

//Función para encontrar un tipo de nodo
t_tokens	*find_node_type(t_tokens *start, t_type type)
{
	while (start)
	{
		if (start->type == type)
			return (start);
		start = start->next;
	}
	return (NULL);
}

void	ft_clear_cmd(t_cmd *cmd)
{
	free(cmd->route);
	ft_free(cmd->args);
}

void	ft_cmd_not_found(t_cmd cmd)
{
	char	*s;

	s = ft_strjoin(cmd.args[0], ERR_COMMAND);
	ft_putstr_fd(s, 2);
	free(s);
	ft_clear_cmd(&cmd);
	exit(127);
}

char	*ft_find_bin(char **path_array, char *name)
{
	char	*temp;

	if (access(name, X_OK) == 0)
		return (name);
	if (!path_array)
		return (NULL);
	while (*path_array)
	{
		temp = ft_strjoin_chr(*path_array, '/', name);
		if (access(temp, X_OK) == 0)
		{
			return (temp);
		}
		free(temp);
		path_array++;
	}
	return (NULL);
}

char	*find_cmd(char *name)
{
	char	*cmd_route;
	char	**path_array;

	path_array = ft_split(getenv("PATH"), ':');
	cmd_route = ft_find_bin(path_array, name);
	ft_free(path_array);
	return (cmd_route);
}

char	**man_arguments(t_tokens *token)
{
	char		**args;
	char		*brute_args;
	char		*temp;
	t_tokens	*aux;

	aux = find_node_type(token, command);
	if (aux)
		brute_args = ft_strdup(aux->content);
	else
		brute_args = NULL;
	while (aux && aux->type != pipe_type)
	{
		if (aux->type == argument)
		{
			temp = brute_args;
			brute_args = ft_strjoin_chr(temp, ' ', aux->content);
			free(temp);
		}
		aux = aux->next;
	}
	args = ft_split(brute_args, ' ');
	free(brute_args);
	return (args);
}

void	ft_close_fd(int fd)
{
	if (fd != -1 && fd != 0 && fd != 1)
		close(fd);
}

void	ft_man_redir(t_program *program, t_tokens *token, t_cmd *cmd)
{
	if (token && token->type == pipe_type)
		token = token->next;
	while (token && token->type != pipe_type)
	{
		if (token->type == redir_l_u || token->type == redir_l_d)
			ft_close_fd(cmd->in_fd);
		if (token->type == redir_l_u)
			cmd->in_fd = open(token->next->content, O_RDONLY);
		if (token->type == redir_l_d)
			cmd->in_fd = program->heredocs[program->hdoc_used++];
		if (token->type == redir_r_u || token->type == redir_r_d)
			ft_close_fd(cmd->out_fd);
		if (token->type == redir_r_u)
			cmd->out_fd = open(token->next->content, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (token->type == redir_r_d)
			cmd->out_fd = open(token->next->content, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (cmd->in_fd < 0 || cmd->out_fd < 0)
		{
			perror(token->next->content);
			exit(1);
		}
		token = token->next;
	}
}

pid_t	ft_child(t_cmd cmd, t_tokens *token, t_program *program, char **env)
{
	int		aux[2];
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		ft_close_fd(cmd.close_fd[0]);
		ft_close_fd(cmd.close_fd[1]);
		ft_man_redir(program, token, &cmd);
		if (!cmd.route && !cmd.args)
			exit(0);
		if (!cmd.route)
			ft_cmd_not_found(cmd);
		aux[0] = dup2(cmd.in_fd, 0);
		aux[1] = dup2(cmd.out_fd, 1);
		if (aux[0] == -1 || aux[1] == -1)
			exit(errno); //Falta limpiar memoria
		if (execve(cmd.route, cmd.args, env) == -1)
		{
			perror("zsh"); //Falta mensaje de error y limpiar memoria
			exit(127);
		}
	}
	return (pid);
}

t_cmd	init_default_cmd(t_tokens *token)
{
	t_cmd		cmd;
	t_tokens	*aux;

	cmd.in_fd = 0;
	cmd.out_fd = 1;
	cmd.close_fd[0] = -1;
	cmd.close_fd[1] = -1;
	aux = token;
	while (aux && aux->type != command)
		aux = aux->next;
	if (aux)
		cmd.route = find_cmd(aux->content);
	else
		cmd.route = NULL;
	cmd.args = man_arguments(token);
	return (cmd);
}

t_cmd	extract_cmd(t_tokens *token, t_pipe pipe1, t_pipe pipe2)
{
	t_cmd	cmd;

	cmd = init_default_cmd(token);
	if (token->type == pipe_type) //Chequea si lee de un pipe
	{
		cmd.in_fd = pipe1[READ_END];
		cmd.close_fd[0] = pipe1[WRITE_END];
		token = token->next;
	}
	if (find_node_type(token, pipe_type)) //Chequea si la salida va a un pipe
	{
		pipe(pipe2);
		cmd.out_fd = pipe2[WRITE_END];
		cmd.close_fd[1] = pipe2[READ_END];
	}
	return (cmd);
}

void	tokens_to_cmds(t_program *program, char **env)
{
	int			i;
	t_cmd		cmd;
	t_pipe		pipe1;
	t_pipe		pipe2;
	t_tokens	*token;

	pipe1[READ_END] = -1;
	pipe1[WRITE_END] = -1;
	pipe2[READ_END] = -1;
	pipe2[WRITE_END] = -1;
	token = program->start_token;
	i = 0;
	while (token)
	{
		cmd = extract_cmd(token, pipe1, pipe2);
		program->pid[i] = ft_child(cmd, token, program, env);
		ft_close_fd(pipe1[READ_END]);
		ft_close_fd(pipe1[WRITE_END]);
		pipe1[READ_END] = pipe2[READ_END];
		pipe1[WRITE_END] = pipe2[WRITE_END];
		token = token->next;
		while (token && token->type != pipe_type)
		{
			if (token->type == redir_l_d)
				program->hdoc_used++;
			token = token->next;
		}
		ft_clear_cmd(&cmd);
		i++;
	}
	ft_close_fd(pipe1[READ_END]);
	ft_close_fd(pipe1[WRITE_END]);
}

/*int main(int argc, char **argv, char **env)
{
	//t_program	program;
	t_tokens	*start;
	t_tokens	token0, token1, token2, token3, token4, token5, token6, token7, token8;

	token0.content = "<";
	token0.type = redir_l_u;
	token0.own_command = false;
	token0.expansion = false;
	token0.position = 0;
	token0.next = &token1;

	token1.content = "/dev/uranfdfsdfsedom";
	token1.type = path_name;
	token1.own_command = false;
	token1.expansion = false;
	token1.position = 1;
	token1.next = &token2;

	token2.content = "xxd";
	token2.type = command;
	token2.own_command = false;
	token2.expansion = false;
	token2.position = 2;
	token2.next = &token3;

	token3.content = "-e";
	token3.type = argument;
	token3.own_command = false;
	token3.expansion = false;
	token3.position = 3;
	token3.next = &token4;

	token4.content = "|";
	token4.type = pipe_type;
	token4.own_command = false;
	token4.expansion = false;
	token4.position = 4;
	token4.next = &token5;

	token5.content = "head";
	token5.type = command;
	token5.own_command = false;
	token5.expansion = false;
	token5.position = 5;
	token5.next = &token6;

	token6.content = "-2";
	token6.type = argument;
	token6.own_command = false;
	token6.expansion = false;
	token6.position = 6;
	token6.next = &token7;

	token7.content = ">>";
	token7.type = redir_r_d;
	token7.own_command = false;
	token7.expansion = false;
	token7.position = 6;
	token7.next = &token8;

	token8.content = "outfile.txt";
	token8.type = path_name;
	token8.own_command = false;
	token8.expansion = false;
	token8.position = 8;
	token8.next = NULL;

	start = &token0;
	
	tokens_to_cmds(start, env);
	wait(NULL);
	wait(NULL);
	return (0);
}*/
