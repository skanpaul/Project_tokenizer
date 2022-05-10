/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/05/10 10:46:54 by ski              ###   ########.fr       */
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
	int cnt_w;
	t_vars vars;
	int i;
	int fd_in;

	// ---------------------------------------------------
	array = NULL;
	new_line = NULL;
	cnt_w = 0;
	// ---------------------------------------------------

	vars.loc = (t_env *)malloc(1 * sizeof(t_env));

	vars.loc->name = ft_strdup("AA");
	// vars.loc->data = ft_strdup("\'\'\'");
	vars.loc->data = ft_strdup("ski");
	vars.loc->next = NULL;
	
	// ---------------------------------------------------
	while (1)
	{
		new_line = readline(MSG_PROMPT);
		// new_line = ft_strdup("<< end grep jus <file");
		ft_add_history(new_line);

		if (is_line_with_correct_quote(new_line) == false)
		{
			ft_printf("\n ---------- !!! BAD QUOTING !!! ---------- \n");
			// clean prog + exit prog
		}

		new_line = chevron_space_maker(new_line);
		new_line = pipeline_space_maker(new_line);
		ft_printf(				   "0) space making :\t %s\n", new_line);
		
		
		array = split_shell_line(new_line, ' ');	
		print_array_in_line(array, "1) split simple :\t ");

		translate_dollars_all(array, &vars);
		print_array_in_line(array, "2) translate $  :\t ");
		
		fd_in = get_fd_in(array);
		ft_printf(				   "3) get fd IN    :\t [ %d ]\n", fd_in);

		
		clear_chevron(array);
		print_array_in_line(array, "4) clear chevron  :\t ");
		
		free_array(array);
							
		if (ft_strncmp(new_line, "exit", ft_strlen("exit") + 1) == 0)
			exit(0);
		
		if (new_line)
			free(new_line);		

		ft_printf("========= BOUCLE ========\n");
	}	
	// ---------------------------------------------------
	return (0);
}

/* ************************************************************************** */

		// ft_printf("\n");
		// ft_printf("space maker AVANT: %s\n", new_line);
		// new_line = chevron_space_maker(new_line);
		// new_line = pipeline_space_maker(new_line);
		// ft_printf("\n");
		// ft_printf("space maker APRES: %s\n", new_line);
		// ft_printf("\n");

/* ************************************************************************** */
void ft_add_history(char *new_line)
{
	if (new_line[0] != '\0')
		add_history(new_line);
}
		
/* ************************************************************************** */