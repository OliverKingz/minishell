/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:52:09 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 16:30:25 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstnew - Creates a new list node.
 * 		Initializes the node with the content passed as argument.
 * 
 * @content: The content to set in the node's content field.
 * 
 * Return: A pointer to the newly created node. NULL if memory 
 *         allocation fails.
 * 
 * Description:
 * This function creates a new node using malloc and initializes its 
 * 'content' member with the value passed in the 'content' argument. 
 * The 'next' pointer is initialized to NULL.
 * 
 * Edge cases checked:
 * - Handles NULL content.
 * 
 * Edge cases not checked:
 * - Does not check if 'content' is valid (just assigns the value).
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
