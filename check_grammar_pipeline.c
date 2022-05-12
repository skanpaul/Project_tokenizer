/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grammar_pipeline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:09:45 by sorakann          #+#    #+#             */
/*   Updated: 2022/05/12 12:37:22 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
// RETURN: NULL if grammar is not correct and 
//
// --> pipeline symbol [ | ] HAS TO BE FOLLOWED by
//		a) letter
//		b) number
//		c) underscore
//		d) chevron symbols
//		e) nothing ==> SPECIAL CASE
// -------------------------------------------------
// !!! WARNING: exit the main program if NULL is returned
char	*check_grammar_pipeline(char *line, t_vars *vars)
{
    char	**array;

	if (!line)
		return (NULL);
	
	array = NULL;
	array = split_shell_line(line, ' ');
	print_array_in_line(array, "A)   tokens     :\t ");
	translate_dollars_all(array, vars);
	print_array_in_line(array, "B)   tok. trans.:\t ");

    

    
    free_array(&array);
    return (line);
}

/* ************************************************************************** */

