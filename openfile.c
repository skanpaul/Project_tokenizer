/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:56:48 by gudias            #+#    #+#             */
/*   Updated: 2022/05/10 10:19:41 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
int	openfile(char *filepath, int o_flag)
{
	int	fd;

	fd = -1;
	if (o_flag == 0)
		fd = open(filepath, O_RDONLY);
	else if (o_flag == 1)
		fd = open(filepath, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (o_flag == 2)
		fd = open(filepath, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		return (0);
	return (fd);
}

/* ************************************************************************** */