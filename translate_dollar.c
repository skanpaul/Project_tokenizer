/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:22:02 by ski               #+#    #+#             */
/*   Updated: 2022/05/06 11:04:58 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
static bool is_char_for_dolvar_name(char c);

/* ************************************************************************** */
void translate_dollar(char *str, t_vars *vars)
{
	int i;
	t_quote_info qti;
	
	(void)vars;

	init_quote_info(&qti);
	
	i = 0;
	while (str[i] != 0)
	{
		refresh_quote_info(&qti, str[i]);



		// code manquant
		
		
		
		i++;
	}

}


/* ************************************************************************** */
static bool is_char_for_dolvar_name(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

/* ************************************************************************** */
bool is_dollar_variable(char *ptr_dollar)
{
	if (ptr_dollar[1] != ' ' || ptr_dollar[1] != '\'' || ptr_dollar[1] != '\"')
		return (false);
	return (true);
}
/* ************************************************************************** */