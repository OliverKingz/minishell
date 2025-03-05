/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:51:38 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 16:29:36 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstdelone - Deletes a node, freeing its memory.
 * 		Frees the memory of the node's content and the node itself.
 * 
 * @lst: A pointer to the node to be deleted.
 * @del: A function pointer to free the content of the node.
 * 
 * Return: None.
 * 
 * Description:
 * This function deletes the given node 'lst' by applying the 'del' 
 * function to its content, then freeing the node itself. The 'next' 
 * pointer of the node is not freed.
 * 
 * Edge cases checked:
 * - Handles NULL 'lst' (does nothing if 'lst' is NULL).
 * - Handles NULL 'del' (does not call 'del' if NULL).
 * 
 * Edge cases not checked:
 * - Does not check if the 'content' has already been freed.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}
