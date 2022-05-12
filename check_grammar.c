/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grammar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:19:45 by sorakann          #+#    #+#             */
/*   Updated: 2022/05/12 12:34:04 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
// return NULL if general grammar is not correct
// !!! WARNING !!!: exit the main program if NULL is returned
char    *check_grammar(char *line, t_vars *vars)
{

	if (!line)
		return (NULL);
	
	line = check_grammar_chevron(line, vars);

    return (line);
}

/* ************************************************************************** */