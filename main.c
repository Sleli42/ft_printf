/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 04:40:56 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/30 07:45:37 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

int		main(void)
{
	int				i;
	unsigned int	l;
	char			*str;

	/*ft_printf("test with string %d and after samere\n", 42);
	ft_printf("[infos] %d %i %s %p\n", 0, 0, "babaauwhum", &str);
	printf("\n");
	ft_printf("[infos] %d %i %s %p\n", 0, 0, "babaauwhum", &str);*/

	printf("\t\t--->[ %%d ]<---\n");
	printf("\t\t--->[ %%d ]<---\n\n");
	printf("\t\t [ MODIF ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
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
	printf("\t\t--->[ %%s ]<---\n\n");
	printf("\t\t [ SIMPLE TEST ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
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
	printf("\t\t--->[ %%p ]<---\n\n");
	printf("\t\t [ SIMPLE TEST ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
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
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
	printf("[printf][.]\t-->|!!%s??%p??%d!!|\n", "string", &i, 42);
	ft_printf("\t[.]\t-->|!!%s??%p??%d!!|\n\n", "string", &i, 42);
	printf("[printf][..]\t-->|!!%d??%s??%p!!|\n", 21, "babaAuWhum", &str);
	ft_printf("\t[..]\t-->|!!%d??%s??%p!!|\n\n", 21, "babaAuWhum", &str);

	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%c ]<---\n");
	printf("\t\t--->[ %%c ]<---\n\n");
	printf("\t\t [ SIMPLE TEST ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
	printf("[printf][c]\t-->|(.%c.)|\n", 'y');
	ft_printf("\t[c]\t-->|(.%c.)|\n\n", 'y');
	printf("[printf][c]\t-->|(.%c.) ** (.%c.)|\n", 'y', 'y');
	ft_printf("\t[c]\t-->|(.%c.) ** (.%c.)|\n\n", 'y', 'y');
	printf("[printf][c]\t-->|[%c%c]|\n", '4', '2');
	ft_printf("\t[c]\t-->|[%c%c]|\n\n", '4', '2');
	printf("[printf][c]\t-->|(.%c.) ** (.%c.) ** [%c%c]|\n", 'y', 'y', '4', '2');
	ft_printf("\t[c]\t-->|(.%c.) ** (.%c.) ** [%c%c]|\n\n", 'y', 'y', '4', '2');
	printf("[printf][c]\t-->|%c|\n", 0);
	ft_printf("\t[c]\t-->|%c|\n\n", 0);

	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%u ]<---\n");
	printf("\t\t--->[ %%u ]<---\n\n");
	printf("\t\t [ SIMPLE TEST ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
	printf("[printf][u]\t-->|%u|\n", 42);
	ft_printf("\t[u]\t-->|%u|\n\n", 42);
	printf("[printf][u]\t-->|%u && %u|\n", 42, 21);
	ft_printf("\t[u]\t-->|%u && %u|\n\n", 42, 21);
	printf("[printf][u]\t-->|%u|\n", UINT_MAX);
	ft_printf("\t[u]\t-->|%u|\n\n", UINT_MAX);
	printf("[printf][u]\t-->|[%u]-[%u]-[%u]|\n", UINT_MAX, 42, 21);
	ft_printf("\t[u]\t-->|[%u]-[%u]-[%u]|\n\n", UINT_MAX, 42, 21);
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%U ]<---\n");
	printf("\t\t--->[ %%U ]<---\n\n");
	printf("\t\t [ SIMPLE TEST ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
	printf("[printf][U]\t-->|%U|\n", 42);
	ft_printf("\t[U]\t-->|%U|\n\n", 42);
	printf("[printf][U]\t-->|%u|\n", ULONG_MAX);
	ft_printf("\t[U]\t-->|%u|\n\n", ULONG_MAX);
	printf("[printf][U]\t-->|%u|\n", (ULONG_MAX / 2));
	ft_printf("\t[U]\t-->|%u|\n\n", (ULONG_MAX / 2));
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%o ]<---\n");
	printf("\t\t--->[ %%o ]<---\n\n");
	printf("\t\t [ SIMPLE TEST ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
	printf("[printf][o]\t-->|%o|\n", 42);
	ft_printf("\t[o]\t-->|%o|\n\n", 42);
	printf("[printf][o]\t-->|%o|\n", UINT_MAX);
	ft_printf("\t[o]\t-->|%o|\n\n", UINT_MAX);
	printf("[printf][o]\t-->|[%o]-[%o]-[%o]|\n", 42, 21, UINT_MAX);
	ft_printf("\t[o]\t-->|[%o]-[%o]-[%o]|\n\n", 42, 21, UINT_MAX);
	printf("[printf][o]\t-->|%o|\n", 0);
	ft_printf("\t[o]\t-->|%o|\n\n", 0);
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%O ]<---\n");
	printf("\t\t--->[ %%O ]<---\n\n");
	printf("\t\t [ simple test ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
	printf("[printf][O]\t-->|%O|\n", 42);
	ft_printf("\t[O]\t-->|%O|\n\n", 42);
	printf("[printf][O]\t-->|%O|\n", ULONG_MAX);
	ft_printf("\t[O]\t-->|%O|\n\n", ULONG_MAX);
	printf("[printf][O]\t-->|[%O]-[%O]-[%O]|\n", 42, 21, ULONG_MAX);
	ft_printf("\t[O]\t-->|[%O]-[%O]-[%O]|\n\n", 42, 21, ULONG_MAX);
	printf("[printf][O]\t-->|%O|\n", 0);
	ft_printf("\t[O]\t-->|%O|\n\n", 0);
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%x ]<---\n");
	printf("\t\t--->[ %%x ]<---\n\n");
	printf("\t\t [ simple test ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
	printf("[printf][x]\t-->|%x|\n", 42);
	ft_printf("\t[x]\t-->|%x|\n\n", 42);
	printf("[printf][x]\t-->|%o|\n", UINT_MAX);
	ft_printf("\t[x]\t-->|%o|\n\n", UINT_MAX);
	printf("[printf][x]\t-->|[%x]-[%x]-[%x]|\n", 42, 21, UINT_MAX);
	ft_printf("\t[x]\t-->|[%x]-[%x]-[%x]|\n\n", 42, 21, UINT_MAX);
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ %%X ]<---\n");
	printf("\t\t--->[ %%X ]<---\n\n");
	printf("\t\t [ simple test ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
	printf("[printf][X]\t-->|%X|\n", 42);
	ft_printf("\t[x]\t-->|%X|\n\n", 42);
	printf("[printf][X]\t-->|%X|\n", UINT_MAX);
	ft_printf("\t[X]\t-->|%X|\n\n", UINT_MAX);
	printf("[printf][X]\t-->|[%X]-[%X]-[%X]|\n", 42, 21, UINT_MAX);
	ft_printf("\t[X]\t-->|[%X]-[%X]-[%X]|\n\n", 42, 21, UINT_MAX);
	
	printf("\n   |o|o|o|*****************************************|o|o|o|\n\n");

	printf("\t\t--->[ oth ]<---\n");
	printf("\t\t--->[ oth ]<---\n\n");
	printf("\t\t [ simple test ]\n\n");
	printf("\t*********************************\n");
	printf("\t*********************************\n\n");
	printf("[printf][oth]\t-->|%%|\n");
	ft_printf("\t[oth]\t-->|%%|\n\n");
	printf("[printf][oth]\t-->|aa%%bb|\n");
	ft_printf("\t[oth]\t-->|aa%%bb|\n\n");
	return (0);
}
