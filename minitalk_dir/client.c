/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:23 by asaadeh           #+#    #+#             */
/*   Updated: 2025/02/03 21:43:58 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

// void send_signal(int pid, unsigned char character)
// {
//     int i;
//     // Loop through all 8 bits of the character
//     for (i = 7; i >= 0; i--) // Start from the highest bit (bit 7)
//     {
//         // Shift the character to the right to get the current bit
//         if ((character >> i) & 1)
//         {
//             // If the bit is 1, send SIGUSR1
//             kill(pid, SIGUSR1);
//         }
//         else
//         {
//             // If the bit is 0, send SIGUSR2
//             kill(pid, SIGUSR2);
//         }

//         // Wait for a short period to give the server time to process the signal
//         usleep(350);  // Sleep for 500 microseconds
//     }
// }

// int main(int argc, char **argv)
// {
//     if (argc != 3)
//     {
//         write(2, "Usage: ./client <server_pid> <message>\n", 40);
//         return 1;
//     }

//     // Get the server PID from the command line argument
//     int server_pid = ft_atoi(argv[1]);

//     // Get the message to send from the command line argument
//     char *message = argv[2];

//     // Send each character of the message to the server
//     while (*message)
//     {
//         send_signal(server_pid, (unsigned char)(*message));
//         message++;
//     }

//     // Send a signal to indicate the end of transmission (optional, based on your implementation)
//     send_signal(server_pid, '\0');

//     return 0;
// }
///////////////////////////////////////////////////////////////////
// void	ft_send_bits(int pid, char i)
// {
// 	int	bit;

// 	bit = 0;
// 	while (bit < 8)
// 	{
// 		if ((i & (0x01 << bit)) != 0)
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		usleep(500);
// 		bit++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	pid;
// 	int	i;

// 	i = 0;
// 	if (argc == 3)
// 	{
// 		pid = ft_atoi(argv[1]);
// 		while (argv[2][i] != '\0')
// 		{
// 			ft_send_bits(pid, argv[2][i]);
// 			i++;
// 		}
// 		ft_send_bits(pid, '\n');
// 	}
// 	else
// 	{
// 		ft_printf("\033[91mError: wrong format.\033[0m\n");
// 		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
// 		return (1);
// 	}
// 	return (0);
// }
///////////////////////////////////////////////
