/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:22:02 by ski               #+#    #+#             */
/*   Updated: 2022/05/06 14:09:26 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
static bool	is_char_for_dolvar_name(char c);
static bool	is_vardol(char *str, int i_dollars);
static int	get_end_pos_vardol(char *str, int start_pos);
static char	*substitute_vardol(char *str, int *start_pos, t_vars *vars);

/* ************************************************************************** */
char	*translate_dollar(char *str, t_vars *vars)
{
	int				i;
	t_quote_info	qti;

	(void)vars;
	init_quote_info(&qti);
	i = 0;
	while (str[i] != 0)
	{
		refresh_quote_info(&qti, str[i]);
		// ----------------------------------------------------
		if (str[i] == '$')
		{
			if (is_inside_single_realquote(&qti) == false)
			{
				if (is_vardol(str, i))
				{
					str = substitute_vardol(str, &i, vars);
				}
			}
		}
		// ----------------------------------------------------
		i++;
	}
	return (str);
}

/* ************************************************************************** */
// WARNING: [*start_pos] is the position of the [$] sign
// [ end_pos ] is the position of the last caracters of the dollar-variable
static char	*substitute_vardol(char *str, int *start_pos, t_vars *vars)
{
	int		i;	
	int		end_pos;
	int		qty;
	char	*buf_1;
	char	*buf_2;
	char	*var_data;

	//-----------------------------------------------
	i = 0;
	end_pos = 0;
	qty = 0;
	buf_1 = NULL;
	buf_2 = NULL;
	var_data = NULL;	
	//-----------------------------------------------

	end_pos = get_end_pos_vardol(str, *start_pos);
	
	qty = *start_pos;
	buf_1 = ft_substr(str, 0, qty);
	
	qty = ft_strlen(str) - end_pos - 1;
	buf_2 = ft_substr(str, end_pos + 1, qty);
	
	var_data = NULL;
	
	if (does_var_exist(vars->env, &str[*start_pos + 1]))
		var_data = get_var(vars->env, &str[*start_pos + 1])->data;	
	else if (does_var_exist(vars->loc, &str[*start_pos + 1]))
		var_data = get_var(vars->loc, &str[*start_pos + 1])->data;
	else
	{
		*start_pos = *start_pos - 1;
	}
	ft_free_null((void**)&str);
	
	str = ft_strjoin(buf_1, var_data);
	ft_free_null((void**)&buf_1);

	buf_1 = str;
	
	str = ft_strjoin(buf_1, buf_2);
	ft_free_null((void**)&buf_1);
	ft_free_null((void**)&buf_2);

	
	return (str);
}

/* ************************************************************************** */
static int	get_end_pos_vardol(char *str, int start_pos)
{
	int	i;

	i = 0;
	while (is_char_for_dolvar_name(str[i + 1]))
		i++;
	return (i);
}

/* ************************************************************************** */
static bool	is_char_for_dolvar_name(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

/* ************************************************************************** */
static bool	is_vardol(char *str, int i_dollars)
{
	if (is_char_for_dolvar_name(str[i_dollars + 1]))
		return (true);
	return (false);
}

/* ************************************************************************** */