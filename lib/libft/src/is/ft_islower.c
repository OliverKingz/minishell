/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:47:29 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 20:54:15 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the given character is a lowercase letter.
 * @param c The character to check.
 * @return 
 * - 1 if the character is a lowercase letter (a-z).
 * 
 * - 0 if the character is not a lowercase letter.
 * @note 
 * - This function checks whether the character falls within
 *  the range of 'a' to 'z'.
 */
int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
