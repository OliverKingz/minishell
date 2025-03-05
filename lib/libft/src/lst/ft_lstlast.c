/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:52:00 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 16:29:59 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstlast - Returns the last node of a list.
 * 		Finds the last node of the list.
 * 
 * @lst: A pointer to the first node of the list.
 * 
 * Return: A pointer to the last node of the list.
 * 
 * Description:
 * This function traverses the list and returns a pointer to the last 
 * node. If the list is empty (NULL), it returns NULL.
 * 
 * Edge cases checked:
 * - Handles an empty list (returns NULL if 'lst' is NULL).
 * 
 * Edge cases not checked:
 * - Assumes all nodes in the list are valid.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (lst == NULL)
	{
		return (NULL);
	}
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}
