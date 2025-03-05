/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokeniser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:17:12 by mzolotar          #+#    #+#             */
/*   Updated: 2025/03/03 08:51:36 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
* @brief 
*
* @param 
* @return 
*/

char **ft_tokeniser(const char *line)
{
	char **token=NULL;
	
	if (line == NULL)
	{
		printf("\033[1;31m🛑 ERROR: en ft_tokeniser: (line == NULL)\n\033[0m"); //testeo
		return (NULL);
	}
	
	
	token = ft_split(line, ' ');
	if (!token)
	{
		printf("Error: ft_split failed.\n");  //testeo
		return NULL;
	}

	//V3:
	//🔸  ✒ no hay comillas en absoluto
		//ft_split
	//🔸  ✒ hay comillas cerradas ' o ", o las dos
		// ✒ comillas cerradas 
			// ✒ split modificado -> ft_split_with_quotes() solo se quita la comilla experior o comillas, por ejemplo: echo "'hola'", ech'o', "ls""-l", etc.
			//ojo con este caso: echo "   hola(o no) "
			//ver todos los casos a testear con comillas y espacios,  a veces pilla comillas abiertas y a veces no 
				//❌ SINTAX_ERROR-> 
				//-> ft_split_with_quotes()
				//🔸  ✒ revisar y/o quitar tokenize_with_quotes.c
		
	return (token);
}


/**
* @brief 
*
* @param 
* @return 
*/

