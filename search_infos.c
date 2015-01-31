/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:52:30 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/31 07:19:34 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*search_flag(char *s, int c)
{
	char	*flags;
	int		i;
	int		j;

	i = 0;
	j = 0;
	flags = (char *)malloc(sizeof(char) * 2);
	if (s[c + 1] == ' ' && s[c + 2] == ' ')
	{
		c = c + 1;
		while (s[c] == ' ')
			c++;
	}
	while (i < c)
		i++;
	while (s[i] && s[i + 1] != '%' && j < 1)
	{
		if (is_flag(s[i]))
		{
			if (s[i - 1] >= '0' && s[i - 1] <= '9')
				i++;
			flags[j] = s[i];
			if (is_flag(s[i + 1]))
				flags[++j] = s[i + 1];
			else
				flags[++j] == '\0';
		}
		i++;
	}
	flags[++j] = '\0';
	if (!is_flag(flags[0]))
		flags[0] = '\0';
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
	while (s[c] && (s[c] != '.'))
	{
		if (s[c] >= '0' && s[c] <= '9')
			wdt[i++] = s[c];
		if (s[c + 1] >= 'a' && s[c + 1] <= 'z')
			break;
		c++;
	}
	wdt[i] = '\0';
	if (wdt)
	{
		width = ft_atoi(wdt);
		return (width);
	}
	return (width);
}

int		search_prec(char *s, int c)
{
	int 	prec;
	int		i;
	char	*pr;

	i = 0;
	prec = 0;
	pr = (char *)malloc(sizeof(char) + 1);
	while (s[c] != '.' && s[c + 1] != '%')
		c++;
	if (s[c + 1] >= '0' && s[c + 1] <= '9')
	{
		c = c + 1;
		while (s[c] >= '0' && s[c] <= '9')
			pr[i++] = s[c++];
	}
	pr[i] = '\0';
	if (pr)
		prec = ft_atoi(pr);
	return (prec);
}

char	*search_modif(char *s, int c)
{
	char	*modif;
	int		j;

	modif = (char *)malloc(sizeof(char) + 1);
	j = 0;
	while (s[c] && s[c + 1] != '%')
	{
		if (is_modif(s[c]))
		{
			modif[j] = s[c];
			if (is_modif(s[c + 1]))
				modif[++j] = s[c + 1];
			else
				modif[++j] = '\0';
		}
		c++;
	}
	modif[++j] = '\0';
	if (!is_modif(modif[0]))
		modif[0] = '\0';
	return (modif);
}

char	search_conv(char *s, int c)
{
	while (s[c])
	{
		if (is_conv(s[c]))
			return (s[c]);
		if (s[c + 1] == ' ')
		{
			while (s[c + 1] == ' ')
				c++;
			if (is_conv(s[c + 1]))
				return (s[c]);
			else
				return ('B');
		}
		else if (s[c + 1] == '%' && !is_conv(s[c]))
			return ('B');
		c++;
	}
	return ('B');
}
