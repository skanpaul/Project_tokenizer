/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:00:42 by ski               #+#    #+#             */
/*   Updated: 2022/05/16 18:44:41 by sorakann         ###   ########.fr       */
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
# include <fcntl.h>
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

// ----------------------------------------------
void	translate_dollars_all(char **array, t_vars *vars);
char	*translate_dollar(char *str, t_vars *vars);
bool	is_char_for_dolvar_name(char c);
bool	is_vardol(char *str, int i);
int		get_end_pos_vardol(char *str, int start_pos);
char	*substitute_vardol(char *str, int *start_pos, t_vars *vars);
char	*delete_char(char *str, int *i);

// ----------------------------------------------
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
void free_array(char ***array);
void print_array(char **array);
void print_array_in_line(char **array, char *comment);
// ----------------------------------------------

void ft_free_null(void **ptr);

bool	does_var_exist(t_env *var_head, char *var_name);

// -------------------------------------------------- linklist_utils.c
void	print_var(t_env *var_head);
t_env	*get_var(t_env *var_head, char *var_name);
bool	does_var_exist(t_env *var_head, char *var_name);
void	update_var(t_env **var_head, char *var_name, char *new_data);
void	add_var(t_env **var_head, char *name, char *data);
void	remove_var(t_env **var_head, char *var_name);
int		size_var_list(t_env *var_head);
void	free_var_list(t_env **var_head);
// -------------------------------------------------- 
bool	does_word_match(char *str, char *hard_text);
bool	does_wordstart_match(char *str, char *hard_text);

int		get_segment_fd_in(char **array);
int		get_segment_fd_out(char **array);

void	clear_chevron(char **array);


char	*check_grammar(char *line, t_vars *vars);
bool	is_grammar_correct(char *line, t_vars *vars);

char	*check_grammar_chevron(char *line, t_vars *vars);
bool	is_grammar_chevron_correct(char *line, t_vars *vars);

char	*check_grammar_pipeline(char *line, t_vars *vars);
bool	is_grammar_pipeline_correct(char *line, t_vars *vars);


int		openfilex(char *filepath, int o_flag);

/* ************************************************************************** */
#endif