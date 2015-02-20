/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:55:52 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/04 09:12:18 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
