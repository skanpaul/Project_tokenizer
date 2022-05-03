/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 06:15:33 by sorakann          #+#    #+#             */
/*   Updated: 2022/05/03 08:33:35 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
bool	is_chevron(char c);
bool	is_prev_char_correct(char *line, int actual_position);
bool	is_next_char_correct(char *line, int actual_position);
bool	is_white_space(char c);
char	*insert_space_before_actual_pos(char *line, int *actual_position);
char	*insert_space_after_actual_pos(char *line, int *actual_position);

/* ************************************************************************** */
char *chevron_space_maker(char *line)
{
    int i;
    int size_line;

    size_line = ft_strlen(line);

	i = 0;
    while (line[i] != 0)
	{
		if (is_chevron(line[i]))
		{
			if (is_prev_char_correct(line, i) == false)
				line = insert_space_before_actual_pos(line, &i);

			if (is_next_char_correct(line, i) == false)
				line = insert_space_after_actual_pos(line, &i);
		}
		i++;		
	}
    
}

/* ************************************************************************** */
char	*insert_space_after_actual_pos(char *line, int *actual_position)
{
	char *start;
	char *start_with_space;
	char *end;
	int len;

	start = NULL;
	start_with_space = NULL;
	end = NULL;
	len = ft_strlen(line);
	
	start = ft_substr(line, 0, *actual_position);
	end = ft_substr(line, *actual_position + 1, len - 1 ); 

	start_with_space = ft_strjoin(start, " ");
	free(start);
	
	free(line);
	line = ft_strjoin(start_with_space, end);

	free(start_with_space);
	free(end);

	(*actual_position)++;
	return (line);	
}

/* ************************************************************************** */
char	*insert_space_before_actual_pos(char *line, int *actual_position)
{
	char *start;
	char *start_with_space;
	char *end;
	int len;

	start = NULL;
	start_with_space = NULL;
	end = NULL;
	len = ft_strlen(line);
	
	start = ft_substr(line, 0, *actual_position - 1);
	end = ft_substr(line, *actual_position, len - 1); 

	start_with_space = ft_strjoin(start, " ");
	free(start);
	
	free(line);
	line = ft_strjoin(start_with_space, end);

	free(start_with_space);
	free(end);

	(*actual_position)++;
	return (line);
}

/* ************************************************************************** */
bool is_chevron(char c)
{
    if (c == '<' || c == '>')
        return (true);
    return (false);
}

/* ************************************************************************** */
// Correct means: another chevron or white space
/* ************************************************************************** */
bool	is_prev_char_correct(char *line, int actual_position)
{
	if (actual_position == 0)
		return (true);
		
	if (is_chevron(line[actual_position - 1]))
		return (true);

	if (is_white_space(line[actual_position - 1]))
		return (true);
	
	return (false);	
}

/* ************************************************************************** */
// Correct means: another chevron or white space
/* ************************************************************************** */
bool	is_next_char_correct(char *line, int actual_position)
{
	int len;

	len = ft_strlen(line);
		
	if (actual_position == len - 1)
		return (true);
		
	if (is_chevron(line[actual_position + 1]))
		return (true);

	if (is_white_space(line[actual_position + 1]))
		return (true);
		
	return (false);	
}

/* ************************************************************************** */
bool	is_white_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

/* ************************************************************************** */
