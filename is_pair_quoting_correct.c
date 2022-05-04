/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pair_quoting_correct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:27:20 by ski               #+#    #+#             */
/*   Updated: 2022/05/04 10:31:26 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
typedef struct s_quote_info
{
	cnt_real_quote;
	mem_real_quote;
	in_real_quote;
	
}	t_quote_info;

/* ************************************************************************** */
static bool is_pair(int n);
static bool is_quote_char(char c);
static void init_quote_info(t_quote_info *qti);

/* ************************************************************************** */
bool is_pair_quoting_correct(char *line)
{
	int i;
	int cnt_real_quote;
	
	bool in_real_quote;
	char mem_real_quote;

	cnt_real_quote = 0;
	mem_real_quote = '\0';
	in_real_quote = false;
	
	i = 0;
	while (line[i] != '\0')
	{
		if (is_quote_char(line[i]))
		{
			if (in_real_quote == false)
			{
				mem_real_quote = line[i];
				cnt_real_quote++;
				in_real_quote = true;
			}
			else // (in_real_quote == true)
			{
				if (mem_real_quote == line[i])
				{
					mem_real_quote = '\0';
					cnt_real_quote++;
					in_real_quote = false;
				}				
			}			
		}
		i++;
	}
	if (is_pair(cnt_real_quote))
		return (true);
	return (false);
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