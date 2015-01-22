/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 00:21:34 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/22 16:42:24 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_precision_addr(char *ret, int precision)
{
	int 	i;
	int 	j;
	char *cpy;

	i = ft_strlen(ret) + precision; 
	cpy = ft_strnew(i);
	i = 2;
	j = 2;
	cpy[0] = ret[0];
	cpy[1] = ret[1];
	while (i < ((precision - ft_strlen(ret)) + 4))
		cpy[i++] = '0';
	while (ret[j])   
		cpy[i++] = ret[j++];
	cpy[i] = '\0';
	return (cpy);
}

char	*add_width_addr(char *ret, int width)
{
	int i;
	int c;
	char *cpy;

	c = width - ft_strlen(ret);
	cpy = ft_strnew(width + ft_strlen(ret));
	i = 0;
	while (i < c && c > 0)
		cpy[i++] = ' ';
	while(*ret)
		cpy[i++] = *ret++;
	cpy[i] == '\0';
	return (cpy);
}

char	*binary_convert(unsigned int value)
{
	char	*ret;
	int		i;
	unsigned int	tmp;

	tmp = value;
	i = 0;
	while (tmp > 2)
	{
		tmp = tmp / 2;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (ret)
	{
		ret[i + 1] = '\0';
		while (i >= 0)
		{
			tmp = value % 2;
			ret[i] = 48 + tmp;
			value = value / 2;
			i--;
		}
	}
	return (ret);
}

void	cmp_msk(char *wchar_bin)
{
	char	*tab[4];
	char	*rev;
	char	*cpy;
	int		i;
	int		j;

	tab[0] = "0xxxxxxx";
	tab[1] = "110xxxxx10xxxxxx";
	tab[2] = "1110xxxx10xxxxxx10xxxxxx";
	tab[3] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	i = 0;
	j = 0;
	if (ft_strlen(wchar_bin) > 8 && ft_strlen(wchar_bin) <= 16)
	{
		if (wchar_bin)
		{
			while (wchar_bin[i])
			{
				printf("wchar_bin c : %c\n", wchar_bin[i]);
				i++;
			}
			cpy = tab[1];
			rev = (char *)malloc(sizeof(char) * ft_strlen(cpy) + 1);
			printf("wchar_bin: %s\n", wchar_bin);
			printf("cpy: %s\n", cpy);
			while (*cpy)
			{
				if (*cpy != 'x')
					rev[j++] = *cpy;
				if (*cpy == 'x')
				{
					printf("wchar_bin c : %c\n", wchar_bin[i]);
					rev[j++] = wchar_bin[i];
					i--;
				}
				printf("|%c|\t", *cpy);
				printf("|%c|\n", *wchar_bin);
				cpy++;
				wchar_bin++;
			}
		}
		printf("rev: %s\n", rev);
	//	printf("i = %d\n", i);
	//	printf("tab[1]: %s\n", tab[1]);
	}
}

