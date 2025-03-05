/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:25:26 by raperez-          #+#    #+#             */
/*   Updated: 2025/02/25 10:45:38 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main(void)
{
    char    *s;

    s = readline("Minishell> ");
    while (s)
    {
        add_history(s);
        free(s);
        s = readline("Minishell> ");
    }
    return (0);
}