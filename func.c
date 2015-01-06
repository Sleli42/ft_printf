/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 04:15:49 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/06 06:41:03 by lubaujar         ###   ########.fr       */
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

void	find_flag(char *flag, int integer, t_infos *lst)
{
	t_infos	*tmp;
	char	*ret;
	char	*c_int;
	char	*temp;
	int		i;
	int		j;
	int		width_max;

	tmp = lst;
	c_int = ft_itoa(integer);
	i = 0;
	j = 0;
	if (tmp->width != 0)
		width_max = tmp->width;
	else
		width_max = 0;
	if (flag[0] == '+')
	{
		if (integer > 0)
		{
			ret = ft_strnew(ft_strlen(ft_itoa(integer) + 2));
			if (flag[1] == '0')
			{
				/*...*/
			}
			ret[i] = '+';
			while (c_int[j])
				ret[++i] = c_int[j++];
			ret[i + 1] = '\0';
			temp = ret;
			free(ret);
			if (tmp->precision != 0 && tmp->precision > ft_strlen(ft_itoa(integer)))
			{
				i = 1;
				j = 0;
				//ret = ft_strnew(tmp->precision + 2);
				ret = ft_strnew(tmp->precision + 2);
				ret[0] = '+';
				while (i <= tmp->precision - ft_strlen(ft_itoa(integer)))
				{
					ret[i] = '0';
					i++;
				}
				while (i < tmp->precision + 1 && c_int[j])
						ret[i++] = c_int[j++];
				ret[i + 1] = '\0';
				temp = ret;
				free(ret);
				ft_putstr(temp);
			}
		}
	}
}
/*
   t_infos	*tmp;
   int		i;
   int		j;

   tmp = lst;
   i = -1;
   j = ft_strlen(ft_itoa(integer));
   if (*s == '+')
   {
   if (integer > 0)
   {
   if (tmp->width != 0 && s[1] == '0')
   {
   ft_putchar('+');
   while (++i < tmp->width - ft_strlen(ft_itoa(integer)) -1)
   ft_putchar('0');
   }
   else if (tmp->width != 0 && s[1] != '0')
   {
   while (++i < tmp->width - ft_strlen(ft_itoa(integer)) - 1)
   ft_putchar(' ');
   if (tmp->precision != 0 && tmp->precision > ft_strlen(ft_itoa(integer)))
   {
   ft_putchar('+');
   while (tmp->precision > j)
   {
   ft_putchar('0');
   j++;
   }
   }
   else
   ft_putchar('+');
   }
   }
   }
   */
