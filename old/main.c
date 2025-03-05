

#include "minishell.h"

int g_sign = 0;

void manejador(int sign)
{
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_sign = sign;
}

// void ft_nothing(int sign)
// {
// 	(void)sign;
// } En memoria de la mejor funcion (aprobada por Alvaro deidad)

//esta versión solo lee comandos de 1 linea, si hay lineas ver como se comporta shell
int main (int argc, char *argv[], char **envp)
{
	if (argc != 1 || argv[1])
	{
		printf("\033[1;31m🛑 ERROR: argumento incorrecto (gestionar este mensaje).\n\033[0m");		//gestionar mensaje de error
		return (1);			
	}
	else 
	{
		//signal(SIGINT, manejador);
		//signal(SIGQUIT, SIG_IGN);
		test_minishell_loop (envp);
		//minishell_loop(envp);
	}
		
	return (0);
}
