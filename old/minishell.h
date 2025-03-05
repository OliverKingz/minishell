

#ifndef MINISHELL_H
# define MINISHELL_H

//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──Includes:──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

# include "libft/libft.h"

# include <stdlib.h>      // malloc, free, getenv
# include <stdio.h>       // printf
# include <unistd.h>      // write, access, read, close, fork, execve, pipe, isatty
# include <sys/wait.h>    // wait, waitpid, wait3, wait4
# include <signal.h>      // signal, sigaction, kill
# include <fcntl.h>       // open
# include <sys/stat.h>    // stat, lstat, fstat
# include <dirent.h>      // opendir, readdir, closedir
# include <string.h>      // strerror
# include <termios.h>     // tcsetattr, tcgetattr
# include <curses.h>      // tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <readline/readline.h> // readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
# include <readline/history.h>
# include <errno.h>       // perror

#include <stdbool.h> 		//bool

//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──Macros  :──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

//Extremos de los pipes
# define READ_END 0
# define WRITE_END 1

//	**ERROR MESSAGES: MINISHELL**
# define SYNTAX_ERR "❌ syntax error\n"

//	**ERROR MESSAGES: SHELL**
//	syntax error near unexpected token	-> bash: syntax error near unexpected token `newline', `|',  `>', etc
# define BASH_ERR "bash: syntax error near unexpected token"

//Comando inexistente	-> command: command not found
# define ERR_COMMAND ": command not found\n"

//Error de sintaxis	-> syntax error near unexpected token 'X'
//add ERR_MSG "bash: syntax error near unexpected token "

//Variable inválida en export	-> export: 'var': not a valid identifier
# define ERR_IDENTIF "not a valid identifier"

//Permiso denegado	-> filename: Permission denied
//add ERR_MSG ": permission denied"

//cd a directorio inexistente	-> cd: folder: No such file or directory
# define ERR_F_OR_D	": no such file or directory"		//cd y cat en archivo inexistente

//cat en archivo inexistente	-> cat: file: No such file or directory
# define ERR_F_OR_D	": no such file or directory"		//cd y cat en archivo inexistente

//Redirección sin archivo	-> bash: syntax error near unexpected token 'newline'
//add ERR_MSG

//Archivo no ejecutable	-> file: Exec format error
//add ERR_MSG


//#➵⤐─╌➣⋆➣╌─⤏➵•➵⤐─╌➣⋆➣╌╌──Global Variables :──╌╌➣⋆➣╌─⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

extern int g_sign;

//#➵⤐──╌╌➣⋆➣╌─⤏➵•➵⤐──╌╌➣⋆➣╌╌──Enums :──╌╌➣⋆➣╌╌⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

typedef enum
{
	temp, command, argument, redir_l_u, redir_l_d, redir_r_u, redir_r_d, pipe_type, path_name, heredoc_delimiter
}	t_type;

typedef int t_pipe[2];

/** 

temp 				->  temporal por defecto
command				->  command
argument 			->  argument 
redir_l_u   		->  redirection_left_unic 		== '<'
redir_l_d   		->  redirection_left_double 	== '<<'
redir_r_u   		->  redirection_right_double 	== '>'
redir_r_d   		->  redirection_right_double 	== '>>' 
pipe_type 			->  pipe
path_name			->  patern_name (echo hello > echo.out 		!=		 echo some more data > ../../over.here)
heredoc_delimiter 	->  (<< LIMIT)

*/

//#➵⤐──╌╌➣⋆➣╌─⤏➵•➵⤐──╌╌➣⋆➣╌╌──Structures  :──╌╌➣⋆➣╌╌⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

typedef struct s_tokens
{
	char			*content;						// *str con datos 
	t_type 			type; 							// **type: command, argument, redir, etc
	bool 			own_command;					//comando propio (echo, cd, pwd, export, unset, env, exit) o del sistema . ver subject minishell
	bool			expansion;						//Gestionar la expansión o no //revisar esto
	int 			position;						//posicion del nodo en la lista	(revisar si hace falta)	
	struct s_tokens *next;
}	t_tokens;

