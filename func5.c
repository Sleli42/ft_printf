/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 00:21:34 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/23 16:30:37 by lubaujar         ###   ########.fr       */
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
/*
void	cmp_msk(char *wchar_bin)
{
	char	*tab[4];
	char	*rev;
	char	*mask;
	char	*tmp;
	char	*tmp2;
	int		i;
	int		j;
	int		ct;

	tab[0] = "0xxxxxxx";
	tab[1] = "110xxxxx10xxxxxx";
	tab[2] = "1110xxxx10xxxxxx10xxxxxx";
	tab[3] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	printf("mask: %d\n", ft_strlen(mask));
	printf("wchar: %d\n", ft_strlen(wchar_bin));
	tmp2 = ft_strrev(wchar_bin);
	printf("%s\n", tmp2);
	if (ft_strlen(wchar_bin) > 11 && ft_strlen(wchar_bin) <= 16)
	{
		mask = (char *)malloc(sizeof(char) * ft_strlen(tab[1]));
		mask = tab[2];
		if (mask)
		{
			rev = (char *)malloc(sizeof(char) * ft_strlen(mask));
			printf("mask: %s\n", mask);
			printf("wchar_bin: %s\n", wchar_bin);
			i = ft_strlen(wchar_bin) - 1;
			j = ft_strlen(mask) - 1;
			ct = j;
			//printf("len mask: %d\n", j);
			printf("char wchar: %c\n", wchar_bin[i]);
			printf("char mask: %c\n", mask[j]);
			while (i >= 0)
			{
				if (mask[j] == 'x')
				{
					printf("wc[i]: %c\n", wchar_bin[i]);
					rev[ct] = wchar_bin[i--];
				}
				if (mask[j] == '1' || mask[j] == '0')
				{
					rev[ct] = mask[j];
				}
				j--;
				ct--;
			//	printf("char wchar: %c\n", wchar_bin[i]);
			//	printf("char mask: %c\n", mask[j]);
			//	printf("char rev: %c\n", rev[j]);
			}
			if (ct > 0)
			{
				while (ct > 0)	
					rev[ct--] = mask[j--];
			}
			printf("value ct: %d\n", ct);
			printf("value j: %d\n", j);
			printf("len rev: %d\n", ft_strlen(rev));
			printf("len mask: %d\n", ft_strlen(mask));
			printf("rev[tab]: %s\n", rev);
			if (rev)
			{
				i = 0;
				j = 0;
				printf("Yolo\n");
				printf("len[rev]: %d\n", ft_strlen(rev));
				while (rev[i] < 8)
				{
					tmp[j++] = rev[i++];
				}
				j = 0;
				while (rev[i] < 16)
				{
					tmp2[j++] = rev[i++];
				}
			}
			write(1, &tmp, 8);
			write(1, &tmp2, 8);
			//printf("wrte[1]: %s\n", write[1]);
		}
	}
}
*/
