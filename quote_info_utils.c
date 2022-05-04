/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_info_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:28:17 by ski               #+#    #+#             */
/*   Updated: 2022/05/04 14:46:30 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
static bool is_quote_char(char c);

/* ************************************************************************** */
// Need: variable of type [ t_quote_info ]
void init_quote_info(t_quote_info *qti)
{
	qti->cnt_real_quote = 0;
	qti->mem_real_quote = '\0';
	qti->inside = false;
	qti->is_real_quote_input = false;
	qti->is_real_quote_output = false;
}

/* ************************************************************************** */
// To use under the while (...) statement ONLY once
void refresh_quote_info(t_quote_info *qti, char actual_char)
{
	qti->is_real_quote_input = false;
	qti->is_real_quote_output = false;
	if (is_quote_char(actual_char))
		{
			if (qti->inside == false)
			{
				qti->mem_real_quote = actual_char;
				qti->cnt_real_quote++;
				qti->inside = true;
				qti->is_real_quote_input = true;
			}
			else // (inside == true)
			{
				if (qti->mem_real_quote == actual_char)
				{
					qti->mem_real_quote = '\0';
					qti->cnt_real_quote++;
					qti->inside = false;
					qti->is_real_quote_output = true;
				}				
			}			
		}
}

/* ************************************************************************** */
// bool is_real_quote_char_input(t_quote_info *qti)
// {
	
// }

// /* ************************************************************************** */
// bool is_real_quote_char_outpu(t_quote_info *qti)
// {
	
// }

/* ************************************************************************** */
// To used with: [ refresh_info_quote() ]
bool is_good_number_of_real_quote(t_quote_info *qti)
{
	if (qti->cnt_real_quote % 2 == 0)
		return (true);
	return (false);	
}

/* ************************************************************************** */
// To used in the same scope than: [ refresh_info_quote() ]
bool is_char_in_real_quote(t_quote_info *qti)
{
	if (qti->inside)
		return (true);
	return (false);
}

/* ************************************************************************** */
// To used in the same scope than: [ refresh_info_quote() ]
bool is_char_out_real_quote(t_quote_info *qti)
{
	if (qti->inside)
		return (false);
	return (true);
}

/* ************************************************************************** */
static bool is_quote_char(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

/* ************************************************************************** */
