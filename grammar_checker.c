/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:10:05 by ski               #+#    #+#             */
/*   Updated: 2022/05/11 18:29:38 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
static bool	is_token_chevron_correct(char **array);
static bool	has_good_token_for_chevron(char **array);

/* ************************************************************************** */
// !!! WARNING: exit the program if NULL is returned
// -------------------------------------------------
// RETURN: NULL if grammar is not correct and 
//
// --> pipeline symbol [ | ] HAS TO BE FOLLOWED by
//		a) letter
//		b) number
//		c) underscore
//		d) chevron symbols
//		e) nothing ==> SPECIAL CASE
// -------------------------------------------------
// !!! WARNING: exit the program if NULL is returned
char	*grammar_checker(char *line, t_vars *vars)
{
	char	**array;

	array = NULL;
	
	array = split_shell_line(line, ' ');
	print_array_in_line(array, "1.1) tokens     :\t ");
	translate_dollars_all(array, vars);
	print_array_in_line(array, "1.2) tok. trans.:\t ");
	
	if (!is_token_chevron_correct(array))
	{
		free_array(&array);
		// free line a un moment donné
		return (NULL);
	}
	
	if (!has_good_token_for_chevron(array))
	{
		free_array(&array);
		// free line a un moment donné
		return (NULL);
	}


	
	free_array(&array);
	return (line);
}

/* ************************************************************************** */
// chevron token [ < , << , > , >> ] HAVE TO BE FOLLOWED
// by a token without
//				- [ < ] single or multiple
//				- [ > ] single or multiple
//				- [ | ] single or multiple
// static bool	is_next_token_correct_for_chevron(char **array)
static bool	has_good_token_for_chevron(char **array)
{
	int i;
	char *next_token;

	i = 0;
	while(array[i])
	{
		if (does_word_match(array[i], "<") || does_word_match(array[i], "<<")
			|| does_word_match(array[i], ">") || does_word_match(array[i], ">>"))
		{
			next_token = array[i + 1];
			if(!next_token || does_wordstart_match(next_token, "<")
				|| does_wordstart_match(next_token, ">")
				|| does_wordstart_match(next_token, "|"))
			{
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
static bool	is_token_chevron_correct(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (does_wordstart_match(array[i], "<")
			|| does_wordstart_match(array[i], ">"))
		{
			if (!does_word_match(array[i], "<")
				&& !does_word_match(array[i], "<<")
				&& !does_word_match(array[i], ">")
				&& !does_word_match(array[i], ">>"))
			{
				ft_printf("minishelle: syntax error near token ");
				ft_printf("\'%s\'\n", array[i]);
				return (false);
			}
		}
		i++;
	}
	return (true);
}
/* ************************************************************************** */