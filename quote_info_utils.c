/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_info_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:28:17 by ski               #+#    #+#             */
/*   Updated: 2022/05/05 08:14:25 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
static bool	is_quote_char(char c);

/* ************************************************************************** */
// Need: variable of type [ t_quote_info ]
void	init_quote_info(t_quote_info *qti)
{
	qti->cnt_char_realquote = 0;
	qti->last_char_realquote = '\0';
	qti->flag_inside_realquote = false;
	qti->flag_entering_realquote = false;
	qti->flag_exiting_realquote = false;
}

/* ************************************************************************** */
// To use under the while (...) statement ONLY once
void	refresh_quote_info(t_quote_info *qti, char actual_char)
{
	qti->flag_entering_realquote = false;
	if (qti->flag_exiting_realquote == true)
		init_quote_info(qti);
	if (is_quote_char(actual_char))
	{
		if (qti->flag_inside_realquote == false)
		{
			qti->last_char_realquote = actual_char;
			qti->cnt_char_realquote++;
			qti->flag_inside_realquote = true;
			qti->flag_entering_realquote = true;
		}
		else
		{
			if (qti->last_char_realquote == actual_char)
			{
				qti->last_char_realquote = '\0';
				qti->cnt_char_realquote++;
				qti->flag_exiting_realquote = true;
			}			
		}
	}
}

/* ************************************************************************** */
bool	is_input_char_real_quote(t_quote_info *qti)
{
	if (qti->flag_entering_realquote)
		return (true);
	return (false);
}

/* ************************************************************************** */
bool	is_output_char_real_quote(t_quote_info *qti)
{
	if (qti->flag_exiting_realquote)
		return (true);
	return (false);
}

/* ************************************************************************** */
// To used with: [ refresh_info_quote() ]
bool	is_good_number_of_real_quote(t_quote_info *qti)
{
	if (qti->cnt_char_realquote % 2 == 0)
		return (true);
	return (false);
}

/* ************************************************************************** */
// To used in the same scope than: [ refresh_info_quote() ]
bool	is_inside_real_quote(t_quote_info *qti)
{
	if (qti->flag_inside_realquote)
		return (true);
	return (false);
}

/* ************************************************************************** */
// To used in the same scope than: [ refresh_info_quote() ]
bool	is_outside_real_quote(t_quote_info *qti)
{
	if (qti->flag_inside_realquote)
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
