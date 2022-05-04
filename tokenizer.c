/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:19:52 by ski               #+#    #+#             */
/*   Updated: 2022/05/03 14:27:38 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
static bool is_double_quote_correct(char *line);
static bool is_single_quote_correct(char *line);
static bool is_line_empty(char *line);
static void add_token(char ***token_array, char *token);
static void copy_array(char ***array_src, char ***array_dst);
static int 	get_size_array(char **token_array);

/* ************************************************************************** */
char **tokenizer(char *line)
{
	char **token_array;
	char *str1;
	char *str2;

	token_array = NULL;
	
	//---------------------------------------------------------------------
	if (is_line_empty(line))
	{
		ft_printf("PROBLEME: line is EMPTY\n");
		return (NULL);
	}
	//---------------------------------------------------------------------
	if ( !is_single_quote_correct(line) || !is_double_quote_correct(line))
	{
		ft_printf("PROBLEME with single or double quote\n");
		return (NULL);
	}
	//---------------------------------------------------------------------
	// splitter selon>
	// 1) whitespace
	// 2) chevron
	// 3) 
	
	
	return token_array;		
}

/* ************************************************************************** */
static void add_token(char ***token_array, char *token)
{
	int size_array;
	char **buff_array;
	
	if (*token_array == NULL)
	{
		*token_array = (char **)malloc(2 * sizeof(char *));
		(*token_array)[0] = token;
		(*token_array)[1] = NULL;
	}
	else
	{
		size_array = get_size_array(*token_array);		
		buff_array = (char **)malloc(size_array + 2 * sizeof(char *));		
		copy_array(token_array, &buff_array);
		buff_array[size_array] = token;
		buff_array[size_array + 1] = NULL;		
		free(*token_array);		
		*token_array = buff_array;			
	}	
}
/* ************************************************************************** */
static int get_size_array(char **token_array)
{
	int i;

	i = 0;
	while (token_array[i] != NULL)
		i++;
		
	return (i);
}

/* ************************************************************************** */
static void copy_array(char ***array_src, char ***array_dst)
{
	int i;
	int size_src;

	size_src = get_size_array(*array_src);

	i = 0;
	while ((*array_src)[i] != NULL)
	{
		(*array_dst)[i] = (*array_src)[i];
		i++;		
	}	
	
}

/* ************************************************************************** */
static bool is_line_empty(char *line)
{
	int i;

	if (line == NULL)
		return (true);

	if (line[0] == '\0')
		return (true);

	return(false);
}
/* ************************************************************************** */
static bool is_double_quote_correct(char *line)
{
	int i;
	int cnt_quote;

	cnt_quote = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\"')
			cnt_quote++;
		i++;
	}
	if (cnt_quote % 2 == 0)
		return (true);
	return (false);	
}
/* ************************************************************************** */
static bool is_single_quote_correct(char *line)
{
	int i;
	int cnt_quote;

	cnt_quote = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\'')
			cnt_quote++;
		i++;
	}
	if (cnt_quote % 2 == 0)
		return (true);
	return (false);	
}

/* ************************************************************************** */