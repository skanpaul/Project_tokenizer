/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/05/08 10:38:09 by sorakann         ###   ########.fr       */
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
		// new_line = ft_strdup("$AAh");
		ft_add_history(new_line);

		if (is_line_with_correct_quote(new_line) == false)
		{
			ft_printf("\n ---------- !!! BAD QUOTING !!! ---------- \n");
			// clean prog + exit prog
		}

		new_line = chevron_space_maker(new_line);
		new_line = pipeline_space_maker(new_line);
		ft_printf("space making:\t\t %s\n", new_line);

		// array = ft_split(new_line, '|');		
		// array = split_shell_line(new_line, '|');	





		

		new_line = translate_dollar(new_line, &vars);
		// new_line = replace_vars(&vars, new_line);





		ft_printf("translating dollar:\t %s\n", new_line);
		ft_printf("\n");
		
			
		// ft_printf("\n");
		// print_array(array);
		// ft_printf("\n");
		
		// free_array(array);
			
							
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