/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:09:25 by mzolotar          #+#    #+#             */
/*   Updated: 2025/03/01 09:20:27 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_metachars(const t_metachars *meta)
{
    if (meta == NULL)
    {
        printf("Estructura t_metachars es NULL\n");
        return;
    }

    print_string_array("Allow Operators", meta->allow_oper);
    print_string_array("Allow Metacharacters", meta->allow_metachar);
    print_string_array("Allow Op", meta->allow_op);
    
    print_string_array("Not Allowed Metacharacters", meta->not_allow_metachar);
    print_string_array("Not Allowed Brackets", meta->not_allow_bracket);
    print_string_array("Is Metacharacter", meta->is_metacharacter);
    

    print_string_array("not_allow_num_redir", meta->not_allow_num_redir);
    print_string_array("not_allow_other_redir", meta->not_allow_other_redir);
    print_string_array("Not Allowed Operators", meta->not_allow_oper);
    print_string_array("Is unexpected_token", meta->unexpected_token);
    
    //print_string_array("Is not_allow_word", meta->not_allow_word);
}

void print_string_array(const char *label, char **array)
{
    printf("%s: ", label);
    if (array == NULL)
    {
        printf("(NULL)\n");
        return;
    }

    while (*array)
    {
        printf("[%s]", *array);
        array++;
    }
    printf("\n");
}


void	print_linked_list(t_tokens *head, int fd)
{
	t_tokens *current = head;

    ft_putstr_fd("\n🔶---------------list_all_content:----------\n", fd);
    int i = 0;
	while (current)
	{
		ft_putstr_fd("Token: ", fd);
        ft_putnbr_fd(i, fd);
        ft_putstr_fd("\n", fd);
		ft_putstr_fd("   Content: ", fd);
		ft_putstr_fd(current->content, fd);
		ft_putstr_fd("\n", fd);

		ft_putstr_fd("   Type: ", fd);
		if (current->type == command)
			ft_putstr_fd("command\n", fd);
		else if (current->type == argument)
			ft_putstr_fd("argument\n", fd);
		else if (current->type == redir_l_u)
			ft_putstr_fd("redir_l_u (<)\n", fd);
		else if (current->type == redir_l_d)
			ft_putstr_fd("redir_l_d (<<)\n", fd);
		else if (current->type == redir_r_u)
			ft_putstr_fd("redir_r_u (>)\n", fd);
		else if (current->type == redir_r_d)
			ft_putstr_fd("redir_r_d (>>)\n", fd);
		else if (current->type == pipe_type)
			ft_putstr_fd("pipe_type\n", fd);
		else if (current->type == path_name)
			ft_putstr_fd("path_name\n", fd);
		else if (current->type == heredoc_delimiter)
			ft_putstr_fd("heredoc_delimiter (<< LIMIT)\n", fd);
        else if (current->type == temp)
			ft_putstr_fd("temp\n", fd);
		else
			ft_putstr_fd("error\n", fd);

		ft_putstr_fd("   Own_Command: ", fd);
		ft_putstr_fd(current->own_command ? "true\n" : "false\n", fd);

		ft_putstr_fd("   Expansion: ", fd);
		ft_putstr_fd(current->expansion ? "true\n" : "false\n", fd);

		ft_putstr_fd("   Position: ", fd);
		ft_putnbr_fd(current->position, fd);
		ft_putstr_fd("\n\n", fd);

		current = current->next;
        i++;
	}
    ft_putstr_fd("--------------------------------------------\n\n", fd);
}


void print_type_list(t_tokens *tokens, int fd)
{
    t_tokens *current = tokens;
    while (current != NULL)
    {
        ft_putstr_fd("[", fd);

        if (current->type == command)
            ft_putstr_fd("command", fd);
        else if (current->type == argument)
            ft_putstr_fd("argument", fd);
        else if (current->type == redir_l_u)
            ft_putstr_fd("redir_l_u (<)", fd);
        else if (current->type == redir_l_d)
            ft_putstr_fd("redir_l_d (<<)", fd);
        else if (current->type == redir_r_u)
            ft_putstr_fd("redir_r_u (>)", fd);
        else if (current->type == redir_r_d)
            ft_putstr_fd("redir_r_d (>>)", fd);
        else if (current->type == pipe_type)
            ft_putstr_fd("pipe_type", fd);
        else if (current->type == path_name)
            ft_putstr_fd("path_name", fd);
        else if (current->type == heredoc_delimiter)
            ft_putstr_fd("heredoc_delimiter", fd);
        else if (current->type == temp)
            ft_putstr_fd("temp", fd);
        else
            ft_putstr_fd("error", fd);
        
        ft_putstr_fd("]", fd);

        if (current->next != NULL)
            ft_putstr_fd(" ➜ ", fd);

        current = current->next;
    }
    ft_putstr_fd(" ➜ NULL\n", fd);
    
}

void print_content_list(t_tokens *tokens, int fd)
{
    t_tokens *place = tokens;
    while (place != NULL)
    {
        ft_putstr_fd("[", fd);
        ft_putstr_fd(place->content, fd);
        ft_putstr_fd("]", fd);

        if (place->next != NULL)
            ft_putstr_fd(" ➜ ", fd);

        place = place->next;
    }
    ft_putstr_fd(" ➜ NULL\n", fd);
    
}

void print_list(t_tokens *tokens, int fd)
{
    ft_putstr_fd("\n🔶---------------list_content+type:--------\n", fd);
    print_content_list(tokens, fd);
    print_type_list(tokens, fd);
    ft_putstr_fd("--------------------------------------------\n\n", fd);
}
void	print_split_before_list(char **token, int fd)
{
	int	i;

	ft_putstr_fd("\n🔶---------------split_before_list:--------\n", fd);
	i = 0;
	while (token[i] != NULL)
	{
		ft_putstr_fd("token[", fd);
		ft_putnbr_fd(i, fd);
		ft_putstr_fd("]:", fd); 
		ft_putstr_fd(token[i], fd); 
		ft_putstr_fd("\n", fd); 
		i++;
	}
	ft_putstr_fd("--------------------------------------------\n\n", fd);
}

void print_command_line(char *line, int fd)
{
    ft_putstr_fd("\n🔶--------------command_line:--------------\n", fd);
    ft_putstr_fd(line, fd);
    ft_putstr_fd("\n--------------------------------------------\n\n", fd);
}

void print_all_test(char *line, char **token, t_tokens *tokens, int fd)
{
	ft_putstr_fd("◉====▣===▢◇▢===▣====◉•◉===▣===▢   ALL DATA:  ▢===▣===◉•◉===▣====▢◇▢===▣===◉\n", fd);
    print_command_line(line, fd);               //linea de comando 
	print_split_before_list(token, fd);         //split
    print_list(tokens, fd);                     // content y type de list
	print_linked_list (tokens, fd);             //  todo el contenido de cada nodo de list	
    ft_putstr_fd("◉====▣===▢◇▢===▣====◉•◉===▣===▢ ====◉•◉=== ▢===▣===◉•◉===▣====▢◇▢===▣===◉\n\n", fd);
}