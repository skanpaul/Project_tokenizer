/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <ski@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:00:42 by ski               #+#    #+#             */
/*   Updated: 2022/05/06 11:40:30 by ski              ###   ########.fr       */
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

typedef struct s_quote_info
{
	int		cnt_char_realquote;
	char	last_char_realquote;
	bool	flag_inside_realquote;
	bool	flag_entering_realquote;
	bool	flag_exiting_realquote;
	
}	t_quote_info;
// ----------------------------------------

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;36m"
# define DEFAULT "\033[0m"
/* ************************************************************************** */

typedef struct s_sig
{
	struct sigaction	sa_sigint_main;
	struct sigaction	sa_sigquit_main;
	struct sigaction	sa_signal_prog;
} t_sig;
// ----------------------------------------
typedef struct	s_env
{
	char			*name;
	char			*data;
	struct s_env	*next;
}	t_env;
// ----------------------------------------
typedef struct	s_vars
{
	int		stdin_fd;
	int		stdout_fd;
	int		stderr_fd;
	t_env	*env;
	t_env	*loc;
	char	**env_char_array;
	t_sig	sig;
}	t_vars;

/* ************************************************************************** */
typedef struct s_data
{
	int a;	
}	t_data;
/* ************************************************************************** */
char	**split_shell_line(char *line, char separator);
int		count_words(char *line, char separator);
char	*translate_dollar(char *str, t_vars *vars);


bool 	is_line_with_correct_quote(char *line);
// ----------------------------------------------
void	init_quote_info(t_quote_info *qti);
void	refresh_quote_info(t_quote_info *qti, char actual_char);
bool	is_good_number_of_realquote(t_quote_info *qti);
bool	is_inside_realquote(t_quote_info *qti);
bool	is_outside_realquote(t_quote_info *qti);
bool	is_entering_realquote(t_quote_info *qti);
bool	is_exiting_realquote(t_quote_info *qti);
bool	is_inside_double_realquote(t_quote_info *qti);
bool	is_inside_single_realquote(t_quote_info *qti);

// ----------------------------------------------

char *chevron_space_maker(char *line);
char *pipeline_space_maker(char *line);
// ----------------------------------------------
char **tokenizer(char *line);
void free_array(char **array);
void print_array(char **array);
// ----------------------------------------------

bool	does_var_exist(t_env *var_head, char *var_name);

/* ************************************************************************** */
#endif