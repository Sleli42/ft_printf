/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:13:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/03 06:05:12 by lubaujar         ###   ########.fr       */
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
		}
		i++;
	}
	va_end(arg);
}

int		main(void)
{
	int		i;

	i = 4242;
	ft_printf("la string: |%+d)|", i);
	return (0);
}
