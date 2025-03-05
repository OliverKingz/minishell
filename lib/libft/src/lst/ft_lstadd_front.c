/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:51:15 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/22 16:29:08 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstadd_front - Adds a node to the front of a list.
 * 		Inserts the new node at the beginning of the list.
 * 
 * @lst: A double pointer to the first node of the list.
 * @new: A pointer to the node to be added to the list.
 * 
 * Return: None. This function does not return a value.
 * 
 * Description:
 * This function takes the new node 'new' and adds it to the beginning 
 * of the list 'lst'. The 'new' node becomes the new first node in the 
 * list, with its 'next' pointer set to the old first node.
 * 
 * Edge cases checked:
 * - Handles when 'lst' is NULL (creates the first node in the list).
 * 
 * Edge cases not checked:
 * - The comment is incorrect. Replace with: "Does not handle when 'lst'
 * is NULL as it assumes 'lst' is a valid double pointer to a list."
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
