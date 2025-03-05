/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:00:15 by mzolotar          #+#    #+#             */
/*   Updated: 2025/02/25 11:32:44 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/

int	open_fd(char *pathern, int flags, mode_t mode)
{
	int	fd;

	fd = open(pathern, flags, mode);
	if (fd == -1)
	{
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
	return (fd);
}


/**
* @brief 
*
* @param 
* @return 
*/

char *get_line(void)
{
	size_t len;
	char *line;
	char *temp_line;
	
	temp_line = get_next_line(0);
	//temp_line = readline("minishell_msg: ");
	if (!temp_line) 
	{
		printf("Error: get_line returned NULL\n");  //quitar comment
		return (NULL);
	}
	len = ft_strlen(temp_line);
	if (len > 0 && temp_line[len - 1] == '\n') 
	{
		len--;  // Ignorar el salto de línea
	}
	line = (char *)malloc(len + 1);
	if (!line) 
	{
		free(temp_line);
		printf("Error: Memory allocation failed\n");  //quitar comment
		return (NULL);
	}
	ft_strlcpy(line, temp_line, len + 1); 
	free (temp_line);
	return (line);
}

/**
* @brief 
*
* @param 
* @return 
*/

t_tokens	*ft_find_node_n_position(t_tokens *head, int position)
{
	while (head != NULL)
	{
		if (head->position == position)
			return (head);
		head = head->next;
	}
	return (NULL);
}








 




 
