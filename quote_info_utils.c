/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_info_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:28:17 by ski               #+#    #+#             */
/*   Updated: 2022/05/04 11:29:09 by ski              ###   ########.fr       */
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
	qti->in_real_quote = false;
}

/* ************************************************************************** */
// Need: [ init_quote_info () ] | To use after scanning each charaters
void refresh_quote_info(t_quote_info *qti, char actual_char)
{
	if (is_quote_char(actual_char))
		{
			if (qti->in_real_quote == false)
			{
				qti->mem_real_quote = actual_char;
				qti->cnt_real_quote++;
				qti->in_real_quote = true;
			}
			else // (in_real_quote == true)
			{
				if (qti->mem_real_quote == actual_char)
				{
					qti->mem_real_quote = '\0';
					qti->cnt_real_quote++;
					qti->in_real_quote = false;
				}				
			}			
		}
}

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
	if (qti->in_real_quote)
		return (true);
	return (false);
}

/* ************************************************************************** */
// To used in the same scope than: [ refresh_info_quote() ]
bool is_char_out_real_quote(t_quote_info *qti)
{
	if (qti->in_real_quote)
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
