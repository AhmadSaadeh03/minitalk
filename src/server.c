/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:32 by asaadeh           #+#    #+#             */
/*   Updated: 2025/02/08 15:52:28 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static char	*g_message = NULL;

static void	helper(void)
{
	ft_printf("%s\n", g_message);
	free(g_message);
	g_message = NULL;
}

static void	append_char(char c)
{
	char	*new_message;
	int		len;

	len = 0;
	if (g_message)
		len = ft_strlen(g_message);
	new_message = malloc(len + 2);
	if (!new_message)
		return ;
	if (g_message)
	{
		ft_memcpy(new_message, g_message, len);
		free(g_message);
	}
	new_message[len] = c;
	new_message[len + 1] = '\0';
	g_message = new_message;
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;

	(void)context;
	if (sig == SIGUSR1)
		c = (c << 1);
	else if (sig == SIGUSR2)
		c = (c << 1) | 1;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			if (g_message)
				helper();
			ft_printf("Acknowledgment (SIGUSR1) sent to client with PID: %d\n",
				info->si_pid);
		}
		else
			append_char(c);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf(" *  Server PID:%d    *\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
