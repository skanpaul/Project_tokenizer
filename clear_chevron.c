/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_chevron.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:44:03 by sorakann          #+#    #+#             */
/*   Updated: 2022/05/10 10:09:32 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
static void	delete_chevron_and_file(char **array, int *i);

/* ************************************************************************** */
void	clear_chevron(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (does_word_match(array[i], "<")
			|| does_word_match(array[i], "<<")
			|| does_word_match(array[i], ">")
			|| does_word_match(array[i], ">>"))
		{
			delete_chevron_and_file(array, &i);
		}
		i++;
	}
}

/* ************************************************************************** */
static void	delete_chevron_and_file(char **array, int *i)
{
	int		j;
	char	*ptr_chevron_str;
	char	*ptr_filename;

	ptr_chevron_str = NULL;
	ptr_filename = NULL;
	ptr_chevron_str = array[*i];
	ptr_filename = array[*i + 1];
	j = 0;
	while (array[*i + j + 2])
	{
		array[*i + j] = array[*i + j + 2];
		j++;
	}
	array[*i + j] = array[*i + j + 2];
	array[*i + j + 1] = NULL;
	ft_free_null((void **)&ptr_chevron_str);
	ft_free_null((void **)&ptr_filename);
	(*i)--;
}

/* ************************************************************************** */