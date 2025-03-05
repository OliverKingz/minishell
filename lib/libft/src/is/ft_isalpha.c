/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:30:44 by ozamora-          #+#    #+#             */
/*   Updated: 2024/11/24 20:25:12 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is alphabetic.
 * @c: The character to check.
 * @return 1 if 'c' is a letter, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}

/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char test_chars[] = {'A', 'z', '1', 'b', '@', 0, 127, 128};
    int i;

    printf("Testing ft_isalpha vs isalpha:\n");
    for (i = 0; i < (int)sizeof(test_chars); i++)
    {
        int my_result = ft_isalpha(test_chars[i]);
        int std_result = isalpha(test_chars[i]);

        if (my_result == std_result)
            printf("ft_isalpha(%c) = %d; isalpha(%c) = %d [Match]\n",
			test_chars[i], my_result, test_chars[i], std_result);
        else
            printf("ft_isalpha(%c) = %d; isalpha(%c) = %d [Mismatch]\n",
			test_chars[i], my_result, test_chars[i], std_result);
    }
    return 0;
}*/