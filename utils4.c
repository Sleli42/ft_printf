/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:06:46 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/07 16:40:12 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*baseBinary(int n)
{
	char			*ret;
	int				i;
	int				tmp;

	tmp = n;
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
			tmp = n % 2;
			ret[i] = 48 + tmp;
			n = n / 2;
			i--;
		}
	}
	return (ret);
}

int		baseDecimal(char *bin)
{
	int		tab[7];
	int		i;
	int		j;
	int		ret;
	
	i = 1;
	j = 0;
	tab[0] = 1;
	ret = 0;
	while (i < 8)
	{
		tab[i] = tab[i - 1] * 2;
		i++;
	}
	while (j < 8)
	{
		if (bin[j] == '1')
			ret += tab[i - 1];
		i--;
		j++;
	}
	return (ret);
}

void	maskUnicode(char *bin, int lenMask)
{
	char	*tab[3];
	char	**ret;
	char	*tmp;
	int		i;
	int		j;

	tab[0] = "0xxxxxxx"; 
	tab[1] = "110xxxxx10xxxxxx";
	tab[2] = "1110xxxx10xxxxxx10xxxxxx";
	tab[3] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	i = 0;
	j = lenMask - 1;

//	printf("bin: %s\n", bin);
//	printf("mask: %s\n", tab[1]);
	tmp = ft_strrev(tab[1]);
//	printf("tmp: %s\n", tmp);
	while (tmp[i] && bin[j])
	{
		if (tmp[i] == 'x')
			tmp[i] = bin[j--];
		i++;
	}
	tmp = ft_strrev(tmp);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == 'x')
			tmp[i] = '0';
		i++;
	}
	splitBinary(tmp);
}

void	splitBinary(char *bin)
{
	int		i;
	int		j;
	int		l;
	int		tmp[1];
	char	*ret[1];

	printf("bin: %s\n", bin);
	i = 0;
	j = 0;
	ret[0] = (char *)malloc(sizeof(char) * 8 + 1);
	while (i < 8)
	{
		ret[0][j] = bin[i];
		i++;
		j++;
	}
	ret[0][j] = '\0';
	l = 0;
	ret[1] = (char *)malloc(sizeof(char) * 8 + 1);
	while (i < 16)
	{
		ret[1][l] = bin[i];
		i++;
		l++;
	}
	ret[1][l] = '\0';
	printf("ret[0]: %s\n", ret[0]);
	printf("ret[1]: %s\n", ret[1]);
	tmp[0] = baseDecimal(ret[0]);
	tmp[1] = baseDecimal(ret[1]);
	printf("%d\n", tmp[0]);
	printf("%d\n", tmp[1]);
	write(1, &(tmp[0]), 1);		/* victoire */
	write(1, &(tmp[1]), 1);		/* victoire */
}
