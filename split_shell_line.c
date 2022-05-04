/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell_line.delimiter                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:29:32 by gudias            #+#    #+#             */
/*   Updated: 2022/05/04 11:45:00 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
static bool is_quote_char(char c);

/* ************************************************************************** */
static int	count_words(char *line, char delimiter)
{
	int	i;
	int	count;
	t_quote_info qti;

	init_quote_info(&qti);

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		refresh_quote_info(&qti, line[i]);

		// ------------------------------------------------
		if (line[i] != delimiter)
		{
			if ((i == 0 || line[i - 1] == delimiter) && is_outside_real_quote(&qti))
				count++;

			if (is_input_char_real_quote(&qti))
				count++;	
		}
		// ------------------------------------------------
		i++;
		// ------------------------------------------------
	}
	return (count);
}

		// if ((str[i] != c) && ((i == 0) || (str[i - 1] == c)))
		// 	count++;
		// i++;

/* ************************************************************************** */
char	**split_shell_line(char *line, char delimiter)
{
	char	**res;
	int		i;
	int		j;
	int		start;
	t_quote_info qti;

	init_quote_info(&qti);

	if (!line)
		return (NULL);

	res = malloc (sizeof (char *) * (count_words(line, delimiter) + 1));

	if (!res)
		return (NULL);
		
	i = 0;
	j = 0;
	start = 0;
	while (line[i] != '\0')
	{
		refresh_quote_info(&qti, line[i]);
		if (is_input_char_real_quote(&qti) 
			|| ((line[i] != delimiter) && (i == 0 || (line[i - 1] == delimiter))))
			start = i;
		if ((line[i] != delimiter) && ((line[i + 1] == '\0') || (line[i + 1] == delimiter)))
			res[j++] = ft_substr(line, start, (i - start) + 1);
		i++;
	}
	res[j] = 0;
	return (res);
}

/* ************************************************************************** */
static bool is_quote_char(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

/* ************************************************************************** */