/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 21:00:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/23 01:57:16 by lubaujar         ###   ########.fr       */
/*   Updated: 2015/02/20 08:16:26 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		hexaValue(int n)
{
	if (0 <= n && n <= 9)
		return (48 + n);
	else if (10 <= n && n <= 15)
	{
		n = n - 10;
		return (97 + n);
	}
	return (0);
}

int		hexaValueMaj(int n)
{
	if (0 <= n && n <= 9)
		return (48 + n);
	else if (10 <= n && n <= 15)
	{
		n = n - 10;
		return (65 + n);
	}
	return (0);
}

char	*add0xAddr(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(ft_strlen(s)) + 3);
	i = 2;
	ret[0] = '0';
	ret[1] = 'x';
	if (ft_strlen(s) < 12 && ft_strlen(s) >= 8)
	{
		if (s[0] != '7')
			ret[i++] = '1';
	}
	while (*s)
		ret[i++] = *s++;
	return (ret);
}

int		nextPercent(char *s, int c)
{
	c = c + 1;
	while (s[c] == ' ')
	{
		if (s[c + 1] == '%')
			return (1);
		c++;
	}
	return (0);
}
/*
int		defineLenString(char *s, int c, t_infos *infos)
{
	int		i;

	i = 0;
	if (infos->width > 0)
		while (c < c + (int)ft_strlen(ft_itoa(infos->width)))
			c++;
	if (infos->prec > 0)
		while (c < c + (int)ft_strlen(ft_itoa(infos->prec)))
			c++;
	if (ft_isalpha(s[c]) == 1)
	{
		while (ft_isalpha(s[c]) == 1 || s[c] == 32)
		{
			printf("s[c]: %c-", s[c]);
			i++;
		}
	}
	printf("i: %d\n", i);
	return (i);
}*/
