/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_infos2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:54:38 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 04:24:30 by lubaujar         ###   ########.fr       */
/*   Updated: 2014/11/08 14:10:50 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		search_width(char *s, int c)
{
	int		width;
	int		i;
	char	*wdt;

	width = -1;
	i = 0;
	wdt = (char *)malloc(sizeof(char) + 1);
	while (s[c] && (s[c] != '.'))
	{
		if (s[c] >= '0' && s[c] <= '9')
			wdt[i++] = s[c];
		if (s[c + 1] >= 'a' && s[c + 1] <= 'z')
			break ;
		c++;
	}
	wdt[i] = '\0';
	if (*wdt != '\0')
		return (ft_atoi(wdt));
	return (width);
}

int		search_prec(char *s, int c)
{
	int		i;
	char	*pr;

	i = 0;
	pr = (char *)malloc(sizeof(char) + 1);
	while (s[c] && s[c] != '.')
		c++;
	if (s[c] == '.')
	{
		c++;
		if (s[c] == '0')
			return (-3);
		if (ft_isdigit(s[c]) == 0 || is_conv(s[c]) == 1)
			return (-2); /* invalid prec */
		while (ft_isdigit(s[c]) == 1)
			pr[i++] = s[c++];
		pr[i] = '\0';
	}
	else
		return (-1);	/* No prec */
	return (ft_atoi(pr));
}

char	*search_modif(char *s, int c, char conv)
{
	char	*modif;
	int		j;

	modif = (char *)malloc(sizeof(char) + 1);
	j = 0;
	while (s[c] && s[c] != conv)
	{
		if (is_modif(s[c]))
		{
			modif[j] = s[c];
			if (is_modif(s[c + 1]))
			{
				modif[++j] = s[c + 1];
				return (modif);
			}
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

char	*searchChar(char *s, int c)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char *));
	i = 0;
	while (s[c] && ft_isalpha(s[c]) == 0)
		c++;
	if (ft_isalpha(s[c]) == 1)
	{
		while (ft_isalpha(s[c]) == 1)
			ret[i++] = s[c++];
		return (ret);
	}
	return (NULL);
}
