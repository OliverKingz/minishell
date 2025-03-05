/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:50:45 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 16:28:54 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstadd_back - Adds a node to the end of a list.
 *      Appends the node 'new' to the end of the list 'lst'.
 * 
 * @lst: A double pointer to the first node of the list.
 * @new: A pointer to the node to be added to the list.
 * 
 * Return: None. This function does not return a value.
 * 
 * Description:
 * This function appends the 'new' node to the end of the list 'lst'. 
 * If '*lst' is NULL (indicating the list is empty), 'new' becomes the 
 * first node.
 * 
 * Edge cases checked:
 * - Handles an empty list (if '*lst' is NULL, 'new' becomes the first node).
 * - Checks if 'lst' or 'new' is NULL to prevent undefined behavior.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
