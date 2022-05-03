/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/05/03 13:35:33 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	t_data d;
	char *new_line;
	char **token_array;
	
	new_line = NULL;
	token_array = NULL;

	new_line = ft_strdup("salut << ?");
	new_line = chevron_space_maker(new_line);
	new_line = pipeline_space_maker(new_line);

	token_array = tokenizer(new_line);

	print_array(token_array);
	if (token_array)
		free_array(token_array);
	token_array = NULL;

		
	return (0);
	
	// ---------------------------------------------------
	while (1)
	{
		new_line = readline(MSG_PROMPT);
		
		// ft_printf("\n");
		// ft_printf("space maker AVANT: %s\n", new_line);
		new_line = chevron_space_maker(new_line);
		new_line = pipeline_space_maker(new_line);
		// ft_printf("\n");
		// ft_printf("space maker APRES: %s\n", new_line);
		// ft_printf("\n");
		
		
		
		if (ft_strncmp(new_line, "exit", ft_strlen("exit") + 1) == 0)
			exit(0);
		
		if (new_line)
			free(new_line);		
	}	
	// ---------------------------------------------------
	return (0);
}