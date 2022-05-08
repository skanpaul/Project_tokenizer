/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:22:02 by ski               #+#    #+#             */
/*   Updated: 2022/05/08 11:23:35 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/* ************************************************************************** */
static bool	is_char_for_dolvar_name(char c);
static bool	is_vardol(char *str, int i);
static int	get_end_pos_vardol(char *str, int start_pos);
static char	*substitute_vardol(char *str, int *start_pos, t_vars *vars);
static char	*delete_char(char *str, int *i);

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
		
		if ((is_vardol(str, i)) && ( !is_inside_single_realquote(&qti)))
			str = substitute_vardol(str, &i, vars);
			
		if ((is_entering_realquote(&qti) || is_exiting_realquote(&qti)))
			str = delete_char(str, &i);
			
		i++;
	}
	return (str);
}

/* ************************************************************************** */
static char	*delete_char(char *str, int *i)
{
	int		len;
	char	*buf_1;
	char	*buf_2;

	buf_1 = NULL;
	buf_2 = NULL;
	len = ft_strlen(str);
	buf_1 = ft_substr(str, 0, *i);
	buf_2 = ft_substr(str, *i + 1, len - *i - 1);
	ft_free_null((void **)&str);
	str = ft_strjoin(buf_1, buf_2);
	(*i)--;
	ft_free_null((void **)&buf_1);
	ft_free_null((void **)&buf_2);
	return (str);
}

/* ************************************************************************** */
// WARNING: [*start_pos] is the position of the [$] sign
// [ end_pos ] is the position of the last caracters of the dollar-variable
static char	*substitute_vardol(char *str, int *start_pos, t_vars *vars)
{
	int		end_pos;
	char	*buf_1;
	char	*buf_2;
	char	*var_data;
	char	*vardol_name;

	end_pos = 0;
	buf_1 = NULL;
	buf_2 = NULL;
	var_data = NULL;
	vardol_name = NULL;
	end_pos = get_end_pos_vardol(str, *start_pos);
	vardol_name = ft_substr(str, *start_pos + 1, end_pos - *start_pos);
	buf_1 = ft_substr(str, 0, *start_pos);
	buf_2 = ft_substr(str, end_pos + 1, ft_strlen(str) - end_pos - 1);
	var_data = NULL;
	if (does_var_exist(vars->env, vardol_name))
		var_data = get_var(vars->env, vardol_name)->data;
	if (does_var_exist(vars->loc, vardol_name))
		var_data = get_var(vars->loc, vardol_name)->data;
	ft_free_null((void **)&str);
	if (var_data)
	{
		str = ft_strjoin(buf_1, var_data);
		ft_free_null((void **)&buf_1);
		buf_1 = str;
		*start_pos = *start_pos + ft_strlen(var_data) - 1;
	}
	else
		(*start_pos) = *start_pos - 1;
	str = ft_strjoin(buf_1, buf_2);
	ft_free_null((void **)&buf_1);
	ft_free_null((void **)&buf_2);
	ft_free_null((void **)&vardol_name);
	return (str);
}

/* ************************************************************************** */

static int	get_end_pos_vardol(char *str, int start_pos)
{
	int	i;

	i = start_pos;
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
static bool	is_vardol(char *str, int i)
{
	if (str[i] == '$' && is_char_for_dolvar_name(str[i + 1]))
		return (true);
	return (false);
}

/* ************************************************************************** */