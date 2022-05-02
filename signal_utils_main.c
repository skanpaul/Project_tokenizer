/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorakann <sorakann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:09:38 by sorakann          #+#    #+#             */
/*   Updated: 2022/04/18 23:11:50 by sorakann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* ************************************************************************** */
void init_struc_sigaction(t_data *d)
{	
	// main: SIGINT	
	d->sa_sigint_main.sa_handler = &handler_signal_main;	// SA_HANDLER	
	sigemptyset(&d->sa_sigint_main.sa_mask);				// SA_MASK
	sigaddset(&d->sa_sigint_main.sa_mask, SIGINT);			// -
	sigaddset(&d->sa_sigint_main.sa_mask, SIGQUIT);			// -	
	d->sa_sigint_main.sa_flags = SA_RESTART;				// SA_FLAG
	
	// main: SIGQUIT	
	d->sa_sigquit_main.sa_handler = &handler_signal_main;	// SA_HANDLER	
	sigemptyset(&d->sa_sigquit_main.sa_mask);				// SA_MASK
	sigaddset(&d->sa_sigquit_main.sa_mask, SIGINT);			// -
	sigaddset(&d->sa_sigquit_main.sa_mask, SIGQUIT);		// -	
	d->sa_sigquit_main.sa_flags = SA_RESTART;				// SA_FLAG
	
}

/* ************************************************************************** */
void	handler_signal_main(int sig_code)
{
	if (sig_code == SIGINT)
	{
		write(1, MSG_MAIN_SIGINT, strlen(MSG_MAIN_SIGINT));
	}
	
	if (sig_code == SIGQUIT)
	{
		write(1, MSG_MAIN_SIGQUIT, strlen(MSG_MAIN_SIGQUIT));	
	}
}

/* ************************************************************************** */
void link_signal_main(t_data *d)
{
	sigaction(SIGINT, &d->sa_sigint_main, NULL);		// [ctrl-C]: SIGINT
	sigaction(SIGQUIT, &d->sa_sigquit_main, NULL);	// [ctrl-\]: SIGQUIT
}

/* ************************************************************************** */