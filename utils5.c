/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 14:12:17 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/12 17:48:03 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		printWchar(int value)
{
	char	*bin;
	int		ret;

	ret = 0;	
	bin = baseBinary(value);
	if ((int)ft_strlen(bin) <= 7)
	{
		write(1, &value, 1);
		ret++;
	}
	else
		ret = maskUnicode(bin, ft_strlen(bin));
	return (ret);
}

int		noConv(char *s, t_infos *infos)
{
	int		ret;
	//printf("flag: |%c|\n", infos->flag[0]);
	//printf("width: |%d|\n", infos->width);
	//printf("prec: |%d|\n", infos->prec);
	//printf("conv: |%c|\n", infos->conv);
	//printf("%s\n", s);
	ret = 0;
	infos = infos;
	while (*s++)
	{
		if (*s == '\0')
			return (0);
		if (ft_isalpha(*s) == 0)
			ret++;
		else
			break ;
	}
//	printf("ret: |%d|\n", ret);
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
