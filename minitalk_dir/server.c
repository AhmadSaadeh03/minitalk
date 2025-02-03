/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:39:32 by asaadeh           #+#    #+#             */
/*   Updated: 2025/02/03 21:43:51 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

// #define MAX_MESSAGE_LENGTH 1024  // Set an upper limit for the message length

// unsigned char received_char = 0;  // To store the received character
// int bit_count = 0;  // To track the number of bits received for the current character
// unsigned char message[MAX_MESSAGE_LENGTH];  // Array to hold the received message
// int message_index = 0;  // Index to track where we are in the message

// // Signal handler
// void handle_signal(int sig)
// {
//     if (sig == SIGUSR1) 
//     {
//         // If SIGUSR1 (bit 1), set the appropriate bit in received_char
//         received_char |= (1 << (7 - bit_count));
//     }
//     // Increment the bit counter
//     bit_count++;

//     // Once 8 bits are received, we have a complete character
//     if (bit_count == 8)
//     {
//         // Store the received character in the message array
//         message[message_index] = received_char;
//         message_index++;

//         // Check if the message is complete (null-terminated string) or if we hit the max length
//         if (received_char == '\0' || message_index >= MAX_MESSAGE_LENGTH)
//         {
//             // Null-terminate the message for safety
//             message[message_index] = '\0';
//            // write(1, "Received Message: ", 18);
//             write(1, message, message_index);  // Print the complete message
//            // write(1, "\n", 1);

//             // Reset for the next message
//             message_index = 0;  // Reset the index, don't clear the message array

//         }

//         // Reset for the next character
//         received_char = 0;
//         bit_count = 0;
//     }
// }

// int main(void)
// {
//     // Set up the signal handler for SIGUSR1 and SIGUSR2
//     if (signal(SIGUSR1, handle_signal) == SIG_ERR)
//     {
//         write(2, "Error registering SIGUSR1 handler\n", 34);
//         return 1;
//     }

//     if (signal(SIGUSR2, handle_signal) == SIG_ERR)
//     {
//         write(2, "Error registering SIGUSR2 handler\n", 34);
//         return 1;
//     }

//     // Print server PID to allow the client to send signals
//     printf("Server PID: %d\n", getpid());

//     // Keep the program running to listen for signals
//     while (1)
//     {
//         pause();  // Wait for signals to be received and handled
//     }

//     return 0;
// }
/////////////////////////////////////////////////
// void	ft_handler(int signal)
// {
// 	static int	bit;
// 	static int	i;

// 	if (signal == SIGUSR1)
// 		i |= (0x01 << bit);
// 	bit++;
// 	if (bit == 8)
// 	{
// 		ft_printf("%c", i);
// 		bit = 0;
// 		i = 0;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	pid;

// 	(void)argv;
// 	if (argc != 1)
// 	{
// 		ft_printf("\033[91mError: wrong format.\033[0m\n");
// 		ft_printf("\033[33mTry: ./server\033[0m\n");
// 		return (0);
// 	}
// 	pid = getpid();
// 	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
// 	ft_printf("\033[90mWaiting for a message...\033[0m\n");
// 	while (argc == 1)
// 	{
// 		signal(SIGUSR1, ft_handler);
// 		signal(SIGUSR2, ft_handler);
// 		pause ();
// 	}
// 	return (0);
// }
////////////////////////////////////////////////////
