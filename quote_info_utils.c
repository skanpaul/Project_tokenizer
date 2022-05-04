/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_info_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:28:17 by ski               #+#    #+#             */
/*   Updated: 2022/05/04 16:23:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
static bool	is_quote_char(char c);

/* ************************************************************************** */
// Need: variable of type [ t_quote_info ]
void	init_quote_info(t_quote_info *qti)
{
	qti->cnt_real_quote = 0;
	qti->mem_real_quote = '\0';
	qti->inside = false;
	qti->flag_input_char = false;
	qti->flag_output_char = false;
}

/* ************************************************************************** */
// To use under the while (...) statement ONLY once
void	refresh_quote_info(t_quote_info *qti, char actual_char)
{
	qti->flag_input_char = false;
	if (qti->flag_output_char == true)
		init_quote_info(qti);
	if (is_quote_char(actual_char))
	{
		if (qti->inside == false)
		{
			qti->mem_real_quote = actual_char;
			qti->cnt_real_quote++;
			qti->inside = true;
			qti->flag_input_char = true;
		}
		else
		{
			if (qti->mem_real_quote == actual_char)
			{
				qti->mem_real_quote = '\0';
				qti->cnt_real_quote++;
				qti->flag_output_char = true;
			}			
		}
	}
}
	// if (!qti->flag_output_char && !qti->flag_input_char)
	// 	ft_printf("[%c]\n", actual_char);
	// if (qti->flag_input_char)
	// 	ft_printf("[%c] INPUT QUOTE\n", actual_char);
	// if (qti->flag_output_char)
	// 	ft_printf("[%c] OUTPUT QUOTE\n", actual_char);

/* ************************************************************************** */
bool	is_input_char_real_quote(t_quote_info *qti)
{
	if (qti->flag_input_char)
		return (true);
	return (false);
}

/* ************************************************************************** */
bool	is_output_char_real_quote(t_quote_info *qti)
{
	if (qti->flag_output_char)
		return (true);
	return (false);
}

/* ************************************************************************** */
// To used with: [ refresh_info_quote() ]
bool	is_good_number_of_real_quote(t_quote_info *qti)
{
	if (qti->cnt_real_quote % 2 == 0)
		return (true);
	return (false);
}

/* ************************************************************************** */
// To used in the same scope than: [ refresh_info_quote() ]
bool	is_inside_real_quote(t_quote_info *qti)
{
	if (qti->inside)
		return (true);
	return (false);
}

/* ************************************************************************** */
// To used in the same scope than: [ refresh_info_quote() ]
bool	is_outside_real_quote(t_quote_info *qti)
{
	if (qti->inside)
		return (false);
	return (true);
}

/* ************************************************************************** */
static bool	is_quote_char(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

/* ************************************************************************** */
