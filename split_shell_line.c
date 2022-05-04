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
// static int	count_words(char *line, char separator)
int	count_words(char *line, char separator)
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
		if (line[i] != separator)
		{
			// -----------------------------------------------------------------------------------
			if (	i == 0 		|| 		(	line[i - 1] == separator	&& 		(	is_outside_real_quote(&qti) || is_input_char_real_quote(&qti)	)		)	)
				count++;

			// -----------------------------------------------------------------------------------
			
			
			
			// -----------------------------------------------------------------------------------
			// if (	(i == 0 || line[i - 1] == separator) 	&& 		is_outside_real_quote(&qti)	)
			// 	count++;
			// if (is_input_char_real_quote(&qti))
			// 	count++;	
			// -----------------------------------------------------------------------------------
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
char	**split_shell_line(char *line, char separator)
{
	char	**res;
	int		i;
	int		j;
	int		start;
	t_quote_info qti;

	init_quote_info(&qti);

	if (!line)
		return (NULL);

	res = malloc (sizeof (char *) * (count_words(line, separator) + 1));

	if (!res)
		return (NULL);
		
	i = 0;
	j = 0;
	start = 0;
	while (line[i] != '\0')
	{
		refresh_quote_info(&qti, line[i]);
		
		if (		(line[i] != separator) 		&& 		(	i == 0 || line[i - 1] == separator	)		)
		{
			start = i;
		}

		if (		(line[i] != separator) 		&& 		(	line[i + 1] == '\0') || line[i + 1] == separator		)
		{
			res[j++] = ft_substr(line, start, (i - start) + 1);
		}

		i++;

	}
	res[j] = 0;
	return (res);
}

/* ************************************************************************** */
// char	**ft_split(char const *str, char c)
// {
// 	char	**res;
// 	int		i;
// 	int		j;
// 	int		start;

// 	if (!str)
// 		return (NULL);
// 	res = malloc (sizeof (char *) * (count_words(str, c) + 1));
// 	if (!res)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	start = 0;
// 	while (str[i] != '\0')
// 	{
// 		if ((str[i] != c) && (i == 0 || (str[i - 1] == c)))
// 			start = i;
// 		if ((str[i] != c) && ((str[i + 1] == '\0') || (str[i + 1] == c)))
// 			res[j++] = ft_substr(str, start, (i - start) + 1);
// 		i++;
// 	}
// 	res[j] = 0;
// 	return (res);
// }

/* ************************************************************************** */