/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:23:11 by lubaujar          #+#    #+#             */
/*   Updated: 2014/12/31 04:10:39 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		search_flag(char *s, int caract, t_infos *lst)
{
	t_infos	*tmp;
	int		len;

	tmp = lst;
	if (is_flag(s[caract + 1]) == 1)	
	{	/* check just 1 flag */
		tmp->flag = s[caract + 1];
		len = caract + 1;
	}
	else if (is_flag(s[caract + 1]) == 0)
		len = caract;
	return (len);
}

int		search_height(char *s, int caract, t_infos *lst)
{
	int		i;
	int		width;
	char	*width_tmp;
	t_infos	*tmp;

	i = -1;
	width_tmp = (char *)malloc(sizeof(char));
	tmp = lst;
	if (s[caract + 1] >= '0' && s[caract + 1] <= '9')
	{
		while (s[caract + 1] >= '0' && s[caract + 1] <= '9')
		{
			width_tmp[++i] = s[caract + 1];
			caract++;
		}
	}
	else
		return (caract);
	width_tmp[++i] = '\0';
	width = ft_atoi(width_tmp);
	tmp->width = width;
	free(width_tmp);
	return (caract);
}

int		search_precision(char *s, int caract, t_infos *lst)
{
	int 	i;
	int 	precision;
	char	*prec_tmp;
	t_infos *tmp;

	i = -1;
	prec_tmp = (char *)malloc(sizeof(char));
	tmp = lst;
	if (s[caract + 1] != '.')
		return (caract);
	else if (s[caract + 1] == '.')
	{
		caract++;
		while (s[caract + 1] >= '0' && s[caract + 1] <= '9')
		{
			prec_tmp[++i] = s[caract + 1];
			caract++;
		}
	}
	prec_tmp[++i] = '\0';
	precision = ft_atoi(prec_tmp);
	tmp->precision = precision;
	free(prec_tmp);
	return (caract);
}

void	search_modifier(char *s, int caract, t_infos *lst)
{
	int		i;
	t_infos	*tmp;

	i = 0;
	tmp = lst;
	printf("string entry: %s\n", s);
	printf("caract entry: %c\n", s[caract]);
	while (s[caract])
	{
		if (is_modifier(s[caract]) == 1)
			tmp->modifier = s[caract];
		caract++;
	}
	printf("modifier: %c\n", tmp->modifier);
}
