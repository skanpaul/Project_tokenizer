/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_info_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:28:17 by ski               #+#    #+#             */
/*   Updated: 2022/05/04 10:47:25 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
static bool is_pair(int n);
static bool is_quote_char(char c);

/* ************************************************************************** */
void init_quote_info(t_quote_info *qti)
{
	qti->cnt_real_quote = 0;
	qti->mem_real_quote = '\0';
	qti->in_real_quote = false;
}
/* ************************************************************************** */
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
static bool is_quote_char(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

/* ************************************************************************** */
static bool is_pair(int n)
{
	int reste;

	reste = n % 2;
	if (reste == 0)
		return (true);
	return (false);	
}
/* ************************************************************************** */
