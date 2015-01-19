/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:23:11 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/19 13:03:47 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		search_flag(char *s, int caract, t_infos *lst)
{
	t_infos	*tmp;
	int		len;
	int		i;
	char	*flags;

	i = 0;
	flags = ft_strnew(2);
	tmp = lst;
	if (is_flag(s[caract + 1]) == 1)	
	{
		flags[i++] = s[caract + 1];
		if (is_flag(s[caract + 2]) == 1)
			flags[i++] = s[caract + 2];
		len = caract + i;
	}
	else if (is_flag(s[caract + 1]) == 0)
	{
		len = caract;
		tmp->flag = "1";
		return (len);
	}
	flags[i] = '\0';
	tmp->flag = flags;
	return (len);
}

int		search_width(char *s, int caract, t_infos *lst)
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
	char	*modifier;
	t_infos	*tmp;

	i = 0;
	tmp = lst;
	modifier = ft_strnew(2);
	while (s[caract])
	{
		if (is_modifier(s[caract]) == 1)
		{
			modifier[i] = s[caract];
			i++;
		}
		caract++;
	}
	modifier[i] = '\0';
	tmp->modifier = modifier;
}

void	search_converter_types(char *s, int caract, t_infos *lst)
{
	int 	i;
	t_infos	*tmp;

	i = 0;
	tmp = lst;
	while (s[caract])
	{
		if ((is_converter_min(s[caract]) == 1) || (is_converter_maj(s[caract]) == 1))
		{
			tmp->type = s[caract];
			break ;
		}
		caract++;
	}
}
