/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:23 by asaadeh           #+#    #+#             */
/*   Updated: 2025/02/08 15:53:47 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_signal = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_signal = 1;
}

static void	send_char(pid_t pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		g_signal = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_signal)
			usleep(300);
	}
}

static int	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <Message>\n", 32);
		return (1);
	}
	if (!check_pid(argv[1]))
	{
		write(2, "Error: Invalid PID\n", 19);
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ack_handler);
	while (argv[2][i])
		send_char(server_pid, argv[2][i++]);
	send_char(server_pid, '\0');
	return (0);
}
