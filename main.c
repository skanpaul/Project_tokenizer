/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/05/04 16:13:03 by ski              ###   ########.fr       */
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
	
	// ---------------------------------------------------
	while (1)
	{
		new_line = readline(MSG_PROMPT);
		ft_add_history(new_line);

		if (is_line_with_correct_quote(new_line) == false)
			ft_printf("\n ---------- !!! BAD QUOTING !!! ---------- \n");

		new_line = chevron_space_maker(new_line);
		new_line = pipeline_space_maker(new_line);
		ft_printf("space maker APRES: %s\n", new_line);
		ft_printf("\n");

		// array = split_shell_line(new_line, ' ');
		
		// print_array(array);
			
							
		if (ft_strncmp(new_line, "exit", ft_strlen("exit") + 1) == 0)
			exit(0);
		
		if (new_line)
			free(new_line);		
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