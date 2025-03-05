/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:45:29 by mzolotar          #+#    #+#             */
/*   Updated: 2025/02/28 12:04:16 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/
//true - tiene redir prohibida
//false - no tiene redir prohibida


bool has_invalid_numeric_redir(const char *str, t_metachars *meta)
{
    const char *ptr;
    //const char *num_start;

    if (!str || !meta || !meta->not_allow_num_redir)
        return (false);
    ptr = str;
    meta->in_single_quote = false;
    meta->in_double_quote = false;
    while (*ptr)
    {
        toggle_quotes(*ptr, &meta->in_single_quote, &meta->in_double_quote);
        if (!meta->in_single_quote && !meta->in_double_quote && *ptr == ' ' &&
            ft_isdigit(*(ptr + 1)))
        {
            //num_start = ++ptr;
            while (ft_isdigit(*ptr))
                ptr++;

			if (check_operator(ptr, meta->not_allow_num_redir))
			{
				//printf("\U0001F6A8 Error: Redirección numérica prohibida detectada: '%.*s%s'\n",
				//		(int)(ptr - num_start), num_start, ptr);
				return (true);
			}
        }
        ptr++;
    }
    return (false);
}






/**
* @brief 
*
* @param 
* @return 
*/

//check_operator(line, meta->allow_oper) == false - hay operadores permitidos sin comillas-> seguimos
//check_operator(line, meta->not_allow_oper) == false - hay operadores no permitidos sin comillas-> sintax_error

bool check_operator (const char *str, char **operators)
{
    int i;
    const char *position;
	const char *ptr;

    if (!str || !operators)
	{
		//printf("entramos como false por check_operator  \n\n");
        return (false);
	}

    ptr = str;
    while (*ptr)
	{
		i = 0;
		while (operators[i])  // Recorre el array hasta encontrar NULL (final de ft_split)
		{
			if (ft_strncmp(ptr, operators[i], ft_strlen(operators[i])) == 0)
			{
				position = ptr;
				if (!oper_is_quoted(str, operators[i], position))
				{
					//printf("\033[0;34m ⚠️ INFO: entramos como true por check_operator, operador: \033[0m %s\n", operators[i]);//quitar linea
					return (true); // Es un operador especial no comillado
				}
			}
			i++;
		}
		ptr++;
	}
    return (false);
}

/**
* @brief 
*
* @param 
* @return 
*/
//true - ok seguimos con programa
//false - fallo sintax error operador/palabra no permitido sin comillas

bool not_allow_spec_operators(const char *str, t_metachars *meta)
{
	if (check_operator(str, meta->not_allow_other_redir) == true)
	{
		//printf("\033[0;34m ⚠️ INFO:salgo con false (check_operator(str, meta->not_allow_other_redir) == true)⚠️\033[0m\n");
		return (false);
	}
	else if (check_operator(str, meta->not_allow_oper) == true)
    {
		//printf("\033[0;34m ⚠️ INFO:salgo con false (check_operator(str, meta->not_allow_oper) == true)⚠️\033[0m\n");
		return (false);
	}
	
	
	return (true);
}


/**
* @brief 
*
* @param 
* @return 
*/

//bool check_metacharacter (const char *str, char **character)
//check_metacharacter (line, meta->allow_metachar) == true  - hay metachar permitidos sin comillas -> segiuimos
//check_metacharacter (line, meta->not_allow_metachar) == true - hay not_allow_metachar sin comillas -> sintax_error
//check_metacharacter (line, meta->not_allow_bracket) == true  - hay not_allow_bracket sin comillas -> sintax_error
//check_metacharacter (line, meta->is_metacharacter) == true 
//false: error o hay caracteres prohibidos o no encuentran caracteres buscados

bool check_metacharacter (const char *str, char **character)
{
	int i;
	const char *ptr;

	if (!str || !character)
	{
		//printf("\033[0;34m ⚠️ INFO: estamos en: if (!str || !character) en bool check_metacharacter.\033[0m\n");//quitar linea
		return (false);
	}

	ptr = str;
	//printf("✅ check_metacharacter\n");
	while (*ptr) 
	{
		i = 0;
		while (character[i]) 
		{
			if (*ptr == character[i][0] && !char_is_quoted(str, *ptr, ptr))
			{
				//printf("✅ check_metacharacter retorna false\n");
				return (false); // Se encontró metacharacter no entrecomillado
			}
			i++;
		}
		ptr++;
	}
	//printf("✅ check_metacharacter retorna true\n");
	return (true);
}


/**
* @brief 
*
* @param 
* @return 
*/

//true -> ❌ SINTAX_ERROR
//false - sigue

bool check_syntax_error_line(const char *str, t_metachars *meta)
{ 
	
	if (not_allow_spec_operators(str, meta) == false)
	{
		//printf("\033[0;34m ⚠️ INFO: estamos en: not_allow_spec_operators(line, meta) == false.⚠️\033[0m\n");
		return (true);
	}
	else if (check_metacharacter (str, meta->not_allow_bracket) == false)
	{
		//printf("\033[0;34m ⚠️ INFO: estamos en: heck_metacharacter (line, meta->not_allow_bracket).\033[0m\n");
		return (true);
	}
	else if (check_metacharacter (str, meta->not_allow_metachar) == false)
	{
		//printf("\033[0;34m ⚠️ INFO: estamos en: check_metacharacter (line, meta->not_allow_metachar).\033[0m\n");
		return (true);
	}
	else if (has_invalid_numeric_redir(str, meta)== true)
	{
		//printf("⚠️ INFO: salgo con false (redirección numérica no permitida) ⚠️\n");
		return (true);
	}
	else if (is_quotes_present(str) && quotes_is_open(str) == true) 
	{
		printf("⚠️ hay comilas y estan abiertas ⚠️\n");
		return (true);
	}
	//comillas abiertas al antes de | < << > >>

	
	return (false);
}



