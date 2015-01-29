/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:52:30 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/29 03:37:23 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

char	*search_flag(char *s, int c)
{
	char	*flags;
	int		i;

	i = 0;
	flags = (char *)malloc(sizeof(char) * 2);
	while (s[c])
	{
		if (is_flag(s[c]) == 1)
		{
			flags[i++] = s[c++];
			if (is_flag(s[c]) == 1)
				flags[i++] = s[c++];
		}
		c++;
	}
	flags[i] = '\0';
	return (flags);
}

int		search_width(char *s, int c)
{
	int		width;
	int		i;
	char	*wdt;

	width = 0;
	i = 0;
	wdt = (char *)malloc(sizeof(char) + 1);
	while (s[c] && s[c] != '.')
	{
		if (s[c] >= '0' && s[c] <= '9')
			wdt[i++] = s[c];
		c++;
	}
	wdt[i] = '\0';
	if (wdt)
	{
		width = ft_atoi(wdt);
		return (width);
	}
	return (0);
}

int		search_prec(char *s, int c)
{
	int 	prec;
	int		i;
	char	*pr;

	i = 0;
	pr = (char *)malloc(sizeof(char) + 1);
	while (s[c] != '.')
		c++;
	while (s[c])
	{
		if (s[c] >= '0' && s[c] <= '9')
			pr[i++] = s[c];
		c++;
	}
	pr[i] = '\0';
	if (pr)
	{
		prec = ft_atoi(pr);
		return (prec);
	}
	return (0);
}

char	*search_modif(char *s, int c)
{
	char	*modif;
	int		i;

	modif = (char *)malloc(sizeof(char) + 1);
	i = 0;
	while (s[c])
	{
		if (is_modif(s[c]) == 1)
		{
			modif[i++] = s[c++];
			if (is_modif(s[c]) == 1)
				modif[i++] = s[c];
		}
		c++;
	}
	modif[i] = '\0';
	return (modif);
}

char	search_conv(char *s, int c)
{
	while (s[c])
	{
		if (is_conv(s[c]) == 1 && s[c - 1] == '%')
			return (s[c]);
		c++;
	}
	return ('\0');
}
