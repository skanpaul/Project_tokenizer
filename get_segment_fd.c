/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:12:10 by ski               #+#    #+#             */
/*   Updated: 2022/05/10 16:49:47 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
#define OF_READ 0
#define OF_WRITE 1
#define OF_APPEND 2

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
			if (fd_out != 0)
				close(fd_out);
			if (does_word_match(array[i], ">"))
				fd_out = open(array[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
			else
				fd_out = open(array[i + 1], O_WRONLY | O_APPEND | O_CREAT, 0777);
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
			if (fd_in != 0)
				close(fd_in);
			if (does_word_match(array[i], "<"))
				fd_in = open(array[i + 1], O_RDONLY);
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
