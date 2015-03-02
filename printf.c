/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 06:05:45 by lubaujar          #+#    #+#             */
/*   Updated: 2015/03/02 06:10:07 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(const char *rfmt, ...)
{
	va_list		arg;
	int			i;
	t_infos		*new;
	t_chkStr	*chk;

	va_start(arg, rfmt);
	i = 0;
	new = NULL;
	chk = NULL;
	new = (t_infos *)malloc(sizeof(t_infos));
	chk = (t_chkStr *)malloc(sizeof(t_chkStr));
	chk = initChkStr(chk);
	i = checkString((char *)rfmt, arg, new, chk);
	va_end(arg);
	return (i);
}

int			noConvSpec(char *s, int c, t_chkStr *chk)
{
	int		i;

	i = 0;
	if (s[c] == '%' && s[c + 1] != '%')
		i = checkIfAnotherPercent(s, c, chk);
	else if (s[c] == '%' && s[c + 1] == '%')
		ft_putchar('%'), i++, chk->return_val++;
	if (s[c] == '%' && s[c + 1] == ' ' && s[c + 2] == '%')
		ft_putchar('%'), i++, chk->return_val++;
	return (i);
}

int			checkIfAnotherPercent(char *s, int c, t_chkStr *chk)
{
	int		i;

	i = 0;
	while (chk->tmp-- >= 0)
		c++, i++;
	chk->tmp += i;
	i = 0;
	if (s[c] == '%')
	{
		ft_putchar('%'), chk->return_val++, i++;
	}
	return (i);
}

void		noConv(char *s, int c, t_infos *infos, t_chkStr *chk)
{
	char		*str;
	int			len;

	c = c;
	s = s;
	len = 0;
	if (infos->width == -1)
		chk->tmp = noConvSpec(s, c, chk);
	if (infos->prec > 0)
		chk->tmp += ft_strlen(ft_itoa(infos->prec)) + 1;
	if (infos->width > 0)
	{
		str = searchChar(s, c);
		if (str != NULL)
			len = (int)ft_strlen(str);
		else
			len = 1;
		if (infos->flag[0] != '-')
		{
			if (infos->flag[0] != '0')
				while (infos->width-- > len)
					ft_putchar(' '), chk->return_val++;
			else if (infos->flag[0] == '0')
				while (infos->width-- > len)
					ft_putchar('0'), chk->return_val++;
			if (str == NULL && checkIfAnotherPercent(s, c, chk) == 1)
				str = NULL;
		}
		if (str != NULL)
			ft_putstr(str), chk->return_val++;
		if (infos->flag[0] == '-')
			while (infos->width - (int)ft_strlen(str) > 0)
				ft_putchar(' '), chk->return_val++, infos->width--;
		chk->tmp += ft_strlen(ft_itoa(infos->width));
	}
	if (infos->flag[0] == ' ')
		chk->tmp = chk->tmp + 1;
}

int			checkString(char *s, va_list arg, t_infos *new, t_chkStr *chk)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			chk->tmp = detect_infos(s, i, new);
			chk->return_val += define_convert(arg, new);
			if (new->conv == 'B')
				noConv(s, i, new, chk);
			while (chk->tmp-- > 0)
				i++;
		}
		else
			chk->return_val += write(1, &(s[i]), 1);
		i++;
	}
	free(new);
	return (chk->return_val);
}
