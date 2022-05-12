/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grammar_chevron.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:10:05 by ski               #+#    #+#             */
/*   Updated: 2022/05/12 12:32:52 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
static bool	is_token_chevron_correct(char **array);
static bool	is_next_token_correct(char **array);

/* ************************************************************************** */
// return NULL if grammar about chevron is not correct
// !!! WARNING !!!: exit the main program if NULL is returned
char	*check_grammar_chevron(char *line, t_vars *vars)
{
	char	**array;

	if (!line)
		return (NULL);
	
	array = NULL;
	array = split_shell_line(line, ' ');
	print_array_in_line(array, "A)   tokens     :\t ");
	translate_dollars_all(array, vars);
	print_array_in_line(array, "B)   tok. trans.:\t ");
	
	if (!is_token_chevron_correct(array) || !is_next_token_correct(array))
		ft_free_null((void **)line);
		
	free_array(&array);
	return (line);
}

/* ************************************************************************** */
// chevron token like [ < , << , > , >> ] are correct
// [ <<< , <<<< , ... , >>> , >>>>, ...] are NOT correct
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
// chevron token [ < , << , > , >> ] HAVE TO BE FOLLOWED
// by a next_token WITHOUT
//				- [ < ] single or multiple
//				- [ > ] single or multiple
//				- [ | ] single or multiple
static bool	is_next_token_correct(char **array)
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