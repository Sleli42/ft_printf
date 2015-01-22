/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 00:21:34 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/22 14:27:48 by lubaujar         ###   ########.fr       */
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

	tab[0] = "0xxxxxxx";
	tab[1] = "110xxxxx10xxxxxx";
	tab[2] = "1110xxxx10xxxxxx10xxxxxx";
	tab[3] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	printf("wchar*: %s\n", wchar_bin);
	rev = ft_strrev(wchar_bin);
	printf("len: %d\n", ft_strlen(wchar_bin));
	printf("cpy[rev]: %s\n", rev);
	if (ft_strlen(wchar_bin) <= 8)
		putwchar
	else if(ft_strlen(wchar_bin) <= 16)
	else if(ft_strlen(wchar_bin) <= 24)
	else if(ft_strlen(wchar_bin) <= 32)
}

