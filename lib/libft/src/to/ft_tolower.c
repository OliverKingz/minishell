/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:27:50 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/27 18:37:43 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a character to lowercase.
 * @param c The character to convert.
 * @return The lowercase equivalent of 'c' if it is an uppercase letter; 
 *         otherwise, returns 'c'.
 */
int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + ' ');
	else
		return (c);
}
