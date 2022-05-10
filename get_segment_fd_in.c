/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment_fd_in.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:12:10 by ski               #+#    #+#             */
/*   Updated: 2022/05/10 11:55:57 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
#define OF_READ		0
#define OF_WRITE	1
#define OF_APPEND	2

/* ************************************************************************** */
int get_segment_fd_in(char **array)
{
	int	i;
	int fd_in;

	fd_in = 0;
	i = 0;
	while (array[i])
	{
		if (does_word_match(array[i], "<") || does_word_match(array[i], "<<"))
		{
			if(fd_in != 0)
				close(fd_in);
			if (does_word_match(array[i], "<"))
				fd_in = open(array[i + 1], O_RDONLY);
			else
			{
				fd_in = 56; //valeur fictive
				ft_printf("heredoc [ << ] with end [ %s ]\n", array[i +1]);
			}
			if (fd_in < 0)
			{
				perror(array[i + 1]);
				break;
			}
		}		
		i++;
	}
	return (fd_in);
}

/* ************************************************************************** */
