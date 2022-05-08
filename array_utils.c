/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:59:35 by ski               #+#    #+#             */
/*   Updated: 2022/05/08 11:55:40 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
void print_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putstr_fd(array[i], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
}

/* ************************************************************************** */
void print_array_in_line(char **array)
{
	int i;

	i = 0;
	if (array[i] != NULL)
	{
		ft_printf("\n");
		ft_printf("ARRAY:\t\t\t ");
	}
	
	while (array[i] != NULL)
	{
		ft_printf("%d:[%s] ", i, array[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("\n");
	
}

/* ************************************************************************** */
void free_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}

	if (array)
		free(array);
	array = NULL;
}

/* ************************************************************************** */