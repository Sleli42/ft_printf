/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:23:32 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/23 23:21:35 by lubaujar         ###   ########.fr       */
/*   Updated: 2015/02/20 19:45:17 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *rfmt, ...)
{
	va_list arg;
	int	i;
	t_infos		*new;
	t_chkStr	*chk;

	va_start(arg, rfmt);
	i = 0;
	new = NULL;
	chk = NULL;
	new = (t_infos *)malloc(sizeof(t_infos));
	chk = (t_chkStr *)malloc(sizeof(t_chkStr));
	chk = initChkStr(chk);
	//i = checkString((char *)rfmt, arg, new, chk);
	i = checkString((char *)rfmt, arg, new, chk);
	va_end(arg);
	return (i);
}

int		noConvSpec(char *s, int c, t_infos *infos)
{
	int		i;

	i = 0;
	infos = infos;
	if (s[c] == '%' && s[c + 1] == '%')
		ft_putchar('%'), i++;
	else if (s[c] == '%' && s[c + 1] == ' ' &&s[c + 2] == '%')
		ft_putchar('%'), i++;
	return (i);
}

void	noConv(char *s, int c, t_infos *infos, t_chkStr *chk)
{
	//int		len;

	c = c;
	s = s;
	//len = defineLenString(s, c, infos);
	if (infos->width == -1)
		chk->tmp = noConvSpec(s, c, infos);
	//printf("chk->tmp: %d\n", chk->tmp);
	//printf("len s: %d\n", (int)ft_strlen(s));
	if (infos->width > 0)
	{
		while (infos->width-- > (int)ft_strlen(s) - (chk->tmp) + 1)
		{
			ft_putchar(' ');
			chk->return_val++;
		}
		chk->tmp += ft_strlen(ft_itoa(infos->width));
	}
	if (infos->flag[0] == ' ')
	{
		chk->return_val = chk->return_val - 1;
		chk->tmp = chk->tmp + 1;
	}
	//printf("tmp: %d\n", chk->tmp);
	chk->return_val += chk->tmp;
}

int		checkString(char *s, va_list arg, t_infos *new, t_chkStr *chk)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			chk->tmp = detect_infos(s, i, new);
	//		printf("chk->tmp: %d\n", chk->tmp);
			chk->return_val += define_convert(arg, new);
			if (new->conv == 'B')
				noConv(s, i, new, chk);
			while (chk->tmp-- > 0)
				i++;
		}
		else
			chk->return_val += write(1, &(s[i]), 1);
		//printf("retval: %d\n", chk->return_val);
		i++;
	}
	free(new);
	free(chk);
	return (chk->return_val);
}
