#include "minishell.h"


// Definiciones de macros y funciones auxiliares (suponemos que ya existen):
// BASH_ERR: mensaje para error tipo "bash: syntax error near unexpected token"
// SYNTAX_ERR: mensaje para error de sintaxis (como comillas abiertas, redirección incompleta, etc.)
// is_redir(token): devuelve true si el token es un operador de redirección (<, >, <<, >>)
// pipe_type: constante que indica que el token es un pipe

bool check_syntax_error_token(t_tokens *tokens)
{
    t_tokens *current = tokens;
    while (current)
    {
        /* 
         * Caso 1: Si el token NO es un operador aislado (ni redirección ni pipe)
         * pero su contenido termina con un caracter de redirección, 
         * consideramos que está “abierto” (como "ls<" o "echo $VAR=|")
         */
        if (current->type != pipe_type && !is_redir(current))
        {
            size_t len = strlen(current->content);
            if (len > 0)
            {
                char last = current->content[len - 1];
                if (last == '<' || last == '>')
                {
                    return (printf("1: %s\n", SYNTAX_ERR), true);
                }
            }
        }
        current = current->next;
    }
    return false;
}

bool check_bash_error_token(t_tokens *tokens)
{
    t_tokens *next_token;
    t_tokens *current = tokens;
    
    // Error: Pipe al inicio (ejemplo: "| ls")
    if (current && current->type == pipe_type)
    {
        return (printf("3: %s: `%s'\n", BASH_ERR, current->content), true);
      
    }
    
    while (current)
    {
        next_token = current->next;
        
        // Error: Redirección sin argumento (ejemplo: ">", "<", ">>", "<<" sin nada después)
        if (is_redir(current) && (!next_token))
        {
            return(printf("4: %s: `newline'\n", BASH_ERR), true);
        }
        
        // Error: Pipe seguido incorrectamente (ejemplo: "| |", "| <", "| >")
        if (current->type == pipe_type && (!next_token || next_token->type == pipe_type || is_redir(next_token)))
        {
            return (printf("5: %s: `%s'\n", BASH_ERR, current->content), true);
             
        }
        
        // Error: Redirecciones encadenadas incorrectamente 
        // (ejemplo: tokens consecutivos de redirección, como "<< <<" o ">> >>" o ">> >")
        if (is_redir(current) && next_token && is_redir(next_token))
        {
            return(printf("6: %s: `%s'\n", BASH_ERR, next_token->content), true);
             
        }
        
        current = next_token;
    }
    return false;
}
