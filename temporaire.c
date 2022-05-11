/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporaire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:02:17 by ski               #+#    #+#             */
/*   Updated: 2022/05/11 17:00:49 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
void ft_free_null(void **ptr)
{
	if (*ptr != NULL)
		free(*ptr);
	*ptr = NULL;
}

/* ************************************************************************** */
bool does_word_match(char *str, char *hard_text)
{
	int res;

	res = ft_strncmp(str, hard_text, ft_strlen(hard_text) + 1);
	if (res == 0)
		return (true);
	return (false);	
}

/* ************************************************************************** */
bool does_wordstart_match(char *str, char *hard_text)
{
	int res;

	res = ft_strncmp(str, hard_text, ft_strlen(hard_text));
	if (res == 0)
		return (true);
	return (false);	
}

/* ************************************************************************** */
int	openfilex(char *filepath, int o_flag)
{
	int	fd;

	fd = -1;
	if (o_flag == 0)
		fd = open(filepath, O_RDONLY);
	else if (o_flag == 1)
		fd = open(filepath, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (o_flag == 2)
		fd = open(filepath, O_WRONLY | O_APPEND | O_CREAT, 0644);
	return (fd);
}

/* ************************************************************************** */