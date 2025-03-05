/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:52:04 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 16:30:08 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstmap - Creates a new list by applying a function to each node.
 * 		Iterates through 'lst' and applies the function 'f' to each 
 *      node, creating a new list with the results.
 * 
 * @lst: A pointer to the first node of the list.
 * @f: A function pointer to apply to each node's content.
 * @del: A function pointer to delete the content of a node if needed.
 * 
 * Return: A new list resulting from the application of 'f'. NULL if 
 *         memory allocation fails.
 * 
 * Description:
 * This function creates a new list by applying the function 'f' to 
 * each node in 'lst'. If memory allocation fails for any node, the 
 * 'del' function is applied to free the content of the failed nodes.
 * 
 * Edge cases checked:
 * - Handles NULL 'lst' (returns NULL if 'lst' is NULL).
 * - Returns NULL if 'f' is NULL
 * 
 * Edge cases not checked:
 * - Assumes memory allocation will succeed unless malloc fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
