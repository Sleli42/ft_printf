/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:13:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/01/22 12:53:31 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *rfmt, ...)
{
	va_list	arg;
	int		i;
	int		len;
	char	*cpy;
	t_infos	*new;

	i = 0;
	cpy = ft_strdup(rfmt);
	new = NULL;
	va_start(arg, rfmt);
	while (cpy[i])
	{
		if (cpy[i] == '%' && cpy[i + 1] == '%')
		{
			ft_putchar('%');
			i = i + 2;
		}
		if (cpy[i] == '%')
		{
			new = (t_infos *)malloc(sizeof(t_infos));
			detect_infos(cpy, i, new);
		//	affiche_detect(&new);
			define_convert(new, arg);
			while (cpy[i] != new->type)
				i++;
			free(new);
			//printf("c_current:%c\n", cpy[i]);
		}
		else
			ft_putchar(cpy[i]);
		i++;
	}
	va_end(arg);
}

int		main(void)
{
	unsigned long		uuu;
	long long int		i;
	long long int		longg;
	long long int		longgg;
	int					test;
	int					ooo;
	char	*s;
	void	*addr;
	wchar_t c = L'暖'; 

	longg = 3333333333333;
	longgg = 4242424242424242;
	i = 214221;
	test = 4242;
	s = "baba au whum";
	addr = (char *)"poneeyyy";

/*	printf("\t\t\t\t-->[TEST %%o]<--\n\n");
	printf("[printf]test:\t |%o|\n", i);
	ft_printf("[ft_printf]test: |%o|\n\n", i);
	printf("[printf]test:\t |%ho|\n", i);
	ft_printf("[ft_printf]test: |%ho|\n\n", i);
	printf("[printf]test:\t |%#o|\n", i);
	ft_printf("[ft_printf]test: |%#o|\n\n", i);
	printf("[printf]test:\t |%#15o|\n", i);
	ft_printf("[ft_printf]test: |%#15o|\n\n", i);
	printf("[printf]test:\t |%#15.24o|\n", i);
	ft_printf("[ft_printf]test: |%#15.24o|\n\n", i);
	printf("[printf]test:\t |%.10o|\n", i);
	ft_printf("[ft_printf]test: |%.10o|\n\n", i);
	printf("[printf]test:\t |%#.10o|\n", i);
	ft_printf("[ft_printf]test: |%#.10o|\n\n", i);
	printf("[printf]test:\t |%20o|\n", i);
	ft_printf("[ft_printf]test: |%20o|\n\n", i);
	printf("[printf]test:\t |%20.12o|\n", i);
	ft_printf("[ft_printf]test: |%20.12o|\n\n", i);
	printf("[printf]test:\t |%-15o|\n", i);
	ft_printf("[ft_printf]test: |%-15o|\n\n", i);
	printf("[printf]test:\t |%-15.9o|\n", i);
	ft_printf("[ft_printf]test: |%-15.9o|\n\n", i);
	printf("\t\t\t\t-->[TEST %%x]<--\n\n");
	printf("[printf]test:\t |%x|\n", i);
	ft_printf("[ft_printf]test: |%x|\n\n", i);
	printf("[printf]test:\t |%X|\n", i);
	ft_printf("[ft_printf]test: |%X|\n\n", i);
	printf("[printf]test:\t |%#X|\n", i);
	ft_printf("[ft_printf]test: |%#X|\n\n", i);
	printf("[printf]test:\t |%#x|\n", i);
	ft_printf("[ft_printf]test: |%#x|\n\n", i);
	printf("[printf]test:\t |%hx|\n", i);
	ft_printf("[ft_printf]test: |%hx|\n\n", i);
	printf("[printf]test:\t |%d|\n", i);
	ft_printf("[ft_printf]test: |%d|\n\n", i);
	printf("[printf]test:\t |%x|\n", i);
	ft_printf("[ft_printf]test: |%x|\n\n", i);
	printf("[printf]test:\t |%X|\n", i);
	ft_printf("[ft_printf]test: |%X|\n\n", i);
	printf("[printf]test:\t |%#X|\n", i);
	ft_printf("[ft_printf]test: |%#X|\n\n", i);
	printf("[printf]test:\t |%#x|\n", i);
	ft_printf("[ft_printf]test: |%#x|\n\n", i);
	printf("[printf]test:\t |%hx|\n", i);
	ft_printf("[ft_printf]test: |%hx|\n\n", i);
	printf("\t\t\t\t-->[TEST %%u]<--\n\n");
	printf("[printf]test:\t |%u|\n", i);
	ft_printf("[ft_printf]test: |%u|\n\n", i);
	printf("[printf]test:\t |%20u|\n", i);
	ft_printf("[ft_printf]test: |%20u|\n\n", i);
	printf("[printf]test:\t |%.10u|\n", i);
	ft_printf("[ft_printf]test: |%.10u|\n\n", i);
	printf("[printf]test:\t |%20.10u|\n", i);
	ft_printf("[ft_printf]test: |%20.10u|\n\n", i);
	printf("[printf]test:\t |%#u|\n", i);
	ft_printf("[ft_printf]test: |%#u|\n\n", i);
	printf("[printf]test:\t |%#20u|\n", i);
	ft_printf("[ft_printf]test: |%#20u|\n\n", i);
	printf("[printf]test:\t |%#.12u|\n", i);
	ft_printf("[ft_printf]test: |%#.12u|\n\n", i);
	printf("[printf]test:\t |%#22.12u|\n", i);
	ft_printf("[ft_printf]test: |%#22.12u|\n\n", i);
	printf("[printf]test:\t |%020.10u|\n", i);
	ft_printf("[ft_printf]test: |%020.10u|\n\n", i);
	printf("[printf]test:\t |%020u|\n", i);
	ft_printf("[ft_printf]test: |%020u|\n\n", i);
	printf("[printf]test:\t |%-20u|\n", i);
	ft_printf("[ft_printf]test: |%-20u|\n\n", i);
	printf("[printf]test:\t |%-20.8u|\n", i);
	ft_printf("[ft_printf]test: |%-20.8u|\n\n", i);
	printf("\t\t\t\t-->[TEST %%U]<--\n\n");
	printf("[printf]test:\t |%U|\n", i);
	ft_printf("[ft_printf]test: |%U|\n\n", i);
	printf("\t\t\t\t-->[TEST %%s]<--\n\n");
	printf("[printf]test:\t |%s|\n", s);
	ft_printf("[ft_printf]test: |%s|\n\n", s);
	printf("[printf]test:\t |%42.42s|\n", s);
	ft_printf("[ft_printf]test: |%42.42s|\n\n", s);
	printf("[printf]test:\t |%021s|\n", s);
	ft_printf("[ft_printf]test: |%021s|\n\n", s);
	printf("[printf]test:\t |%-.4s|\n", s);
	ft_printf("[ft_printf]test: |%-.4s|\n\n", s);
	printf("[printf]test:\t |%-20s|\n", s);
	ft_printf("[ft_printf]test: |%-20s|\n\n", s);
	printf("[printf]test:\t |%-20.4s|\n", s);
	ft_printf("[ft_printf]test: |%-20.4s|\n\n", s);
	printf("[printf]test:\t |%-.4s|\n", s);
	ft_printf("[ft_printf]test: |%-.4s|\n\n", s);
	printf("\t\t\t\t-->[TEST %%d]<--\n\n");
	printf("[printf]test:\t |% .17d|\n", i);
	ft_printf("[ft_printf]test: |% .17d|\n\n", i);
	printf("[printf]test:\t |% 10.10d|\n", i);
	ft_printf("[ft_printf]test: |% 10.10d|\n\n", i);
	printf("[printf]test:\t |%hd|\n", i);
	ft_printf("[ft_printf]test: |%hd|\n\n", i);
	printf("[printf]test:\t |%+hd|\n", i);
	ft_printf("[ft_printf]test: |%+hd|\n\n", i);
	printf("[printf]test:\t |%-10hd|\n", i);
	ft_printf("[ft_printf]test: |%-10hd|\n\n", i);
	printf("[printf]test:\t |%-10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%-10.12hd|\n\n", i);
	printf("[printf]test:\t |%0.42d|\n", i);
	ft_printf("[ft_printf]test: |%0.42d|\n\n", i);
	printf("[printf]test:\t |%+.10ld|\n", i);
	ft_printf("[ft_printf]test: |%+.10ld|\n\n", i);
	printf("[printf]test:\t |%-10ld|\n", i);
	ft_printf("[ft_printf]test: |%-10ld|\n\n", i);
	printf("[printf]test:\t |%010.7d|\n", i);
	ft_printf("[ft_printf]test: |%010.7d|\n\n", i);
	printf("[printf]test:\t |%0.12hd|\n", i);
	ft_printf("[ft_printf]test: |%0.12hd|\n\n", i);
	printf("[printf]test:\t |%+10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%+10.12hd|\n\n", i);
	printf("[printf]test:\t |%-4.8hd|\n", i);
	ft_printf("[ft_printf]test: |%-4.8hd|\n\n", i);
	printf("[printf]test:\t |%-10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%-10.12hd|\n\n", i);
	printf("[printf]test:\t |%-10d|\n", i);
	ft_printf("[ft_printf]test: |%-10d|\n\n", i);
	printf("[printf]test:\t |%-10.12hd|\n", i);
	ft_printf("[ft_printf]test: |%-10.12hd|\n\n", i);
	printf("\t\t\t\t-->[TEST %%D]<--\n\n");
	printf("[printf]test:\t |%D|\n", longg);
	ft_printf("[ft_printf]test: |%D|\n\n", longg);
	printf("[printf]test:\t |%D|\n", longgg);
	ft_printf("[ft_printf]test: |%D|\n\n", longgg);
	printf("[printf]test:\t |%14D|\n", longg);
	ft_printf("[ft_printf]test: |%14D|\n\n", longg);
	printf("[printf]test:\t |%14D|\n", longg);
	ft_printf("[ft_printf]test: |%14D|\n\n", longg);
	printf("[printf]test:\t |%.15D|\n", longg);
	ft_printf("[ft_printf]test: |%.15D|\n\n", longg);
	printf("[printf]test:\t |%.17D|\n", longgg);
	ft_printf("[ft_printf]test: |%.17D|\n\n", longgg);
	printf("[printf]test:\t |%21.17D|\n", longgg);
	ft_printf("[ft_printf]test: |%21.17D|\n\n", longgg);
	printf("[printf]test:\t |%-21.17D|\n", longgg);
	ft_printf("[ft_printf]test: |%-21.17D|\n\n", longgg);
	printf("[printf]test:\t |%.15D|\n", longgg);
	ft_printf("[ft_printf]test: |%.15D|\n\n", longgg);
	printf("\t\t\t\t-->[TEST %%p]<--\n\n");
	printf("[printf]test:\t |%p|\n", &test);
	ft_printf("[ft_printf]test: |%p|\n\n", &test);
	printf("[printf]test:\t |%p|\n", &s);
	ft_printf("[ft_printf]test: |%p|\n\n", &s);
	printf("[printf]test:\t |%p|\n", &addr);
	ft_printf("[ft_printf]test: |%p|\n\n", &addr);
	printf("[printf]test:\t |%p|\n", addr);
	ft_printf("[ft_printf]test: |%p|\n\n", addr);
	printf("[printf]test:\t |%p|\n", 0);
	ft_printf("[ft_printf]test: |%p|\n\n", 0);
	printf("[printf]test:\t |%p|\n", 0);
	ft_printf("[ft_printf]test: |%p|\n\n", 0);
	printf("[printf]test:\t |%15p|\n", &ooo);
	ft_printf("[ft_printf]test: |%15p|\n\n", &ooo);
	printf("[printf]test:\t |%14p|\n", &uuu);
	ft_printf("[ft_printf]test: |%14p|\n\n", &uuu);
	printf("[printf]test:\t |%.14p|\n", &uuu);
	ft_printf("[ft_printf]test: |%.14p|\n\n", &uuu);
	printf("[printf]test:\t |%20.14p|\n", &uuu);
	ft_printf("[ft_printf]test: |%20.14p|\n\n", &uuu);
	printf("[printf]test:\t |%16p|\n", 0);
	ft_printf("[ft_printf]test: |%16p|\n\n", 0);*/
	printf("\t\t\t\t-->[TEST %%C]<--\n\n");
	printf("[printf]test:\t |%C|\n", '4');
	ft_printf("[ft_printf]test: |%C|\n\n", '4');
	printf("[printf]test:\t |%C|\n", L'猫');
	ft_printf("[ft_printf]test: |%C|\n\n", L'猫');
	printf("[printf]test:\t |%C%C|\n", '4', '2');
	ft_printf("[ft_printf]test: |%C%C|\n\n", '4', '2');
/*	printf("\t\t\t\t-->[OTHER TEST]<--\n\n");
	printf("[printf]test:\t |%%|\n");
	ft_printf("[ft_printf]test: |%%|\n\n");
	printf("[printf]test:\t |%%poney|\n");
	ft_printf("[ft_printf]test: |%%poney|\n\n");
	printf("%da%db%dc\n", 1, 12, -2);
	ft_printf("%da%db%dc\n", 1, 12, -2);
	printf("negative: %d\n", -22);
	ft_printf("negative: %d\n", -22);
	printf("positive: %d\n", 42);
	ft_printf("positive: %d\n", 42);
	printf("printf = \t|%d|\n", NULL);
	ft_printf("ft_printf = \t|%d|\n", NULL);
	printf("printf = \t|%s|\n", NULL);
	ft_printf("ft_printf = \t|%s|\n", NULL);*/
	return (0);
}
