/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck_quote_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:37:18 by mzolotar          #+#    #+#             */
/*   Updated: 2025/02/28 09:46:23 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/
//true - hay commillas
//false - no hay comillas

bool is_quotes_present (const char *str)
{
	if (!str) // Evitar acceso a puntero nulo
        return (false);
	if (ft_strchr(str, '"') || ft_strchr(str, '\'')) 
		return (true);
	return (false);
}

/**
* @brief 
*
* @param 
* @return 
*/
//true - tiene comillas abiertas
//false - no tiene comillas abiertas

bool quotes_is_open(const char *str) 
{
    bool single_quote;
    bool double_quote;

	single_quote = false;
	double_quote = false;
    while (*str) 
	{
        if (*str == '"' && !single_quote) 
        {
            double_quote = !double_quote;
        } 
        else if (*str == '\'' && !double_quote) 
        {
            single_quote = !single_quote;
        }
        str++;
    } 
    return (single_quote || double_quote);
}

/**
* @brief 
*
* @param 
* @return 
*/
//true - par
//false -impar

bool is_even_quotes(const char *str)
{
    size_t single_quotes;
    size_t double_quotes;

	single_quotes = ft_strchar_count(str, '\'');
	double_quotes = ft_strchar_count(str, '"');

    return (single_quotes % 2 == 0) && (double_quotes % 2 == 0);
}

/**
* @brief 
*
* @param 
* @return 
*/
//true - metachar encomillado
//false - metachar no encomillado

bool char_is_quoted(const char *str, char character, const char *position) 
{
    bool in_single_quote;
    bool in_double_quote;
    const char *ptr;

    in_single_quote = false;
    in_double_quote = false;
    if (!str || !position)
        return (false);
    ptr = str;
    while (*ptr)
    {
        toggle_quotes(*ptr, &in_single_quote, &in_double_quote);

        // Solo verificamos si *pos está dentro de comillas
        if (ptr == position && *ptr == character)
        {
            //printf("\033[0;34m ⚠️ INFO: metachar en posición: %ld, Estado de comillas: %d (dobles) o %d (simples) \033[0m\n",
            //    position - str, in_double_quote, in_single_quote);
            return (in_single_quote || in_double_quote);
        }
        ptr++; // Avanzar en la línea
    }
    return (false);
}

/**
* @brief 
*
* @param 
* @return 
*/

// Esta función revisa si el operador específico está entre comillas
//true - con comillas
//false - sin comillas

bool oper_is_quoted(const char *str, const char *operator_str, const char *position) 
{
    bool in_single_quote;
    bool in_double_quote;
    const char *ptr;

    in_single_quote = false;
    in_double_quote = false;
    if (!str || !operator_str || !position)
    {
        printf("salta error en oper_is_quoted: if (!str || !operator_str || !position) "); //quitar esta linea
        return (false);
    }
    ptr = str;
    while (*ptr) 
    {
        toggle_quotes(*ptr, &in_single_quote, &in_double_quote);
        if (ptr == position && ft_strncmp(ptr, operator_str, ft_strlen(operator_str)) == 0)
        {
            //printf("\033[0;34m ⚠️ INFO: Operador en posición: %ld, Estado de comillas: %d (dobles) o %d (simples) \033[0m\n",
            //    position - str, in_double_quote, in_single_quote);            
            return (in_single_quote || in_double_quote);  
        }
        ptr++;
    }
    return (false); 
}
    
    