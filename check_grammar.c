/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grammar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:19:45 by sorakann          #+#    #+#             */
/*   Updated: 2022/05/16 16:13:15 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
// return NULL if general grammar is not correct
// !!! WARNING !!!: exit the main program if NULL is returned
char    *check_grammar(char *line, t_vars *vars)
{
	char *cpy_line;

	cpy_line = ft_strdup(line);

	is_line_with_correct_quote(cpy_line)
	
	cpy_line = chevron_space_maker(cpy_line);
	cpy_line = pipeline_space_maker(cpy_line);
	
	if (!line)
		return (NULL);
	
	line = check_grammar_pipeline(line, vars);
	if (!line)
		return (line);
		
	line = check_grammar_chevron(line, vars);
	if (!line)
		return (line);

    return (line);
}

/* ************************************************************************** */
// return NULL if general grammar is not correct
// !!! WARNING !!!: exit the main program if NULL is returned
bool	is_grammar_correct(char *line, t_vars *vars)
{
	char *cpy_line;

	cpy_line = ft_strdup(line);

	if (!is_line_with_correct_quote(cpy_line))
	{
		ft_free_null((void **)&cpy_line);
		return (false);
	}
	
	cpy_line = chevron_space_maker(cpy_line);
	cpy_line = pipeline_space_maker(cpy_line);
	
	if (!line)
		return (NULL);
	
	line = check_grammar_pipeline(line, vars);
	if (!line)
		return (line);
		
	line = check_grammar_chevron(line, vars);
	if (!line)
		return (line);

    return (line);
}

/* ************************************************************************** */