typedef struct s_cmd
{
	int		in_fd;
	int		out_fd;
	int		close_fd[2];
	char	*route;
	char	**args;
	char	**env;
}	t_cmd;

typedef struct s_program
{
	int			cmd_cont;
	int			hdoc_cont;
	int			hdoc_used;
	int			*heredocs;
	pid_t		*pid;
	t_tokens	*start_token;
	int			last_exit_status;
}	t_program;

typedef struct s_metachars
{

char **allow_oper;									//	<< >>													//✅_se usa
char **allow_metachar;								//	< > |													//✅_se usa
char **allow_op;									// < > | << >> 												//✅_se usa + //🚩 revisar: <<< (en los tokens( -> synt_error)

char **not_allow_metachar;							//	\n ; : \t & ) ( # !										//✅_se usa
char **not_allow_bracket;							//	[ { ] } 												//✅_se usa
char **is_metacharacter;							//	\t ' ' \n | & ; ( ) < >									//🚩 revisar si se usa

char **not_allow_num_redir;							//<<- << <> >> < >											//✅_se usa
char **not_allow_other_redir;						// " <<<,<<<, <<-,<<-, 2>, 2>>"    (con espacio antes)		//✅_se usa
char **not_allow_oper;								// || ;; >| $|										 		//✅_se usa
char **unexpected_token;							// 

char **not_allow_word;								// alias... 												//🚩 revisar si se usa -> check_reserved_words()
char *word;											//🚩 revisar si se usa + //reservado para meter word en las comprobaciones de variables y check_reserved_word (meta->not_allow_word)
//char *variable;

int i_current_index;								//✅_se usa reservado para el uso de check_spaces_line()
int j_new_index;									//✅_se usa reservado para el uso de check_spaces_line()

bool in_single_quote;								//✅_se usa reservado para el uso de check_spaces_line()
bool in_double_quote;								//✅_se usa reservado para el uso de check_spaces_line()

} t_metachars;

//#➵⤐╌╌➣⋆➣╌─⤏➵•➵⤐╌╌➣⋆➣╌╌─Function Prototypes : :──➣⋆➣╌⤏➵•➵⤐╌╌➣⋆➣╌╌➔#

//🔹 ✒------test_utils.c (borrar)──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

void print_metachars(const t_metachars *meta);
void print_string_array(const char *label, char **array);
void print_linked_list(t_tokens *head, int fd);
void print_type_list(t_tokens *tokens, int fd);
void print_content_list(t_tokens *tokens, int fd);
void print_list(t_tokens *tokens, int fd);
void print_split_before_list(char **token, int fd);
void print_command_line(char *line, int fd);
void print_all_test(char *line, char **token, t_tokens *tokens, int fd);

//test_funcionts.c (borrar)
char **test_ft_tokeniser(const char *line);
void test_minishell_loop (char **envp);

//-----------------test_utils_end──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#


//main.c (/5):
//int main (int argc, char *argv[], char **envp);

//utils.c (/5)
int	open_fd(char *pathern, int flags, mode_t mode);
char *get_line(void);
t_tokens	*ft_find_node_n_position(t_tokens *head, int position);

//tokenize_with_quotes.c (/5)
size_t	ft_count_tokens(const char *s);
//static char	**ft_malloc_tokens(char **array, const char *s);
//static char	**ft_cpy_tokens(char **array, const char *s);
char	**tokenize_with_quotes(const char *s);

//token_utils.c (/5)
t_metachars *init_meta_struct(void);


//🔹 ✒------check_syntax_error_1_line──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

//ckeck_quotes_utils.c (/5):
bool is_quotes_present (const char *str);														
bool quotes_is_open(const char *str);															
bool is_even_quotes(const char *str);															
bool char_is_quoted(const char *str, char character, const char *position);						
bool oper_is_quoted(const char *str, const char *operator_str, const char *position);			

//check_syntax_error_line.c (/5)
bool is_invalid_redir(const char *ptr, const char *num_start, t_metachars *meta);
bool has_invalid_numeric_redir(const char *str, t_metachars *meta);							
bool check_operator (const char *str, char **operators);										
bool not_allow_spec_operators(const char *str, t_metachars *meta);								
bool check_metacharacter (const char *str, char **character);									
bool check_syntax_error_line(const char *str, t_metachars *meta);									//revisar

