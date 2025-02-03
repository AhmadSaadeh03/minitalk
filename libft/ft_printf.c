/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadeh <asaadeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:05:54 by asaadeh           #+#    #+#             */
/*   Updated: 2025/01/16 16:26:30 by asaadeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *c, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, c);
	while (c[i])
	{
		if (c[i] == '%')
		{
			i++;
			if (c[i])
				count += check(c[i], args);
		}
		else
			count += write(1, &c[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
// int     main()
//  {
//         ft_printf("%p",(void *)0);
// 	ft_printf("%s",NULL);	   

//  }