void minishell_loop(char **envp)
{
	(void)envp;
	char **token;
	t_tokens *tokens;
	t_metachars *meta;
	char *line;
	
	tokens = NULL;
	//line = readline("Minishell> ");
	line = get_line();
	while (line) 
	{
		
		//line = readline("Minishell> ");
			//🔹 ✒ meter datos correctos en  ✒ readline ("user@hostname:~/42_School_temp_rep/minishell_borrador")
				//user: whoami o echo $USER
				//hostname: hostname o echo $HOSTNAME
				//path: pwd
					//  ~/ ==  /home/user
					
		meta = init_meta_struct(); // Inicializa la estructura t_metachars
		if (!meta)
		{
			free (line);
			printf("\033[0;34m ⚠️Error: No se pudo inicializar la estructura\033[0m\n");  //quitar esta linea
			break;
		}
		

//FASE 1_TOKENIZACION: -----------------------------------------------------------------------------------------------------

// 🔹 SYNTAX_ERROR_FASE_1: V2:
	// ⚠️ metachars no permitidos: \n ; \t & ) ( # !  				
	// ⚠️ oper no permitido: || ;; >| $|						  	
	// ⚠️ ✒ redirs no permitidos: diferentes de 0, 1 y 2  			
		// ⚠️ con &: ...												
		// ⚠️ not_allow_other_redir:" <<-,<<-, 2>, 2>>"  				
		// ⚠️ con '<space>n<redir>' 									
	// ⚠️ comentarios: # sin comillas  									

	// ✅ corregir bug asignacion type en redir en parseo
		// 🔹 ✒ ver casos
			// 🔹 ✒ hay path_name -> ✅_ejecuta
			// 🔹 ✒ hay path_name, pero es incorrecto
			// 🔹 ✒ hay path_name pero no en su sitio:
			// 🔹 ✒ no hay path_name: 
		// 🔹 ✒ BASH_ERROR: bash: syntax error near unexpected token
	// 🔹 ✒ corregir bug asignacion type en pipe 
		// 🔹 ✒ ver casos
			// 🔹 ✒ hay comando -> ✅_ejecuta
			// 🔹 ✒ hay comando, pero es incorrecto: ls "|" wc -ls -
			// 🔹 ✒ hay comando pero no en su sitio: ls | | -l
			// 🔹 ✒ no hay comando: ls | |
		// 🔹 ✒ BASH_ERROR: bash: syntax error near unexpected token
		
	// 🔹 ✒ comillas abiertas -> ❌ SYNTAX ERROR
		// 🔹 ✒ casos especiales -> ver casos linea 134 pasos_tokenizacion.txt
		// 🔹 ✒ comillas abiertas 
			// 🔹 ✒ comillas abiertas en general.
			// 🔹 ✒ pipe "abierto": echo hola | y '| y echo hola | | y echo hola | | |
			// 🔹 ✒ comillas con pipe abierto
			// 🔹 ✒ comillas abiertas al antes de | < << > >> -> ❌ SYNTAX ERROR ??
			// 🔹 ✒  revisar casos |||||| y | | | |
			
			
	// 🔹 ✒ '/' + '\t' + '\n'
	// 🔹 ✒ '/' anula caracteres -> ver subject
	// 🔹 ✒ meter codigo de SYNTAX_ERROR en $? -> ver pasos_tokenizacion.txt
	
	//🔹 ✒ REVISAR con SEÑALES y HISTORIAL:
		// 🔹  ✒ check_empty_line ->  <espacio><espacio><ENTER> → si linea esta vacia o solo espacio o solo enter -> espera comando nuevo y no ejecuta nada
		// 🔹  ✒ <ENTER> → No hay tokens, así que no hay comando. Bash simplemente muestra un nuevo prompt sin ejecutar nada.
	// 🔹  ✒ Eliminación de espacios en blanco iniciales y finales. Preparamos 'line' para seguir. El shell ignora espacios, tabs y nuevas líneas al principio y al final del comando. Esto no afecta a la tokenización directamente, pero sí prepara el comando para que sea procesado correctamente. -> revisar f ()-> char *get_line(void);
	// 🔹 meter SYNTAX_ERROR en $?
	
	//→ << DELIMITER 	→ 🔹 ✒ gestionar minishell
	//→ << .. y << . y 	→ 🔹 ✒ ❌ SINTAX_ERROR (como comillas abiertas)
	//→ <<.. y <<. 	 	→ 🔹 ✒ ❌ BASH_ERROR: bash: ..: Is a directory (. y .. se tokeniza como path_name)
	
	// ⚠️ PTE_TESTEO_SYNTAX_ERROR_Y_EJECUCION_TODA_FASE1
	
//FASE 1_TOKENIZACION_END: -----------------------------------------------------------------------------------------------------

		if (check_syntax_error_line(line, meta) == true)
		{
			printf (SYNTAX_ERR);
			free(line);
			free_meta_struct(meta);
			break;					//❌❌❌ REAJUSTAR ESTO, QUIERO QUE VUELVA A GENERAR OTRA LINEA DESPUES DE IMPRIMIR EL ERROR NO ROMPA EL BUCLE
		}
		
	 	check_spaces_line (&line, meta);

		// 🔸  ✒ aqui va la funcion: ft_tokeniser()-------------------------------------------------------------------
		token = ft_tokeniser(line);
		if (!token)
		{
			free (line);
			free_meta_struct(meta);
			printf ("(!token) en test_ft_tokeniser(line)"); // revisar y borrar printf
			break;
		}
		//fin de la funcion: ft_tokeniser()-------------------------------------------------------------------

		// 🔹 init list y check type: v2 rula, pero revisar
		init_list (&tokens, token);  
		check_type_tokens(tokens);
		
		if (check_bash_error_token(tokens)== true)
		{
			free (line);								//LINE
			free_split_strs(token);						//SPLIT
			free_tokens_list(&tokens);					//LISTA ENLAZADA== TOKENS
			free_meta_struct(meta);						//META
			break;										//❌❌❌ REAJUSTAR ESTO, QUIERO QUE VUELVA A GENERAR OTRA LINEA DESPUES DE IMPRIMIR EL ERROR NO ROMPA EL BUCLE
		}
		
		if (check_syntax_error_token(tokens)== true)
		{
			printf (SYNTAX_ERR);
			free (line);								//LINE
			free_split_strs(token);						//SPLIT
			free_tokens_list(&tokens);					//LISTA ENLAZADA== TOKENS
			free_meta_struct(meta);						//META
			break;										//❌❌❌ REAJUSTAR ESTO, QUIERO QUE VUELVA A GENERAR OTRA LINEA DESPUES DE IMPRIMIR EL ERROR NO ROMPA EL BUCLE
		}
		
		//check_reserved_words_token
		//check_and_expand_var_token
		//quitar_comillas_token
		
		
//check_sintax_error_2-------------------------------------------------------
		//FASE2_V2:
		// 🔸 ✒ meter SYNTAX_ERROR en $?
		// 🔸 ✒ revisar asignacion de tipo para path_name: falla este comando-> echo "append this">>>logfile.log  -> asigna como path_name >
		// 🔸 ✒ chaekeo bash error en casos: -bash: syntax error near unexpected token 
			// 🔸 ✒ <<<<<, >>>>>, <, >>, >, |
			// 🔸 ✒ >|, |<, etc
			// 🔸 ✒ ver casos
			// 🔸 ✒ testeo redirecciones no validas: >>>>>>, <<<<<<, etc
		// 🔸 ✒  SYNTAX_ERROR_FASE_2:
			// 🔸 ✒ alias + palabras del sistema no permitidos: alias for, etc ->  🔹 ✒ REVISAR casos tipo 'echo for', echo alias ll='ls -la', echo if [ "$x" -eq 5 ]; then echo "x es 5";,  fi etc, 		🚩_PTE_TESTEO + ⚠️_PTE_REVISAR_NORMA 
				//(check_reserved_words(str, meta) -> revisar estas fucniones y ver como gestiono palabras reservadas como SYNTAX_ERROR
					// echo alias ll='ls -la'
					// alias ll='ls -la'
				//  🔸 ✒ funciones propias: my_function ...
			// 🔸 ✒ metachar no permitido: <<<  -> (❌ SINTAX_ERROR) despues de separarlo en casos como <<<<<<<<<<<<
		// 🔸 ✒ revisar variables con colillas y sin comillas y ' + " -> "'hola" , etc. 
		// 🔸  ✒ "" y '' → se tokeniza y da ❌ BASH_ERROR: Command '' not found. 
			// ✒ SYNTAX_ERROR varible con caraacteres no permitidos:
				// 🔸 ✒ hacer idendificador de variables aqui: check_dolar_char -> check_is_valid_var->extract_var/expancion_var cuidado con $|(not_alow_oper)
				// 🔸 ✒ Expansión de la variable con el prefijo ${}: echo "Hola ${nombre}"
				// 🔸 ✒ Expansión de comandos con (): $(date)
				// 🔸 ✒ Expansión aritmética: echo $((5 + 3))
				// 🔸 ✒ Expansión de arreglos: array=("uno" "dos" "tres") -> echo ${array[1]}
				// 🔸 ✒ Expansión de comodines (Globbing: * → (*.txt), ? → (file?.txt), [] → (file[123].txt), {} → (file{1,2,3}.txt)) == wildcards)
				// 🔸 ✒ Funciones de shell: mi_funcion() { echo "¡Hola, mundo!"; }
			// 🔸 ✒ expancion de variables sin comillas y con ""
				// 🔸 ✒ fucnion para identificar y extraes variable
				// 🔸 ✒ expancion de varieable
					//revisar si token tiene o no tiene espacios para retoknizar
						//revisar cuando se quitan las comillas
						//con espacios - 
						//sin espacios - 
					// 🔸 ✒ Expansión de variables (Variable Expansion)
					// 🔸 ✒ Expansión de parámetros (Parameter Expansion)
					// 🔸 ✒ Expansión de comandos:
						// 🔸 ✒ Expansión de comandos:
						// 🔸 ✒ Expansión de comandos con redirecciones
							// 🔸 ✒ Expansión de comandos con redirecciones permitidas
							// 🔸 ✒ Expansión de comandos con redirecciones no permitidas:ver casos-> (❌ SINTAX_ERROR)
					// 🔸 ✒ Expansión de la tilde (~)
					// 🔸 ✒ (❌ SINTAX_ERROR) ver arriba
				// 🔸 ✒ expancion de variable en HEREDOC:
					// ver normas de expancion dentor de HEREDOC
						//LIMITER entre comillas ' y " las variebles no se expanden
						//LIMITER sin comillas las variebles se expandiran

//fin check_sintax_error_2--------------------------------------------------------------

		//FASE3_V2:
		// 🔸 ✒ quitar comillas a tokens: solo se quita comillas exteriores -> "'hola mundo'" -> 'hola mundo', etc. 
		// 🔸 ✒  "" y '' → se tokeniza y da ❌ BASH_ERROR: Command '' not found.
		// 🔸 ✒ testeo de comandos de tokens limpios
		
			// 🚩_TESTEO_SYNTAX_ERROR
			// 🚩_TESTEO_EJECUCION


		//print_all_test();-------------------------------------------------------------------------------
		int fd_test;
		fd_test = open_fd("test/test_output/test_outputs.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
		print_all_test(line, token, tokens, fd_test);
		close(fd_test);		
		//fin test----------------------------------------------------------------------------------------



		if (ft_strncmp(line, "exit", -1) == 0) // ojo aqui exit es un token no un *str, los espacios en shell se quitan (ft_split)
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
		line = get_line();
		//line = readline("Minishell> ");
		
	}
}

