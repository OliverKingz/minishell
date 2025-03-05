/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:27:54 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/27 18:38:18 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a character to uppercase.
 * @param c The character to convert.
 * @return The uppercase equivalent of 'c' if it is a lowercase letter; 
 *         otherwise, returns 'c'.
 */
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - ' ');
	else
		return (c);
}
