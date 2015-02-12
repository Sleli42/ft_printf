/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 00:58:29 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/12 14:17:52 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*addPrecString(char *s, int prec)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + prec) + 1);
	if (prec == -1)
		while ((size_t)i < ft_strlen(s))
			ret[i++] = ' ';
	else if (ft_strlen(s) < (size_t)prec)
		while (*s)
			ret[i++] = *s++;
	else if ((size_t)prec < ft_strlen(s))
		while (i < prec)
			ret[i++] = *s++;
	else
	{
		while ((size_t)i < (prec - ft_strlen(s)))
			ret[i++] = '0';
		while (*s)
			ret[i++] = *s++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*addPrec(char *s, int prec)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * prec + 1);
	i = 0;
	if (s[0] == '-')
	{
		ret[i++] = '-';
		while ((size_t)i <= (prec - ft_strlen(s) + 1))
			ret[i++] = '0';
		//(*s)++;
		while (*s++)
			ret[i++] = *s;
	}
	else
	{
		while ((size_t)i < (prec - ft_strlen(s)))
			ret[i++] = '0';
		while (*s)
			ret[i++] = *s++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*addWidth(char *s, int width, char *flag)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * width + 1);
	i = 0;
	j = 0;
	if (flag[0] == '-' || flag[1] == '-')
	{
		while (*s)
			ret[i++] = *s++;
		while (i < width)
			ret[i++] = ' ';
	}
	else
	{
		if (flag[0] == '0' && s[0] != '0')
		{
			if (s[j] == '-')
			{
				j = j + 1;
				ret[i++] = '-';
				while ((size_t)i <= width - ft_strlen(s))
					ret[i++] = '0';
			}
			else
			{
				while ((size_t)i < width - ft_strlen(s))
					ret[i++] = '0';
			}
		}
		else
		{
			while ((size_t)i < width - ft_strlen(s))
				ret[i++] = ' ';
		}
		while (s[j])
			ret[i++] = s[j++];
	}
	ret[i] = '\0';
	return (ret);
}

char	*addWidth0x(char *s, int width, char *flag)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * width + 1);
	i = 0;
	if (flag[0] == '0' || flag[0] == '-')
	{
		while (*s)
			ret[i++] = *s++;
		while (i < width)
		{
			if (flag[0] == '-')
				ret[i++] = ' ';
			else
				ret[i++] = '0';
		}
	}
	else
	{
		while ((size_t)i < width - ft_strlen(s))
			ret[i++] = ' ';
		while (*s)
			ret[i++] = *s++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*addSharpOctal(char *s)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 2);
	i = 0;
	ret[i++] = '0';
	while (*s)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);

}
