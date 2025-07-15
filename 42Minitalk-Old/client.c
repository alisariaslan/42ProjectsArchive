/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <ali@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:47:27 by ali               #+#    #+#             */
/*   Updated: 2023/02/25 20:42:27 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_num(char *str)
{
	if (*str)
	{
		while (*str)
		{
			if (*str >= '0' && *str <= '9')
				str++;
			else
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

static int	uatoi(char *str)
{
	int	i;
	int	total;
	int	step;

	i = 0;
	total = 0;
	step = 1;
	while (str[i])
		i++;
	while (i > 0)
	{
		total += (str[i - 1] - 48) * (step);
		step *= 10;
		i--;
	}
	return (total);
}

static void	bit_sender(char *str, int pid)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i--) & 1)
			{
				if (PRINT_BITS)
					write(1, "1", 1);
				kill(pid, SIGUSR1);
			}
			else
			{
				if (PRINT_BITS)
					write(1, "0", 1);
				kill(pid, SIGUSR2);
			}
			usleep(TRANSFER_SPEED);
		}
		if (PRINT_BITS)
			write(1, " ", 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	if (!is_num(argv[1]))
		return (0);
	bit_sender(argv[2], uatoi(argv[1]));
	if (PRINT_BITS)
		write(1, "\n", 1);
}
