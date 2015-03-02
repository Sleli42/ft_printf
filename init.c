/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 22:21:53 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 04:16:57 by lubaujar         ###   ########.fr       */
/*   Updated: 2015/02/20 07:58:49 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_chkStr	*initChkStr(t_chkStr *chk)
{
	t_chkStr *tmp;

	tmp = chk;
	tmp->return_val = 0;
	tmp->tmp = 0;
	return (tmp);
}

int		detect_infos(char *s, int c, t_infos *new)
{
	int		i;

	i = 0;
	new->flag = search_flag(s, c);
	if (new->flag[0] != '\0')
		i += ft_strlen(new->flag);
	//printf("[flag]i value : |%d|\n", i);
	//printf("*tmp: |%d|\n", i);
//	printf("flag : |%s|\n", new->flag);
	new->width = search_width(s, c);
	if (new->width > 0)
		i += ft_strlen(ft_itoa(new->width));
	//printf("[width]i value : |%d|\n", i);
//	printf("width a pass: |%d|\n", (int)ft_strlen(ft_itoa(new->width)));
//	printf("width : |%d|\n", new->width);
	new->prec = search_prec(s, c);
	if (new->prec > 0)
		i += ft_strlen(ft_itoa(new->prec)) + 1;
	if (new->prec == -2)
	{
	//	printf("yolo\n");
		i += 1;
	}
	if (new->prec == -3)
	{
		//printf("yolo\n");
		i += 2;
	}
	//else if (new->prec == -1)
	//	i += 1;
	//printf("[prec]i value : |%d|\n", i);
//	printf("prec a pass: |%d|\n", (int)ft_strlen(ft_itoa(new->prec)));
	//printf("prec : |%d|\n", new->prec);
	new->conv = search_conv(s, c);
	if (new->conv != 'B')
		i += 1;
	new->modif = search_modif(s, c, new->conv);
	if (new->modif[0] != '\0')
		i += ft_strlen(new->modif);
//	printf("tmp: |%d|\n", i);
	return (i);
}

int		define_convert(va_list arg, t_infos *infos)
{
	t_infos	*tmp;
	int		val;

	tmp = infos;
	val = 0;
	if (tmp->conv == 'd' || tmp->conv == 'i')
		val = convert_int(arg, tmp);
	if (tmp->conv == 'D')
		val = convert_long_int(arg, tmp);
	if (tmp->conv == 's' && tmp->modif[0] != 'l')
		val = convert_string(arg, tmp);
	if (tmp->conv == 'c' && tmp->modif[0] != 'l')
		val = convert_char(arg, tmp);
	if (tmp->conv == 'C' || (tmp->conv == 'c' && tmp->modif[0] == 'l'))
		val = convert_wchar(arg, tmp);
	if (tmp->conv == 'p')
		val = convert_pointer(arg, tmp);
	if (tmp->conv == 'S' || (tmp->conv == 's' && tmp->modif[0] == 'l'))
		val = convert_wchar_string(arg, tmp);
	if (tmp->conv == 'u' || tmp->conv == 'U')
		val = convert_unsigned(arg, tmp);
	if (tmp->conv == 'o' || tmp->conv == 'O')
		val = convert_octal(arg, tmp);
	if (tmp->conv == 'x' || tmp->conv == 'X')
		val = convert_hexa(arg, tmp);
	return (val);
}
