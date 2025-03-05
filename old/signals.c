/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:57:33 by raperez-          #+#    #+#             */
/*   Updated: 2025/02/22 11:48:20 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int main(void)
{
    sigaction();
    while (1) {
        printf("Ejecutando... (presiona Ctrl+C)\n");
        sleep(2);
    }
    return (0);
}