//------chaeck_syntax_error_1_line_end──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#


//🔹 ✒--------------check_spaces_line──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#
//check_line_utils.c (/5)
void toggle_quotes(char c, bool *in_single_quote, bool *in_double_quote);
bool	is_operator(const char *str, const char *op);
void	update_quote_status(const char c, t_metachars *meta);

//check_spaces_line_utils.c (/5)
bool	needs_space_before(const char *line, int i);
bool	needs_space_after(const char *line, int i, int op_len);
int	count_extra_spaces(const char *line, t_metachars *meta);
int	count_spaces_for_ops(const char *line, t_metachars *meta);
char	*allocate_new_line(const char *line, t_metachars *meta);

//check_spaces_line.c (/5)
void	copy_operator(char *new_line, t_metachars *meta, const char *line, int op_len);
void	process_operators(const char *line, char *new_line, t_metachars *meta);
void	process_line(const char *line, char *new_line, t_metachars *meta);
void	replace_line(char **line, char *new_line);
void	check_spaces_line(char **line, t_metachars *meta);

//-----------check_spaces_line_end──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#


//🔹 ✒--check_syntax_error_2_token──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

//check_reserved_words.c
bool is_reserved_word(const char *word, t_metachars *meta);
void extract_word_dynamic(const char *line, int *index, char **dest);
bool is_reserved_and_unquoted(const char *line, const char *word, t_metachars *meta);
bool check_reserved_words(const char *line, t_metachars *meta);

//check_syntax_error_token.c (/5)
bool check_bash_error_token (t_tokens *tokens);
bool check_syntax_error_token(t_tokens *tokens);

//check_is_var.c (/5)


//--check_syntax_error_2_token_end──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#


//ft_tokeniser.c (/5)
char **ft_tokeniser(const char *line);
void minishell_loop(char **envp);


//🔹 ✒--check_type_tokens──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

//check_type_tokens_utils.c (/5)
bool check_pipe(t_tokens *current);
bool is_redir(t_tokens *current);
t_type check_redir(t_tokens *current);
bool check_command(t_tokens *current, t_tokens *head);
bool check_argument(t_tokens *current, t_tokens *head);

//check_type_tokens.c (/5)
bool check_own_command(t_tokens *current);
void    assign_redirection_type( t_tokens *current, t_tokens *head);
bool	assign_token_type(t_tokens *current, t_tokens *head);
void	process_tokens(t_tokens *tokens, bool *has_temp_tokens);
void	check_type_tokens(t_tokens *tokens);

//--check_type_tokens_end──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#






//free_utils.c (/5)
void	free_split_strs(char **split_strs);
void	free_tokens_list(t_tokens **tokens);
void	free_meta_struct(t_metachars *meta);


//list_utils.c (/5)
t_tokens	*find_last_node(t_tokens *tokens);
//static void initialize_node(t_tokens *tokens, char *content, int position);
//static void add_node(t_tokens **tokens, char *content, int position);
void	init_list(t_tokens **tokens, char **split_str);


//exe_cmd.c  (/5)
void		ft_wait_children(t_program *program);
int			count_node_type(t_tokens *start, t_type type);
t_tokens	*find_node_type(t_tokens *start, t_type type);
void		ft_clear_cmd(t_cmd *cmd);
void		ft_cmd_not_found(t_cmd cmd);
char		*ft_find_bin(char **path_array, char *name);
char		*find_cmd(char *name);
char		**man_arguments(t_tokens *token);
void		ft_close_fd(int fd);
void		ft_man_redir(t_program *program, t_tokens *token, t_cmd *cmd);
pid_t		ft_child(t_cmd cmd, t_tokens *token, t_program *program, char **env);
t_cmd		init_default_cmd(t_tokens *token);
t_cmd		extract_cmd(t_tokens *token, t_pipe pipe1, t_pipe pipe2);
void		tokens_to_cmds(t_program *program, char **env);

//heredoc.c
void	create_hdoc(t_program *program);
void	ft_hdoc(char *limiter, t_pipe pipe_hdoc);

#endif