/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcionts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:27:02 by mzolotar          #+#    #+#             */
/*   Updated: 2025/03/03 09:06:22 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **test_ft_tokeniser(const char *line)
{
	char **token;

	if (line == NULL)
	{
		printf("\033[1;31m🛑 ERROR: en test_ft_tokeniser: (line == NULL)\n\033[0m"); //quitar comentario
        return (NULL);
	}
	token = ft_split(line, ' ');
	if (!token)
	{
		printf("Error: ft_split failed.\n");  //testeo
		return NULL;
	}
	return (token);
}

void test_minishell_loop(char **envp)
{
	(void)envp;
	char		**token;
	t_tokens	*tokens;
	t_metachars *meta;
	t_program	program;
	char		*line;
	
	tokens = NULL;

	line = readline("Minishell> ");	
	//line = get_line();
	while (line) 
	{
		//Guardar en el historial
		//if (ft_strncmp("", line, -1) != 0)
		//	add_history(line);
		
		meta = init_meta_struct(); // Inicializa la estructura t_metachars
		if (!meta)
		{
			free (line);
			printf("\033[0;34m ⚠️Error: No se pudo inicializar la estructura\033[0m\n");  //quitar esta linea
			break;
		}

		if (check_syntax_error_line(line, meta) == true)
		{
			printf (SYNTAX_ERR);
			free(line);
			free_meta_struct(meta);
			break;					//❌❌❌ REAJUSTAR ESTO, QUIERO QUE VUELVA A GENERAR OTRA LINEA DESPUES DE IMPRIMIR EL ERROR NO ROMPA EL BUCLE
		}

		check_spaces_line (&line, meta);

		// funcion: test_ft_tokeniser()-------------------------------------------------------------------
		token = test_ft_tokeniser(line);
		if (!token)
		{
			free (line);
			free_meta_struct(meta);
			printf ("(!token) en test_ft_tokeniser(line)"); // revisar y borrar printf
			break;
		}
		//fin de la funcion: test_ft_tokenizer()-------------------------------------------------------------------

		init_list (&tokens, token);
		check_type_tokens(tokens);
		
		//print_all_test();-------------------------------------------------------------------------------
		//ver output en: test/test_output/test_outputs.txt
		int fd_test;
		fd_test = open_fd("test/test_output/test_outputs.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
		print_all_test(line, token, tokens, fd_test);
		close(fd_test);
		//fin test----------------------------------------------------------------------------------------

		
		program.cmd_cont = count_node_type(tokens, command);
		program.hdoc_cont = count_node_type(tokens, redir_l_d);
		//program.pid = (pid_t *) malloc(sizeof(pid_t) * program.cmd_cont);
		program.pid = (pid_t *) ft_calloc(program.cmd_cont + 2, sizeof(pid_t));
		program.start_token = tokens;
		g_sign = 0; //Reseteo la variable que guarda las señales
		//Heredoc
		create_hdoc(&program);
		tokens_to_cmds(&program, envp);
		ft_wait_children(&program); //Función para esperar a los hijos
		if (ft_strncmp(line, "exit", -1) == 0) 
		{
			free (line);								//LINE
			free_split_strs(token);						//SPLIT
			free_tokens_list(&tokens);					//LISTA ENLAZADA== TOKENS
			free_meta_struct(meta);						//META
			break;
		}
		//FREE ALL:------------------------------------------------------------------------
		free (line);								//LINE
		free_split_strs(token);						//SPLIT
		free_tokens_list(&tokens);					//LISTA ENLAZADA== TOKENS
		free_meta_struct(meta);						//META
		line = readline("Minishell> ");
		//line = get_line();
	}
}
