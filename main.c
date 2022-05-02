/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:47 by ski               #+#    #+#             */
/*   Updated: 2022/05/02 22:41:27 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
int main (int argc, char **argv, char **envp)
{
	t_data d;
	char *new_line;
	char *inputrc;

	inputrc = getenv("INPUTRC");
	printf("PATH .inputrc: %s\n", inputrc);
	
	new_line = NULL;
	init_struc_sigaction(&d);
	link_signal_main(&d);
	// ---------------------------------------------------
	while (1)
	{
		new_line = readline(MSG_PROMPT);
		
		if (ft_strncmp(new_line, "exit", ft_strlen("exit") + 1) == 0)
			exit(0);

		tokenizer(new_line);

		
		if (new_line)
			free(new_line);		
	}	
	// ---------------------------------------------------
	return (0);
}