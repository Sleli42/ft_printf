/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:49 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/03 06:05:15 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	detect_infos(char *cpy, int caract, t_infos *new)
{
	int		len;

	len = search_flag(cpy, caract, new);
	len = search_width(cpy, len, new);
	len = search_precision(cpy, len, new);
	search_modifier(cpy, caract, new);
	search_converter_types(cpy, caract, new);
}

void	define_convert(t_infos *lst, va_list arg)
{
	t_infos	*tmp;

	tmp = lst;
	if (is_int(tmp->type) == 1)
		convert_int(arg, tmp);
}

int		find_flag(char *s, int integrer)
{
	char tab[100];
	char salope;
	int		i = 1;
	int z = 0;
	
	salope = ft_itoi(integrer);
	if (s == "-")
		return (1);
	else if (s == "+")
		{
			tab[0] = "+"
			while(tab[i])
			{
				tab[i] = salope[z];
				i++;
				z++;
				printf("lucas suce d bite : %s", tab);
			}

		}
	else if (s == " ")
	else if (s == "0")
		
}
