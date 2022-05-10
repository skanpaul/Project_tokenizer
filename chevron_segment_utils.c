/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevron_segment_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:12:10 by ski               #+#    #+#             */
/*   Updated: 2022/05/10 22:09:45 by sorakann         ###   ########.fr       */
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
// RETURN -1: not possible to open a file
// RETURN  0: no file has to be open
// RETURN >2: a file was open
// NEED to close file ONLY if fd > 2
int	get_segment_fd_out(char **array)
{
	int	i;
	int	fd_out;

	fd_out = 0;
	i = 0;
	while (array[i])
	{
		if (does_word_match(array[i], ">") || does_word_match(array[i], ">>"))
		{
			// PEUT ETRE A EFFACER -----------------------------------------
			if(array[i + 1] == NULL  || array[i + 1][0] == '\0')
			{
				ft_printf("syntax error near unexpected token `newline'\n");
				fd_out = -1;
				break ;
			}
			// -------------------------------------------------------------
			
			if (fd_out != 0)
				close(fd_out);
			if (does_word_match(array[i], ">"))
				fd_out = openfilex(array[i + 1], 1);
			else
				fd_out = openfilex(array[i + 1], 2);
			if (fd_out < 0)
			{
				perror(array[i + 1]);
				break ;
			}
		}
		i++;
	}
	return (fd_out);
}

/* ************************************************************************** */
// RETURN -1: not possible to open a file
// RETURN  0: no file has to be open
// RETURN >2: a file was open
// NEED to close file ONLY if fd > 2
int	get_segment_fd_in(char **array)
{
	int	i;
	int	fd_in;

	fd_in = 0;
	i = 0;
	while (array[i])
	{
		if (does_word_match(array[i], "<") || does_word_match(array[i], "<<"))
		{
			// PEUT ETRE A EFFACER -----------------------------------------
			if(array[i + 1] == NULL  || array[i + 1][0] == '\0')
			{
				ft_printf("syntax error near unexpected token `newline'\n");
				fd_in = -1;
				break ;
			}
			// -------------------------------------------------------------
			
			if (fd_in != 0)
				close(fd_in);
			if (does_word_match(array[i], "<"))
				fd_in = openfilex(array[i + 1], 0);
			else
			{
				fd_in = 56;
				ft_printf("BESOIN: heredoc [ << ] with end [ %s ]\n", array[i + 1]);
			}
			if (fd_in < 0)
			{
				perror(array[i + 1]);
				break ;
			}
		}
		i++;
	}
	return (fd_in);
}

/* ************************************************************************** */
