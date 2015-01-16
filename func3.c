/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 09:54:14 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/16 13:09:51 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_precision_string(char *s, int precision)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * precision);
	i = 0;
	if (precision > ft_strlen(s))
		return (s);
	if (precision < ft_strlen(s))
	{
		while (*s)
		{
			if (i < precision)
				ret[i++] = *s;
			*s++;
		}
		return (ret);
	}
	return (NULL);
}

char	*add_width_string(char *s, int width, char *flag)
{
	char	*ret;
	int		i;

	ret = ft_strnew(width);
	i = 0;
	//printf("flag: %s\n", flag);
	if (width < ft_strlen(s) || width == ft_strlen(s))
		return (s);
	if (flag[0] == '-')
	{
		while (*s)
			ret[i++] = *s++;
		while (i < width)
			ret[i++] = ' ';
		return (ret);
	}
	if (width > ft_strlen(s))
	{
			while (i < width - ft_strlen(s))
			{
				if (flag[0] != '0')
					ret[i++] = ' ';
				else 
					ret[i++] = '0';
			}
		while (*s)
			ret[i++] = *s++;
		return (ret);
	}
	return (NULL);
}
