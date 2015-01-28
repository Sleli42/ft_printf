/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:52:30 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/27 20:42:18 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

char	*search_flag(char *s)
{
	char	*flags;
	int		i;

	i = 0;
	flags = (char *)malloc(sizeof(char) * 2);
	while (*s)
	{
		if (is_flag(*s) == 1)
		{
			flags[i++] = *s++;
			if (is_flag(*s) == 1)
				flags[i++] = *s++;
		}
		*s++;
	}
	flags[i] = '\0';
	return (flags);
}

int		search_width(char *s)
{
	int		width;
	int		i;
	char	*wdt;

	width = 0;
	i = 0;
	wdt = (char *)malloc(sizeof(char) + 1);
	while (*s && *s != '.')
	{
		if (*s >= '0' && *s <= '9')
			wdt[i++] = *s;
		*s++;
	}
	wdt[i] = '\0';
	if (wdt)
	{
		width = ft_atoi(wdt);
		return (width);
	}
	return (0);
}

int		search_prec(char *s)
{
	int 	prec;
	int		i;
	char	*pr;

	i = 0;
	pr = (char *)malloc(sizeof(char) + 1);
	while (*s != '.')
		*s++;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			pr[i++] = *s;
		*s++;
	}
	pr[i] = '\0';
	if (pr)
	{
		prec = ft_atoi(pr);
		return (prec);
	}
	return (0);
}

char	*search_modif(char *s)
{
	char	*modif;
	int		i;

	modif = (char *)malloc(sizeof(char) + 1);
	i = 0;
	while (*s)
	{
		if (is_modif(*s) == 1)
		{
			modif[i++] = *s++;
			if (is_modif(*s) == 1)
				modif[i++] = *s;
		}
		*s++;
	}
	modif[i] = '\0';
	return (modif);
}

char	search_conv(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (is_conv(s[i]) == 1)
			return (s[i]);
		i++;
	}
	return ('\0');
}
