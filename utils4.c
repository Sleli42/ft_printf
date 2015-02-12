/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 13:06:46 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/12 13:50:02 by lubaujar         ###   ########.fr       */
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
	while (tmp >= 2)
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
	//printf("[binaryConv]%s\n", ret);
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

int		maskUnicode(char *bin, int lenMask)
{
	char	*tab[3];
	char	*tmp;
	int		i;
	int		j;
	int		ret;

	tab[0] = "0xxxxxxx"; 
	tab[1] = "110xxxxx10xxxxxx";
	tab[2] = "1110xxxx10xxxxxx10xxxxxx";
	tab[3] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	i = 0;
	j = lenMask - 1;
	if (lenMask <= 7)
		tmp = ft_strrev(tab[0]);
	else if (lenMask > 7 && lenMask <= 11)
		tmp = ft_strrev(tab[1]);
	else if (lenMask > 11 && lenMask <= 16)
		tmp = ft_strrev(tab[2]);
	else
		tmp = ft_strrev(tab[3]);
	while (tmp[i] && bin[j])
	{
		if (tmp[i] == 'x')
			tmp[i] = bin[j--];
		i++;
	}
	tmp = ft_strrev(tmp);
//	printf("bin: %s\n", bin);
//	printf("tmp: %s\n", tmp);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == 'x')
			tmp[i] = '0';
		i++;
	}
	ret = splitBinary(tmp, (ft_strlen(tmp) / 8));
	return (ret);
}

int		splitBinary(char *bin, int nbDiv)
{
	int		i;
	int		j;
	int		ct;
	int		div;
	char	*ret[8];

	i = 0;
	ct = 0;
	div = 8;
	while (ct < nbDiv)
	{
		j = 0;
		ret[ct] = (char *)malloc(sizeof(char) * 8 + 1);
		while (i < div)
			ret[ct][j++] = bin[i++];
		ret[ct][j] = '\0';
		ct++;
		div = div + 8;
	}
	return (displayWchar(ret, (ct - 1)));
}

int		displayWchar(char **tab, int nb)
{
	int	 	tmp[nb];
	int		i;

	i = -1;
	while (++i <= nb)
		tmp[i] = baseDecimal(tab[i]);
	i = 0;
	while (i <= nb)
	{
		write(1, &(tmp[i]), 1);
		i++;
	}
	return (i);
}
