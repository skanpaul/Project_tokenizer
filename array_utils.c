/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:59:35 by ski               #+#    #+#             */
/*   Updated: 2022/05/15 17:26:07 by sorakann         ###   ########.fr       */
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
void print_array_in_line(char **array, char *comment)
{
	int i;

	i = 0;
	if (array[i] != NULL)
		ft_printf("%s", comment);
	
	while (array[i] != NULL)
	{
		ft_printf("%d:[%s] ", i, array[i]);
		i++;
	}
	ft_printf("\n");
}

/* ************************************************************************** */
void free_array(char ***array)
{
	int i;

	if (*array == NULL)
		return ;

	i = 0;
	while ((*array)[i] != NULL)
	{
		free((*array)[i]);
		i++;
	}

	if ((*array))
		free((*array));
	(*array) = NULL;
}

/* ************************************************************************** */