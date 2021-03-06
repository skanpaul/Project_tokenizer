/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/05/18 11:02:43 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
void ft_add_history(char *new_line);

/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	char *new_line;
	char **array;
	t_vars vars;
	int fd_in;
	int fd_out;
	struct termios ta;
	
	//------------------------------------
	tcgetattr(STDIN_FILENO, &ta);
	print_termios_attributes(ta);

	
	//tcgetattr(STDIN_FILENO, &attributes);
	//attributes.c_lflag &= ~ ECHO;
	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);	
	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	//------------------------------------

	// ---------------------------------------------------
	(void)argc;
	(void)argv;
	(void)envp;
	array = NULL;
	new_line = NULL;
	// ---------------------------------------------------
	vars.loc = (t_env *)malloc(1 * sizeof(t_env));
	vars.loc->name = ft_strdup("AA");
	vars.loc->data = ft_strdup("ski");
	vars.loc->next = (t_env *)malloc(1 * sizeof(t_env));
	vars.loc->next->name = ft_strdup("?");
	vars.loc->next->data = ft_strdup("0");
	vars.loc->next->next = NULL;	
	
	// ---------------------------------------------------
	while (1)
	{
		new_line = readline("prompt> ");
		// new_line = ft_strdup("exit");
		
		ft_add_history(new_line);

		if (new_line && new_line[0] != '\0')
		{
			
			if(!is_grammar_correct(new_line, &vars))
			{	
				ft_printf("Genreral grammas is not correct\n");	
				goto label_free_line;
			}
			
			// if (is_line_with_correct_quote(new_line) == false)
			// {
			// 	ft_printf("\n ---------- !!! BAD QUOTING !!! ---------- \n");
			// 	// clean prog + exit prog
			// }

			ft_printf("---------------------------------------------------\n");
			new_line = chevron_space_maker(new_line);
			new_line = pipeline_space_maker(new_line);
			ft_printf(				   "1) space making :\t %s\n", new_line);

			array = split_shell_line(new_line, ' ');	
			print_array_in_line(array, "2) split simple :\t ");

			translate_dollars_all(array, &vars);
			print_array_in_line(array, "3) translate $  :\t ");
			
			fd_in = get_segment_fd_in(array);
			ft_printf(				   "4) get fd IN    :\t [ %d ]\n", fd_in);		
			
			if (fd_in < 0)
			{
				free_array(&array);
				goto label_free_line;
			}
				
			fd_out = get_segment_fd_out(array);	
			ft_printf(				   "5) get fd OUT   :\t [ %d ]\n", fd_out);
			
			if (fd_out < 0)
			{
				free_array(&array);
				goto label_free_line;
			}

			// --------------------
			// BLOC DE CODE A FAIRE
			// --------------------
						
			if (fd_out > 2)
				close(fd_out);
				
			if (fd_in > 2)
				close(fd_in);
			
			clear_chevron(array);
			print_array_in_line(array, "6) clear chevron:\t ");
			
			free_array(&array);
								
			if (does_word_match(new_line, "exit"))
				break ;
		}
			
label_free_line:		
		if (new_line)
			free(new_line);	
		new_line = NULL;	
		ft_printf("---------------------------------------------------\n");
	}	
	// ---------------------------------------------------
	free_var_list(&vars.loc);
	// rl_clear_history();

	if (new_line)
			free(new_line);	
		new_line = NULL;	
	
	// ---------------------------------------------------
	return (126);
}

/* ************************************************************************** */
void ft_add_history(char *new_line)
{
	if (!new_line || new_line[0] != '\0')
		add_history(new_line);
}
		
/* ************************************************************************** */