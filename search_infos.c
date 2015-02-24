/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:52:30 by sksourou          #+#    #+#             */
/*   Updated: 2015/02/24 04:52:58 by lubaujar         ###   ########.fr       */
/*   Updated: 2015/02/13 16:16:21 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_help_flag(char *s, int i)
{
	char	*flag;
	int		j;

	j = 0;
	flag = (char *)malloc(sizeof(char) * 2);
	if (s[i - 1] >= '1' && s[i - 1] <= '9')
		i++;
	if (!is_flag(s[i]))
		return (flag);
	flag[j] = s[i];
	if (is_flag(s[i + 1]))
		flag[++j] = s[i + 1];
	else
		flag[++j] = '\0';
	return (flag);
}

char	skipSpaces(char *s, int c)
{
	c = c + 1;
	while (s[c] == ' ')
		c++;
	return (c);
}

char	*search_flag(char *s, int c)
{
	char	*flags;

	flags = (char *)malloc(sizeof(char) * 2);
	while (s[c] && s[c + 1] != '%')
	{
		//if (s[c + 1] == ' ' && s[c + 2] == ' ')
		//	c = skipSpaces(s, c);
		if (is_flag(s[c]) == 1)
		{
			flags = ft_help_flag(s, c);
			break ;
		}
		if (is_conv(s[c]) == 1 || s[c] == '.')
			break ;
		c++;
	}
	return (flags);
}

char	search_conv(char *s, int c)
{
	while (s[c])
	{
		if (is_conv(s[c + 1]))
			return (s[c + 1]);
		if (s[c + 1] == ' ')
		{
			while (s[c + 1] == ' ')
				c++;
			if (is_conv(s[c + 1]) == 1)
				return (s[c + 1]);
			else if ((s[c + 1] >= 'a' && s[c + 1] <= 'z')
					|| (s[c + 1] >= 'A' && s[c + 1] <= 'Z'
						&& is_conv(s[c + 1]) == 0))
				return ('B');
		}
		c++;
	}
	return ('B');
}
