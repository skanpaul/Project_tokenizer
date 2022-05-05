/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:00:42 by ski               #+#    #+#             */
/*   Updated: 2022/05/05 08:13:56 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# include "libft.h"
# include "ft_printf.h"
/* ************************************************************************** */
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
typedef enum e_token_type
{
	cmd,
	file,
	chevron_in,
	chevron_out,
	pipeline, 
	arg	
} t_token_type;

/* ************************************************************************** */
typedef struct s_quote_info
{
	int		cnt_char_realquote;
	char	last_char_realquote;
	bool	flag_inside_realquote;
	bool	flag_entering_realquote;
	bool	flag_exiting_realquote;
	
}	t_quote_info;

/* ************************************************************************** */
typedef struct s_data
{
	int a;	
}	t_data;
/* ************************************************************************** */
char	**split_shell_line(char *line, char separator);
int		count_words(char *line, char separator);


bool 	is_line_with_correct_quote(char *line);
// ----------------------------------------------
void	init_quote_info(t_quote_info *qti);
void	refresh_quote_info(t_quote_info *qti, char actual_char);
bool	is_inside_real_quote(t_quote_info *qti);
bool	is_outside_real_quote(t_quote_info *qti);
bool	is_good_number_of_real_quote(t_quote_info *qti);
bool	is_input_char_real_quote(t_quote_info *qti);
bool	is_output_char_real_quote(t_quote_info *qti);
// ----------------------------------------------

char *chevron_space_maker(char *line);
char *pipeline_space_maker(char *line);
// ----------------------------------------------
char **tokenizer(char *line);
void free_array(char **array);
void print_array(char **array);
// ----------------------------------------------

/* ************************************************************************** */
#endif