/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:52:15 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 16:30:38 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstsize - Counts the number of nodes in a list.
 * 		Traverses the list and returns the number of nodes.
 * 
 * @lst: A pointer to the first node of the list.
 * 
 * Return: The number of nodes in the list.
 * 
 * Description:
 * This function iterates through the list starting from the node 
 * pointed to by 'lst' and counts the total number of nodes in the 
 * list, returning the count as an integer.
 * 
 * Edge cases checked:
 * - Handles an empty list (returns 0 when 'lst' is NULL).
 * 
 * Edge cases not checked:
 * - Assumes 'lst' is a valid pointer; does not check for corrupted lists.
 */
int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*current;

	counter = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}
