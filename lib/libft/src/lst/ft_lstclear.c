/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:51:21 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 16:29:26 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstclear - Deletes and frees a list of nodes.
 * 		Deletes and frees all nodes from 'lst', applying 'del' to 
 *      each node's content.
 * 
 * @lst: A double pointer to the first node of the list.
 * @del: A function pointer to free the content of each node.
 * 
 * Return: None.
 * 
 * Description:
 * This function deletes all nodes in the list starting from 'lst', 
 * applying 'del' to the content of each node before freeing it. 
 * Finally, 'lst' is set to NULL.
 * 
 * Edge cases checked:
 * - Handles NULL 'lst' (does nothing if 'lst' is NULL).
 * - Handles NULL 'del' (does nothing if 'del' is NULL).
 * 
 * Edge cases not checked:
 * - Assumes all nodes in the list are valid; does not check for corruption.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*current_next;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		current_next = current->next;
		del(current->content);
		free(current);
		current = current_next;
	}
	*lst = NULL;
}
