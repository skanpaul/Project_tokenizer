/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grammar_pipeline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:09:45 by sorakann          #+#    #+#             */
/*   Updated: 2022/05/12 14:01:24 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
static bool	is_token_pipeline_correct(char **array, t_vars *vars);

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

    if (!is_token_pipeline_correct(array, vars))
		ft_free_null((void **)&line);
    
    free_array(&array);
    return (line);
}

/* ************************************************************************** */
static bool is_token_pipeline_correct(char **array, t_vars *vars)
{
	int i;

	i = 0;
	while(array[i])
	{
		if (does_wordstart_match(array[i], "|"))
		{
			if (!does_word_match(array[i], "|"))
			{
				update_var(&vars->loc, "?", "258"); // à refléchir
				ft_printf("minishell: syntax error near token ");
				ft_printf("\'%s\'\n", array[i]);
				return (false);
			}
		}
		i++;
	}
	return (true);
}

/* ************************************************************************** */
// static bool is_previous_token_correct(char **array, t_vars *vars)
// {
// 	int i;

// 	i = 0;
// 	while(array[i])
// 	{
// 		if( does_word_match)


		
// 	}

// 	return (true);
// }



/* ************************************************************************** */
// static bool is_next_token_correct(char **array, t_vars *vars)
// {
// 	int i;

// 	i = 0;
// 	while(array[i])
// 	{
// 		if( does_word_match)


		
// 	}

// 	return (true);
// }



/* ************************************************************************** */