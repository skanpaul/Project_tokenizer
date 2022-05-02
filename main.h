/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:00:42 by ski               #+#    #+#             */
/*   Updated: 2022/05/02 22:41:08 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
/* ************************************************************************** */
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>
/* ************************************************************************** */
# define NO_ERROR		0
# define ERROR			1
/* ************************************************************************** */
# define FORK_CHILD		0
# define FORK_ERROR		-1
/* ************************************************************************** */
# define MSG_PROMPT				"prompt> "
/* ************************************************************************** */
# define MSG_MAIN_SIGINT		"parent receive SIGINT [ctrl-C]\n"
# define MSG_MAIN_SIGQUIT		"parent receive SIGQUIT [ctrl-\\]\n"
/* ************************************************************************** */
typedef struct s_data
{
	//--------------------------------
	struct sigaction sa_sigint_main;	// [ctrl-C]
	struct sigaction sa_sigquit_main;	// [ctrl-\]
	//--------------------------------
	
}	t_data;
/* ************************************************************************** */
bool	is_parent(pid_t fk_pid);
/* ************************************************************************** */
void	init_struc_sigaction(t_data *d);
// -------------------------------------------------
void	handler_signal_main(int sig_code);
// -------------------------------------------------
void	link_signal_main(t_data *d);

char **tokenizer(char *line);
void free_array(char **array);
void print_array(char **array);


/* ************************************************************************** */
#endif