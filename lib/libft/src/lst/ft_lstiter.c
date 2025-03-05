/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:51:48 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 16:29:49 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstiter - Iterates through a list and applies a function.
 * 		Applies the function 'f' to each node's content.
 * 
 * @lst: A pointer to the first node of the list.
 * @f: A function pointer to apply to each node's content.
 * 
 * Return: None.
 * 
 * Description:
 * This function iterates through the list starting from 'lst', 
 * applying the function 'f' to the content of each node.
 * 
 * Edge cases checked:
 * - Handles NULL 'lst' (does nothing if 'lst' is NULL).
 * - Handles NULL 'f' (does nothing if 'f' is NULL).
 * 
 * Edge cases not checked:
 * - Does not validate the integrity of the list structure.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (lst == NULL || f == NULL)
		return ;
	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}
