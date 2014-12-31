/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:13:40 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/31 04:10:36 by lubaujar         ###   ########.fr       */
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
	while (cpy[i])
	{
		if (cpy[i] == '%')
		{
			len = search_flag(cpy, i, &new);
			len = search_height(cpy, len, &new);
			len = search_precision(cpy, len, &new);
			search_modifier(cpy, i, &new);
		}
		i++;
	}
}

int		main(void)
{
	ft_printf("la string: |%-j1.40s|");
	return (0);
}
