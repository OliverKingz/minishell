/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:47:17 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 20:54:08 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if the given character is an uppercase letter.
 * @param c The character to check.
 * @return 
 * - 1 if the character is an uppercase letter (A-Z).
 * 
 * - 0 if the character is not an uppercase letter.
 * @note 
 * - This function checks whether the character falls within
 *  the range of 'A' to 'Z'.
 */
int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
