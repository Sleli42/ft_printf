/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:47:10 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/25 03:20:08 by lubaujar         ###   ########.fr       */
/*   Updated: 2015/02/19 19:52:34 by lubaujar         ###   ########.fr       */
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
	{
		ret = maskUnicode(bin, ft_strlen(bin));
	}
//	printf("ret: %d\n", ret);
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
//	printf("bin: %s\n", bin);
	if (lenMask <= 7)
		tmp = ft_strrev(tab[0]);
	else if (lenMask > 7 && lenMask <= 11)
		tmp = ft_strrev(tab[1]);
	else if (lenMask > 11 && lenMask <= 16)
		tmp = ft_strrev(tab[2]);
	else
		tmp = ft_strrev(tab[3]);
//	printf("-> %s\n", tmp);
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
	{
		tmp[i] = baseDecimal(tab[i]);
		//printf("tmp[%d] : %d", i, *tab[i]);
	}
	i = 0;
	while (i <= nb)
	{
		write(1, &(tmp[i]), 1);
		i++;
	}
	return (i);
}
