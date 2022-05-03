/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/05/03 09:24:43 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	t_data d;
	char *new_line;
	char *inputrc;
	
	new_line = NULL;
	init_struc_sigaction(&d);
	link_signal_main(&d);

	new_line = ft_strdup("abcd<efgh");
	ft_printf("\n");
	ft_printf("space maker AVANT: %s\n", new_line);
	new_line = chevron_space_maker(new_line);
	ft_printf("\n");
	ft_printf("space maker APRES: %s\n", new_line);
	ft_printf("\n");

	
	// ---------------------------------------------------
	while (1)
	{
		new_line = readline(MSG_PROMPT);
		
		ft_printf("\n");
		ft_printf("space maker AVANT: %s\n", new_line);
		new_line = chevron_space_maker(new_line);
		ft_printf("\n");
		ft_printf("space maker APRES: %s\n", new_line);
		ft_printf("\n");
		
		if (ft_strncmp(new_line, "exit", ft_strlen("exit") + 1) == 0)
			exit(0);

		

		
		if (new_line)
			free(new_line);		
	}	
	// ---------------------------------------------------
	return (0);
}