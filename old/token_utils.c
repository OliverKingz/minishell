/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:42:35 by mzolotar          #+#    #+#             */
/*   Updated: 2025/03/03 08:59:40 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/

t_metachars *init_meta_struct(void)
{
    t_metachars *meta;

    meta = (t_metachars *)malloc(sizeof(t_metachars));
    if (!meta)
        return (NULL);

    meta->allow_oper = ft_split(" << >> ", ' ');
    meta->allow_metachar = ft_split(" < > | ", ' ');
	meta->allow_op = ft_split(" << | >> < > ", ' ');
    
    meta->not_allow_metachar = ft_split(" \n ; : \t & # ! ) ( ", ' ');
    meta->not_allow_bracket = ft_split(" [ { ] } ", ' ');
    meta->is_metacharacter = ft_split(" \t \n | & ; ( ) < > ", ' ');
    
    
    meta->not_allow_num_redir = ft_split("<<- << <> >> < >", ' ');
	meta->not_allow_other_redir= ft_split(" <<<,<<<,<<-, <>,<>, <<-, 2>, 2>>", ',');
    meta->not_allow_oper = ft_split(" || ;; >| $|", ' ');
    meta->unexpected_token = ft_split(" `newline' `|' `>' `<' `>>' `<<' ", ' ');
    
    //meta->not_allow_word = ft_split(" alias for while if elif do done case then in esac until coproc else select fi ", ' ');
    //meta->word = NULL;
    //meta->varvariable =NULL;

    meta->i_current_index = 0;
    meta->j_new_index = 0;

    meta->in_single_quote = false;
    meta->in_double_quote = false;

    return (meta);
}

















