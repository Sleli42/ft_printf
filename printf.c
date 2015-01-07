/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:13:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/07 06:50:25 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *rfmt, ...)
{
	va_list	arg;
	int		i;
	int		len;
	char	*cpy;
	t_infos	new;

	i = 0;
	cpy = ft_strdup(rfmt);
	va_start(arg, rfmt);
	while (cpy[i])
	{
		if (cpy[i] == '%')
		{
			detect_infos(cpy, i, &new);
			define_convert(&new, arg);
			while (cpy[i] != new.type)
				i++;
		}
		else
			ft_putchar(cpy[i]);
		i++;
	}
	va_end(arg);
}

int		main(void)
{
	int		i;

	i = 32790;
	printf("[printf]test:\t |%+.13hd|\n", i);
	ft_printf("[ft_printf]test: |%+.13hd|\n", i);
	return (0);
}
