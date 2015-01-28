/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 04:40:56 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/28 05:25:57 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

int		main(void)
{
	int				i;
	unsigned int	l;
	char			*str;

	printf("\t\t--->[ %%d ]<---\n");
	printf("\t\t--->[ %%d ]<---\n\n\n");
	printf("\t\t [ MODIF ]\n\n");
	printf("\t****************************\n\n");
	printf("[printf][d]\t-->|%d|\n", INT_MAX);
	printf("[printf][d]\t-->|%d|\n\n", INT_MIN);
	ft_printf("\t[d]\t-->|%d|\n", INT_MAX);
	ft_printf("\t[d]\t-->|%d|\n\n", INT_MIN);
	printf("[printf][hd]\t-->|%hd|\n", SHRT_MAX);
	printf("[printf][hd]\t-->|%hd|\n\n", SHRT_MIN);
	ft_printf("\t[hd]\t-->|%hd|\n", SHRT_MAX);
	ft_printf("\t[hd]\t-->|%hd|\n\n", SHRT_MIN);
	printf("[printf][hhd]\t-->|%hhd|\n", SCHAR_MAX);
	printf("[printf][hhd]\t-->|%hhd|\n\n", SCHAR_MIN);
	ft_printf("\t[hhd]\t-->|%hhd|\n", SCHAR_MAX);
	ft_printf("\t[hhd]\t-->|%hhd|\n\n", SCHAR_MIN);
	printf("[printf][ld]\t-->|%ld|\n", LONG_MAX);
	printf("[printf][ld]\t-->|%ld|\n\n", LONG_MIN);
	ft_printf("\t[ld]\t-->|%ld|\n", LONG_MAX);
	ft_printf("\t[ld]\t-->|%ld|\n\n", LONG_MIN);
	printf("[printf][lld]\t-->|%lld|\n", LLONG_MAX);
	printf("[printf][lld]\t-->|%lld|\n\n", LLONG_MIN);
	ft_printf("\t[lld]\t-->|%lld|\n", LLONG_MAX);
	ft_printf("\t[lld]\t-->|%lld|\n\n", LLONG_MIN);
	printf("[printf][jd]\t-->|%jd|\n", LLONG_MAX);
	printf("[printf][jd]\t-->|%jd|\n\n", LLONG_MIN);
	ft_printf("\t[jd]\t-->|%jd|\n", LLONG_MAX);
	ft_printf("\t[jd]\t-->|%jd|\n\n", LLONG_MIN);

	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%s ]<---\n");
	printf("\t\t--->[ %%s ]<---\n\n\n");
	printf("\t\t [ SIMPLE TEST ]\n\n");
	printf("\t****************************\n\n");
	printf("[printf][s]\t-->|%s|\n", "abcde");
	ft_printf("\t[s]\t-->|%s|\n\n", "abcde");
	printf("[printf][s]\t-->|!!%s!!|\n", "??");
	ft_printf("\t[s]\t-->|!!%s!!|\n\n", "??");
	printf("[printf][s]\t-->|%s|\n", 0);
	ft_printf("\t[s]\t-->|%s|\n\n", 0);
	printf("[printf][s]\t-->|%s|\n", "");
	ft_printf("\t[s]\t-->|%s|\n\n", "");
	printf("[printf][s]\t-->|!!%s!!%s!!!%s!!!!|\n", "??", "???", "????");
	ft_printf("\t[s]\t-->|!!%s!!%s!!!%s!!!!|\n\n", "??", "???", "????");
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%p ]<---\n");
	printf("\t\t--->[ %%p ]<---\n\n\n");
	printf("\t\t [ SIMPLE TEST ]\n\n");
	printf("\t****************************\n\n");
	printf("[printf][p]\t-->|%p|\n", &i);
	ft_printf("\t[p]\t-->|%p|\n\n", &i);
	printf("[printf][p]\t-->|%p|\n", &l);
	ft_printf("\t[p]\t-->|%p|\n\n", &l);
	printf("[printf][p]\t-->|%p|\n", &str);
	ft_printf("\t[p]\t-->|%p|\n\n", &str);
	printf("[printf][p]\t-->|%p|\n", 0);
	ft_printf("\t[p]\t-->|%p|\n\n", 0);

	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");
	
	printf("\t\t [ MULTI TEST ]\n\n");
	printf("\t****************************\n\n");
	printf("[printf][.]\t-->|!!%s??%p??%d!!|\n", "string", &i, 42);
	ft_printf("\t[.]\t-->|!!%s??%p??%d!!|\n\n", "string", &i, 42);
	printf("[printf][..]\t-->|!!%d??%s??%p!!|\n", 21, "babaAuWhum", &str);
	ft_printf("\t[..]\t-->|!!%d??%s??%p!!|\n\n", 21, "babaAuWhum", &str);
	
	return (0);
}
