/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reserved_words.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:03:50 by mzolotar          #+#    #+#             */
/*   Updated: 2025/02/22 12:33:53 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/
//true - palabra especial SHELL
// false - no es palabra especial SHELL

bool is_reserved_word(const char *word, t_metachars *meta)
{
    int i;

	i = 0;
    while (meta->not_allow_word[i])
    {
        if (ft_strncmp(word, meta->not_allow_word[i], -1) == 0)
            return (true); 					
        i++;
    }
    return (false); 
}

/**
* @brief 
*
* @param 
* @return 
*/

// Extrae una palabra de la línea y la almacena en meta->word
void extract_word_dynamic(const char *line, int *index, char **dest) 
{
    int start;
    int length;

	start = *index;
	length = 0;

    // Calcular la longitud de la palabra
    while (line[*index] && !ft_strchr(" \t\n|&;(){}", line[*index])) 
    {
        (*index)++;
        length++;
    }

    // Asignar memoria para la palabra
    // Solo liberar si ya hay algo en dest
	if (*dest) 
	{
		free(*dest);
		*dest = NULL;
	}
	 
    *dest = (char *)malloc(length + 1);
	
    if (!(*dest)) 
    {
        perror("malloc failed in extract_word_dynamic");			//quitar printf
        return;
    }

    // Copiar la palabra extraída
    ft_strlcpy(*dest, &line[start], length + 1);
}


/**
* @brief 
*
* @param 
* @return 
*/

//  Verifica si la palabra es reservada y no está entrecomillada
//true - palabra especial SHELL sin comillas
// false - no es palabra especial SHELL

bool is_reserved_and_unquoted(const char *line, const char *word, t_metachars *meta)
{
    const char *position;
    char before;
    char after;

    if (is_reserved_word(word, meta))
    {
        position = ft_strnstr(line, word, ft_strlen(line));
        if (position)
        {
            // Verifica si está rodeada de separadores o es una palabra independiente
            if (position == line)
                before = ' ';
            else
                before = *(position - 1);

            after = *(position + ft_strlen(word));
            if ((ft_strchr(" \t\n|&;(){}", before) || position == line) &&
                (ft_strchr(" \t\n|&;(){}", after) || after == '\0'))
            {
                if (!oper_is_quoted(line, word, position))
                    return (true);
            }
        }
    }
    return (false);
}


/**
* @brief 
*
* @param 
* @return 
*/

//true - hay palabra reservada - SYNTAX_ERROR
//false - no hay palabra reservada, seguimos

// recorre la línea y detecta palabras reservadas reservadas por SHEEL no permitidas en minishell_42

bool check_reserved_words(const char *line, t_metachars *meta) 
{
	int i = 0;
	bool in_single_quote;
	bool in_double_quote;
	
	i = 0;
	in_single_quote = false;
	in_double_quote = false;

	if (!line || !meta || !meta->not_allow_word)
		return false;
		
	if (meta->word)  // Solo liberar si no es NULL
	{
		free(meta->word);
		meta->word = NULL;  // Evitar referencias colgantes
	}

	while (line[i]) 
	{
		toggle_quotes(line[i], &in_single_quote, &in_double_quote);
		if (in_single_quote || in_double_quote) 		 // Ignorar contenido dentro de comillas
		{
			i++;
			continue;
		}

		// Si encontramos un separador, extraemos la palabra anterior
		if (ft_strchr(" \t\n|&;(){}", line[i]) || line[i] == '\0') 
		{
			if (meta->word && is_reserved_and_unquoted(line, meta->word, meta)) 
				return (true);
			// Resetear la palabra para la siguiente
            if (meta->word)
            {
                free(meta->word);
                meta->word = NULL;
            }
			i++;
		}
		else 
		{
			// Extraer palabra y guardarla en meta->word
            extract_word_dynamic(line, &i, &(meta->word));
		}
	}
	
	// Última palabra en la línea (si existe)
	if (meta->word && is_reserved_and_unquoted(line, meta->word, meta)) 
	{
		return (true);
	}
	return (false);
}
