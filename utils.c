/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 21:00:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/28 05:26:06 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		hexaValue(int n)
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

char	*baseHexa(unsigned long int n)
{
	char			*ret;
	int				i;
	unsigned long int		tmp;

	tmp = n;
	i = 0;
	while (tmp > 16)
	{
		tmp = tmp / 16;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (ret)
	{
		ret[i + 1] = '\0';
		while (i >= 0)
		{
			tmp = n % 16;
			ret[i] = hexaValue(tmp);
			n = n / 16;
			i--;
		}
	}
	return (ret);
}

char	*add0xAddr(char *s)
{
	char	*ret;
	char	*tmp;
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
