/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:13:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/15 14:36:06 by lubaujar         ###   ########.fr       */
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
		//	affiche_detect(&new);
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
	char	*i;
	long long int		j;


	j = 42424;
	i = "42424";
	/*rintf("[printf]test:\t |% .17d|\n", i);
	ft_printf("[ft_printf]test: |% .17d|\n\n", i);
	printf("[printf]test:\t |% 10.10d|\n", i);
	ft_printf("[ft_printf]test: |% 10.10d|\n\n", i);
	printf("[printf]test:\t |%hd|\n", i);
	ft_printf("[ft_printf]test: |%hd|\n\n", i);
	printf("[printf]test:\t |%+hd|\n", i);
	ft_printf("[ft_printf]test: |%+hd|\n\n", i);
	printf("[printf]test:\t |%-10hd|\n", i);
	ft_printf("[ft_printf]test: |%-10hd|\n\n", i);
	printf("[printf]test:\t |%-10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%-10.12hd|\n\n", i);
	printf("[printf]test:\t |%0.42d|\n", i);
	ft_printf("[ft_printf]test: |%0.42d|\n\n", i);
	printf("[printf]test:\t |%+.10ld|\n", i);
	ft_printf("[ft_printf]test: |%+.10ld|\n\n", i);
	printf("[printf]test:\t |%-10ld|\n", i);
	ft_printf("[ft_printf]test: |%-10ld|\n\n", i);
	printf("[printf]test:\t |%010.7d|\n", i);
	ft_printf("[ft_printf]test: |%010.7d|\n\n", i);
	printf("[printf]test:\t |%0.12hd|\n", i);
	ft_printf("[ft_printf]test: |%0.12hd|\n\n", i);
	printf("[printf]test:\t |%+10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%+10.12hd|\n\n", i);
	printf("[printf]test:\t |%-4.8hd|\n", i);
	ft_printf("[ft_printf]test: |%-4.8hd|\n\n", i);
	printf("[printf]test:\t |%-10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%-10.12hd|\n\n", i);
	printf("[printf]test:\t |%-10d|\n", i);
	ft_printf("[ft_printf]test: |%-10d|\n\n", i);
	printf("[printf]test:\t |%-10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%-10.12hd|\n\n", i);*/
	printf("|%#10p|\n", i);
	printf("|%#20p|\n", i);
	printf("|%#15p|\n", i);
	printf("|%10.42p|\n", i);
	printf("|%10p|\n", i);
	printf("|%.12p|\n", i);
	return (0);
}
