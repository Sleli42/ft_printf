/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 04:40:56 by lubaujar          #+#    #+#             */
/*   Updated: 2015/02/05 22:42:38 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

int		main(void)
{
	int				i;
	unsigned int	l;
	char			*str;

	/*printf("{%05.c}", 0);
	printf("\n");
	ft_printf("{%05.c}", 0);
	printf("\n");*/
//	ft_printf("111%s333\n", "222");
/*	ft_printf("[infos] %d %i %s %p\n", 0, 0, "babaauwhum", &str);
	printf("\n");
	ft_printf("[infos] %d %i %s %p\n", 0, 0, "babaauwhum", &str);*/

	printf("\t\t--->[ %%d ]<---\n");
	printf("\t\t--->[ %%d ]<---\n");
	printf("\t\t [ MODIF ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][d]\t-->|%d|\n", INT_MAX);
	ft_printf("\t[d]\t-->|%d|\n", INT_MAX);
	printf("[printf][d]\t-->|%d|\n", INT_MIN);
	ft_printf("\t[d]\t-->|%d|\n", INT_MIN);
	printf("[printf][hd]\t-->|%hd|\n", SHRT_MAX);
	ft_printf("\t[hd]\t-->|%hd|\n", SHRT_MAX);
	printf("[printf][hd]\t-->|%hd|\n", SHRT_MIN);
	ft_printf("\t[hd]\t-->|%hd|\n", SHRT_MIN);
	printf("[printf][hhd]\t-->|%hhd|\n", SCHAR_MAX);
	ft_printf("\t[hhd]\t-->|%hhd|\n", SCHAR_MAX);
	printf("[printf][hhd]\t-->|%hhd|\n", SCHAR_MIN);
	ft_printf("\t[hhd]\t-->|%hhd|\n", SCHAR_MIN);
	printf("[printf][ld]\t-->|%ld|\n", LONG_MAX);
	ft_printf("\t[ld]\t-->|%ld|\n", LONG_MAX);
	printf("[printf][ld]\t-->|%ld|\n", LONG_MIN);
	ft_printf("\t[ld]\t-->|%ld|\n", LONG_MIN);
	printf("[printf][lld]\t-->|%lld|\n", LLONG_MAX);
	ft_printf("\t[lld]\t-->|%lld|\n", LLONG_MAX);
	printf("[printf][lld]\t-->|%lld|\n", LLONG_MIN);
	ft_printf("\t[lld]\t-->|%lld|\n", LLONG_MIN);
	printf("[printf][jd]\t-->|%jd|\n", LLONG_MAX);
	ft_printf("\t[jd]\t-->|%jd|\n", LLONG_MAX);
	printf("[printf][jd]\t-->|%jd|\n", LLONG_MIN);
	ft_printf("\t[jd]\t-->|%jd|\n", LLONG_MIN);
	printf("\t\t [ .PREC ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][d]\t-->|%.0d|\n", 42);
	ft_printf("\t[d]\t-->|%.0d|\n", 42);
	printf("[printf][d]\t-->|%.d|\n", 42);
	ft_printf("\t[d]\t-->|%.d|\n", 42);
	printf("[printf][d]\t-->|%.0d|\n", 0);
	ft_printf("\t[d]\t-->|%.0d|\n", 0);
	printf("[printf][d]\t-->|%.d|\n", 0);
	ft_printf("\t[d]\t-->|%.d|\n", 0);
	printf("[printf][d]\t-->|%.7d|\n", 42);
	ft_printf("\t[d]\t-->|%.7d|\n", 42);
	printf("[printf][d]\t-->|%.7d|\n", -42);
	ft_printf("\t[d]\t-->|%.7d|\n", -42);
	printf("[printf][d]\t-->|%.21d|\n", 42);
	ft_printf("\t[d]\t-->|%.21d|\n", 42);
	printf("[printf][d]\t-->|%.21d|\n", -42);
	ft_printf("\t[d]\t-->|%.21d|\n", -42);
	printf("\t\t [ WIDTH ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][d]\t-->|%1d|\n", 42);
	ft_printf("\t[d]\t-->|%1d|\n", 42);
	printf("[printf][d]\t-->|%1d|\n", -42);
	ft_printf("\t[d]\t-->|%1d|\n", -42);
	printf("[printf][d]\t-->|%10d|\n", 0);
	ft_printf("\t[d]\t-->|%10d|\n", 0);
	printf("[printf][d]\t-->|%1d|\n", 0);
	ft_printf("\t[d]\t-->|%1d|\n", 0);
	printf("[printf][d]\t-->|%21d|\n", 42);
	ft_printf("\t[d]\t-->|%21d|\n", 42);
	printf("[printf][d]\t-->|%21d|\n", -42);
	ft_printf("\t[d]\t-->|%21d|\n", -42);
	printf("[printf][d]\t-->|%42d|\n", 42);
	ft_printf("\t[d]\t-->|%42d|\n", 42);
	printf("[printf][d]\t-->|%42d|\n", -42);
	ft_printf("\t[d]\t-->|%42d|\n", -42);
	printf("\t\t [ WIDTH + .PREC ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][d]\t-->|%1.0d|\n", 42);
	ft_printf("\t[d]\t-->|%1.0d|\n", 42);
	printf("[printf][d]\t-->|%1.0d|\n", -42);
	ft_printf("\t[d]\t-->|%1.0d|\n", -42);
	printf("[printf][d]\t-->|%10.2d|\n", 42);
	ft_printf("\t[d]\t-->|%10.2d|\n", 42);
	printf("[printf][d]\t-->|%10.21d|\n", 42);
	ft_printf("\t[d]\t-->|%10.21d|\n", 42);
	printf("[printf][d]\t-->|%42.21d|\n", INT_MAX);
	ft_printf("\t[d]\t-->|%42.21d|\n", INT_MAX);
	printf("[printf][d]\t-->|%42.21d|\n", INT_MIN);
	ft_printf("\t[d]\t-->|%42.21d|\n", INT_MIN);
	printf("[printf][d]\t-->|%26.24d|*|%26.24d|\n", INT_MAX, INT_MIN);
	ft_printf("\t[d]\t-->|%26.24d|*|%26.24d|\n", INT_MAX, INT_MIN);
	printf("\t\t [ Space ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][d]\t-->|wesh % d wesh|\n", 42);
	ft_printf("\t[d]\t-->|wesh % d wesh|\n", 42);
	printf("[printf][d]\t-->|% d|\n", -42);
	ft_printf("\t[d]\t-->|% d|\n", -42);
	printf("[printf][d]\t-->|% d|\n", INT_MAX);
	ft_printf("\t[d]\t-->|% d|\n", INT_MAX);

	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%s ]<---\n");
	printf("\t\t--->[ %%s ]<---\n");
	printf("\t\t [ SIMPLE TEST ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][s]\t-->|%s|\n", "abcde");
	ft_printf("\t[s]\t-->|%s|\n", "abcde");
	printf("[printf][s]\t-->|!!%s!!|\n", "??");
	ft_printf("\t[s]\t-->|!!%s!!|\n", "??");
	printf("[printf][s]\t-->|%s|\n", 0);
	ft_printf("\t[s]\t-->|%s|\n", 0);
	printf("[printf][s]\t-->|%s|\n", "");
	ft_printf("\t[s]\t-->|%s|\n", "");
	printf("[printf][s]\t-->|!!%s!!%s!!!%s!!!!|\n", "??", "???", "????");
	ft_printf("\t[s]\t-->|!!%s!!%s!!!%s!!!!|\n", "??", "???", "????");
	printf("\t\t [ .PREC ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][s]\t-->|%.1s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%.1s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%.10s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%.10s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%.42s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%.42s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%.4s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%.4s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%.2s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%.2s|\n", "Baba Au Whum");
	printf("\t\t [ WIDTH ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][s]\t-->|%1s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%1s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%10s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%10s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%42s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%42s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%13s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%13s|\n", "Baba Au Whum");
	printf("\t\t [ WIDTH + .PREC ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][s]\t-->|%1.1s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%1.1s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%10.1s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%10.1s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%10.10s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%10.10s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%42.21s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%42.21s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%3.21s|\n", "Baba Au Whum");
	ft_printf("\t[s]\t-->|%3.21s|\n", "Baba Au Whum");
	printf("[printf][s]\t-->|%10.21s|\n", "");
	ft_printf("\t[s]\t-->|%10.21s|\n", "");
	printf("[printf][s]\t-->|%21.12s|\n", "42");
	ft_printf("\t[s]\t-->|%21.12s|\n", "42");
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t --->[ %%p ]<---\n");
	printf("\t\t --->[ %%p ]<---\n");
	printf("\t\t [ SIMPLE TEST ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][p]\t-->|%p|\n", &i);
	ft_printf("\t[p]\t-->|%p|\n", &i);
	printf("[printf][p]\t-->|%p|\n", &l);
	ft_printf("\t[p]\t-->|%p|\n", &l);
	printf("[printf][p]\t-->|%p|\n", &str);
	ft_printf("\t[p]\t-->|%p|\n", &str);
	printf("[printf][p]\t-->|%p|\n", 0);
	ft_printf("\t[p]\t-->|%p|\n", 0);
	printf("\t\t [ .PREC ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][p]\t-->|%.1p|\n", &i);
	ft_printf("\t[p]\t-->|%.1p|\n", &i);
	printf("[printf][p]\t-->|%.21p|\n", &i);
	ft_printf("\t[p]\t-->|%.21p|\n", &i);
	printf("[printf][p]\t-->|%.12p|\n", &str);
	ft_printf("\t[p]\t-->|%.12p|\n", &str);
	printf("[printf][p]\t-->|%.21p|\n", &str);
	ft_printf("\t[p]\t-->|%.21p|\n", &str);
	printf("\t\t [ WIDTH ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][p]\t-->|%1p|\n", &i);
	ft_printf("\t[p]\t-->|%1p|\n", &i);
	printf("[printf][p]\t-->|%21p|\n", &i);
	ft_printf("\t[p]\t-->|%21p|\n", &i);
	printf("[printf][p]\t-->|%1p|\n", &str);
	ft_printf("\t[p]\t-->|%1p|\n", &str);
	printf("[printf][p]\t-->|%42p|\n", &str);
	ft_printf("\t[p]\t-->|%42p|\n", &str);
	printf("\t\t [ WIDTH + .PREC ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][p]\t-->|%1.1p|\n", &i);
	ft_printf("\t[p]\t-->|%1.1p|\n", &i);
	printf("[printf][p]\t-->|%21.3p|\n", &i);
	ft_printf("\t[p]\t-->|%21.3p|\n", &i);
	printf("[printf][p]\t-->|%1.21p|\n", &str);
	ft_printf("\t[p]\t-->|%1.21p|\n", &str);
	printf("[printf][p]\t-->|%42.21p|\n", &str);
	ft_printf("\t[p]\t-->|%42.21p|\n", &str);

	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t --->[ %%c ]<---\n");
	printf("\t\t --->[ %%c ]<---\n");
	printf("\t\t [ SIMPLE TEST ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][c]\t-->|(.%c.)|\n", 'y');
	ft_printf("\t[c]\t-->|(.%c.)|\n", 'y');
	printf("[printf][c]\t-->|(.%c.) ** (.%c.)|\n", 'y', 'y');
	ft_printf("\t[c]\t-->|(.%c.) ** (.%c.)|\n", 'y', 'y');
	printf("[printf][c]\t-->|[%c%c]|\n", '4', '2');
	ft_printf("\t[c]\t-->|[%c%c]|\n", '4', '2');
	printf("[printf][c]\t-->|(.%c.) ** (.%c.) ** [%c%c]|\n", 'y', 'y', '4', '2');
	ft_printf("\t[c]\t-->|(.%c.) ** (.%c.) ** [%c%c]|\n", 'y', 'y', '4', '2');
	printf("[printf][c]\t-->|%c|\n", 0);
	ft_printf("\t[c]\t-->|%c|\n", 0);

	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t --->[ %%u ]<---\n");
	printf("\t\t --->[ %%u ]<---\n");
	printf("\t\t [ SIMPLE TEST ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][u]\t-->|%u|\n", 42);
	ft_printf("\t[u]\t-->|%u|\n", 42);
	printf("[printf][u]\t-->|%u && %u|\n", 42, 21);
	ft_printf("\t[u]\t-->|%u && %u|\n", 42, 21);
	printf("[printf][u]\t-->|%u|\n", UINT_MAX);
	ft_printf("\t[u]\t-->|%u|\n", UINT_MAX);
	printf("[printf][u]\t-->|[%u]-[%u]-[%u]|\n", UINT_MAX, 42, 21);
	ft_printf("\t[u]\t-->|[%u]-[%u]-[%u]|\n", UINT_MAX, 42, 21);
	printf("\t\t [ WIDTH ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t --->[ %%U ]<---\n");
	printf("\t\t --->[ %%U ]<---\n");
	printf("\t\t [ SIMPLE TEST ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][U]\t-->|%U|\n", 42);
	ft_printf("\t[U]\t-->|%U|\n", 42);
	printf("[printf][U]\t-->|%u|\n", ULONG_MAX);
	ft_printf("\t[U]\t-->|%u|\n", ULONG_MAX);
	printf("[printf][U]\t-->|%u|\n", (ULONG_MAX / 2));
	ft_printf("\t[U]\t-->|%u|\n", (ULONG_MAX / 2));
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%o ]<---\n");
	printf("\t\t--->[ %%o ]<---\n");
	printf("\t\t [ SIMPLE TEST ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][o]\t-->|%o|\n", 42);
	ft_printf("\t[o]\t-->|%o|\n", 42);
	printf("[printf][o]\t-->|%o|\n", UINT_MAX);
	ft_printf("\t[o]\t-->|%o|\n", UINT_MAX);
	printf("[printf][o]\t-->|[%o]-[%o]-[%o]|\n", 42, 21, UINT_MAX);
	ft_printf("\t[o]\t-->|[%o]-[%o]-[%o]|\n", 42, 21, UINT_MAX);
	printf("[printf][o]\t-->|%o|\n", 0);
	ft_printf("\t[o]\t-->|%o|\n", 0);
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%O ]<---\n");
	printf("\t\t--->[ %%O ]<---\n");
	printf("\t\t [ simple test ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][O]\t-->|%O|\n", 42);
	ft_printf("\t[O]\t-->|%O|\n", 42);
	printf("[printf][O]\t-->|%O|\n", ULONG_MAX);
	ft_printf("\t[O]\t-->|%O|\n", ULONG_MAX);
	printf("[printf][O]\t-->|[%O]-[%O]-[%O]|\n", 42, 21, ULONG_MAX);
	ft_printf("\t[O]\t-->|[%O]-[%O]-[%O]|\n", 42, 21, ULONG_MAX);
	printf("[printf][O]\t-->|%O|\n", 0);
	ft_printf("\t[O]\t-->|%O|\n", 0);
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%x ]<---\n");
	printf("\t\t--->[ %%x ]<---\n");
	printf("\t\t [ simple test ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][x]\t-->|%x|\n", 42);
	ft_printf("\t[x]\t-->|%x|\n", 42);
	printf("[printf][x]\t-->|%o|\n", UINT_MAX);
	ft_printf("\t[x]\t-->|%o|\n", UINT_MAX);
	printf("[printf][x]\t-->|[%x]-[%x]-[%x]|\n", 42, 21, UINT_MAX);
	ft_printf("\t[x]\t-->|[%x]-[%x]-[%x]|\n", 42, 21, UINT_MAX);
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%X ]<---\n");
	printf("\t\t--->[ %%X ]<---\n");
	printf("\t\t [ simple test ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][X]\t-->|%X|\n", 42);
	ft_printf("\t[x]\t-->|%X|\n", 42);
	printf("[printf][X]\t-->|%X|\n", UINT_MAX);
	ft_printf("\t[X]\t-->|%X|\n", UINT_MAX);
	printf("[printf][X]\t-->|[%X]-[%X]-[%X]|\n", 42, 21, UINT_MAX);
	ft_printf("\t[X]\t-->|[%X]-[%X]-[%X]|\n", 42, 21, UINT_MAX);
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ oth ]<---\n");
	printf("\t\t--->[\033[31mOTHERS\033[0m]<---\n");
	printf("\t\t [ simple test ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][oth]\t-->|%%|\n");
	ft_printf("\t[oth]\t-->|%%|\n");
	printf("[printf][oth]\t-->|aa%%bb|\n");
	ft_printf("\t[oth]\t-->|aa%%bb|\n");
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");
	
	printf("\t\t [ MULTI TEST ]\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n");
	printf("[printf][.]\t-->|!!%s??%p??%d!!|\n", "string", &i, 42);
	ft_printf("\t[.]\t-->|!!%s??%p??%d!!|\n", "string", &i, 42);
	printf("[printf][..]\t-->|!!%d??%s??%p!!|\n", 21, "babaAuWhum", &str);
	ft_printf("\t[..]\t-->|!!%d??%s??%p!!|\n", 21, "babaAuWhum", &str);
//	ft_printf("{%03c}", 'h');
/*	printf("{%#.5x}\n", 0);
	ft_printf("{%#.5x}\n", 0);
	ft_printf("{%05.%}", 0);*/
	return (0);
}
