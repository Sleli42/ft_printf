/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_infos2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:54:38 by lubaujar          #+#    #+#             */
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
	int 	prec;
	int		i;
	char	*pr;

	i = 0;
	prec = -1;
	pr = (char *)malloc(sizeof(char) + 1);
	if (is_conv(s[c + 1]) == 1 || ft_isalpha(s[c + 1]) == 1)
		return (-1);
	while (s[c] != '.')
	{
		if (s[c] == '\0' || s[c] == '%')
			return (-1);
		else if (s[c] == '.' && s[c + 1] == '0')
			return (-1);
		else
		{
			while (ft_isdigit(s[c + 1] == 1))
				pr[i++] = s[c++];
		}
		c++;
	}
	pr[i] = '\0';
	if (pr)
		prec = ft_atoi(pr);
	return (prec);
}

char	*search_modif(char *s, int c, char conv)
{
	char	*modif;
	int		j;

	modif = (char *)malloc(sizeof(char) + 1);
	j = 0;
	while (s[c] && s[c + 1] != '%' && s[c + 1] != conv)
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
