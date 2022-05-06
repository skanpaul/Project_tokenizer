/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:22:02 by ski               #+#    #+#             */
/*   Updated: 2022/05/06 12:13:34 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
static bool	is_char_for_dolvar_name(char c);
static bool	is_vardol(char *str, int i_dollars);
static int	get_end_pos_vardol(char *str, int start_pos);

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
					// subsitute var dol
				}
			}
		}
		// ----------------------------------------------------
		i++;
	}
	return (str);
}

/* ************************************************************************** */
static char	*substitute_vardol(char *str, int *star_pos, t_vars *vars)
{
	int		i;	
	int		end_pos;
	int		qty;
	char	*buf_1;
	char	*buf_2;
	char	*var_data;

	end_pos = get_end_pos_vardol(str, *star_pos);
	
	qty = *star_pos;
	buf_1 = ft_substr(str, 0, qty);
	
	qty = ft_strlen(str) - end_pos - 1;
	buf_2 = ft_substr(str, end_pos + 1, qty);

	ft_free_null((void**)&str);
	
	var_data = NULL;
	
	if (does_var_exist(vars->env, &str[*star_pos + 1]))
		var_data = get_var(vars->env, &str[*star_pos + 1])->data;	
	else if (does_var_exist(vars->loc, &str[*star_pos + 1]))
		var_data = get_var(vars->env, &str[*star_pos + 1])->data;
	else
	{
		// startpos - 1
	}

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