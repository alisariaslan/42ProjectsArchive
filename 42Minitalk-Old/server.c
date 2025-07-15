/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:47:23 by ali               #+#    #+#             */
/*   Updated: 2023/02/25 20:42:14 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_str(char *str, int newline)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	if (newline)
		write(1, "\n", 1);
}

static void	print_pid(int pid)
{
	char	*new;
	int		temp;
	int		step;

	temp = pid;
	step = 0;
	while (temp)
	{
		temp /= 10;
		step++;
	}
	new = (char *)malloc(sizeof(char) * step + 1);
	new[step] = 0;
	while (--step >= 0)
	{
		new[step] = (pid % 10) + 48;
		pid /= 10;
	}
	print_str("PID:", 0);
	print_str(new, 1);
	free(new);
}

static void	signal_receiver(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static unsigned int		i;

	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	else if (signal == SIGUSR2)
		c = (c << 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = signal_receiver;
	s_sigaction.sa_flags = SA_SIGINFO;
	print_pid(getpid());
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
}

/*
kill(info->si_pid,SIGUSR1);
*/
