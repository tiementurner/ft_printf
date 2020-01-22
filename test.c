/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 16:20:48 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/22 12:29:04 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// int	main(void)
// {
// 	int a;
// //	static char *s_hidden = "hi low\0don't print me lol\0";
// 	a = 1;
// //	ft_printf("%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
// //	ft_printf("%");
// 	ft_printf("ft: %5.2d\n", 12321312);
// 	printf("pf: %5.2d\n", 12321312);
// 	ft_printf("ft: %5.2x\n", 123124);
// 	printf("pf: %5.2x\n", 123124);
// 	ft_printf("ft: %5.2u\n", 4324234);
// 	printf("pf: %5.2u\n", 4324234);
// 	ft_printf("ft: %5p\n", "123");
// 	printf("pf: %5p\n", "123");
// 	ft_printf("ft: %p\n", NULL);
// 	printf("pf: %p\n", NULL);
// 	ft_printf("ft: %-05%\n");
// 	printf("pf: %-05%\n");
// 	// while (1)
// 	// {
// 	// 	a++;
// 	// }
// }
#include <limits.h>
#include <locale.h>
#include <math.h>
int	main(void)
{

	//ft_printf("%.7s", "hello");
	char		s1[] = "Lookie";
	char		s2[] = "Here";
	char		s3[] = "Wow this is a really big string wowow";
	char		s4[] = "Old man";
	char		*nlptr = NULL;


	char		c1 = '&';
	char		c2 = 'D';
	char		c3 = '7';
	char		c4 = 48;

	int			i1 = 8902;
	int			i2 = 97;

	unsigned	o1 = 11;
	unsigned	o2 = 67;
	unsigned	o3 = 88;
	unsigned	o4 = 111;

	unsigned	x1 = 15;
	unsigned	X1 = 15;
	unsigned	x2 = 23;
	unsigned	X2 = 23;
	unsigned	x3 = 64;
	unsigned	X3 = 64;
	unsigned	x4 = 128;
	unsigned	X4 = 128;

	int			H = 7;


	ft_printf("\033[0;31m");
	ft_printf("Strings: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-8s$ %7s$ %.8s$ %.*s$", s1, s2, s3, H, s4));
	printf("<- %i\n\n", printf("%-8s$ %7s$ %.8s$ %.*s$", s1, s2, s3, H, s4));
	ft_printf("\033[0m");

	ft_printf("\033[1;31m");
	ft_printf("Strings: -010Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-10s$ %*s$ %-8.7s$ %s$", s1, -10, s2, s3, s4));
	printf("<- %i \n\n", printf("%-10s$ %*s$ %-8.7s$ %s$", s1, -10, s2, s3, s4));
	ft_printf("\033[0m");

	ft_printf("\033[0;32m");
	ft_printf("Chars: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%7c$ %-7c$ %8c$ %*c$", c1, c2, c3, 0, c4));
	printf("<- %i \n\n", printf("%7c$ %-7c$ %8c$ %*c$", c1, c2, c3, 0, c4));
	ft_printf("\033[0m");

	ft_printf("\033[1;32m");
	ft_printf("Chars: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-c$ %c$ %-8c$ %*c$", c1, c2, c3, -1, c4));
	printf("<- %i \n\n", printf("%-c$ %c$ %-8c$ %*c$", c1, c2, c3, -1, c4));
	ft_printf("\033[0m");

	ft_printf("\033[0;33m");
	ft_printf("Integers: .6(-3) +.7(-446) 07(-54) +5(432)\n");
	ft_printf("<- %i \n", ft_printf("%.6i, |%+.7i, |%07i, |%+5i", -3, -446, -54, 432));
	printf("<- %i \n\n", printf("%.6i, |%.7i, |%07i, |%+5i", -3, -446, -54, 432));
	ft_printf("\033[0m");

	ft_printf("\033[1;33m");
	printf("Integers: +08.6, +8.6, +07,       +7,     + 7,     +.7,      +0.7:\n");
	ft_printf("<- %i \n", ft_printf("%+08.6d , |%+8.6d, |%+07d, |%+7d, |% 7d, |%+.7d, |%+0.7d", 32, 32, 32, 32, -32, -32, -32));
	printf("<- %i \n\n", printf("%+08.6d , |%+8.6d, |%+07d, |%+7d, |% 7d, |%+.7d, |%+0.7d", 32, 32, 32, 32, -32, -32, -32));
	ft_printf("\033[0m");

	ft_printf("\033[0;34m");
	ft_printf("Unsigned ints: -3u, 07u, .8u, .*u:\n");
	ft_printf("<- %i \n", ft_printf("%-3u$ %07u$ %.8u$ %.*u$", o1, o2, o3, 5, o4));
	printf("<- %i \n\n", printf("%-3u$ %07u$ %.8u$ %.*u$", o1, o2, o3, 5, o4));
	ft_printf("\033[0m");

	ft_printf("\033[1;34m");
	ft_printf("Unsigned ints: -3u, 0u, -8.7u, #u\n");
	ft_printf("<- %i\n", ft_printf("%-3u$ %0u$ %-8.7u$ %u$", o1, o2, o3, o4));
	printf("<- %i \n\n", printf("%-3u$ %0u$ %-8.7u$ %u$", o1, o2, o3, o4));
	ft_printf("\033[0m");

	ft_printf("\033[0;35m");
	ft_printf("hexadecimals: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%3x$ %07x$ %.8x$ %.*x$", x1, x2, x3, 11, x4));
	printf("<- %i \n\n", printf("%3x$ %07x$ %.8x$ %.*x$", x1, x2, x3, 11, x4));
	ft_printf("\033[0m");

	ft_printf("\033[1;35m");
	ft_printf("hexadecimals: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-3x$ %0x$ %-8.7x$ %.0x$", x1, x2, (unsigned)ULONG_MAX, x4));
	printf("<- %i \n\n", printf("%-3x$ %0x$ %-8.7x$ %.0x$", x1, x2, (unsigned)ULONG_MAX, x4));
	ft_printf("\033[0m");

	ft_printf("\033[0;36m");
	ft_printf("HEXADECIMALS: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-3X$ %07X$ %.8X$ %.*X$", X1, X2, X3, 8, X4));
	printf("<- %i \n\n", printf("%-3X$ %07X$ %.8X$ %.*X$", X1, X2, X3, 8, X4));
	ft_printf("\033[0m");

	ft_printf("\033[1;36m");
	ft_printf("HEXADECIMALS: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	printf("<- %i \n\n", printf("%-X$ %0X$ %-8.7X$ %#X$", (unsigned)ULONG_MAX, X2, X3, X4));
	ft_printf("\033[0m");

	ft_printf("\033[0;31m");
	ft_printf("Pointer addresses:\n");
	ft_printf("<- %i \n", ft_printf("%-8p$", (void*)ULONG_MAX));
	printf("<- %i \n\n", printf("%-8p$", (void*)ULONG_MAX));
	ft_printf("\033[0m");

	ft_printf("\033[1;31m");
	ft_printf("Simply check each conversion without any flags \n\n");
	ft_printf("<- %i \n", ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %% ", c1, s1, &s1, i1, i2, o1, x1, X1));
	printf("<- %i \n\n", printf("%c, %s, %p, %d, %i, %u, %x, %X, %% ", c1, s1, &s1, i1, i2, o1, x1, X1));

	ft_printf("\033[0;32m");
	printf("Try special case like 0 or smallest int or empty string or null pointer\n");
	ft_printf("<- %i \n", ft_printf("%i, %i, %s, %p $and some final words after the last conversion$", 0, -2147483647, "", &nlptr));
	printf("<- %i \n\n\n", printf("%i, %i, %s, %p $and some final words after the last conversion$", 0, -2147483647, "", &nlptr));

	ft_printf("\033[1;32m");
	ft_printf("\033[0;33m");

	ft_printf("Simple Flags Management:\n");
	ft_printf("<- %i \n", ft_printf("%7s, %7s, %7s, %*s$", s1, s2, s3, 7, s4));
	printf("<- %i \n\n", printf("%7s, %7s, %7s, %*s$", s1, s2, s3, 7, s4));
	ft_printf("\033[1;33m");
	ft_printf("<- %i \n", ft_printf("%-7s, %-7s, %-7s, %-8s$", s1, s2, s3, s4));
	printf("<- %i \n\n", printf("%-7s, %-7s, %-7s, %-8s$", s1, s2, s3, s4));
	ft_printf("\033[0;34m");
	ft_printf("%i \n", ft_printf("%7s, %7s, %7s, %7s$", s1, s2, s3, s4));
	printf("%i \n\n", printf("%7s, %7s, %7s, %7s$", s1, s2, s3, s4));
	ft_printf("\033[1;34m");
	ft_printf("<- %i \n", ft_printf("%6.8s, %8.6s, %.5s, %.23s$", s1, s2, s3, s4));
	printf("<- %i \n\n\n", printf("%6.8s, %8.6s, %.5s, %.23s$", s1, s2, s3, s4));
	ft_printf("\033[0m");

	ft_printf("\033[0;35m");
	ft_printf("Advanced Flags Management:\n");
	ft_printf("<- %i \n", ft_printf("%*s, %*s, %*s, %*s$", -1, s1, 0, s2, 9, s3, 7, s4));
	printf("<- %i \n\n", printf("%*s, %*s, %*s, %*s$", -1, s1, 0, s2, 9, s3, 7, s4));
	ft_printf("\033[1;35m");
	ft_printf("<- %i \n", ft_printf("Precision *: %.*s, %.*s, %.*s,%*.*s", -1, s1, 0, s2, 23, s3, 8, 7, s4));
	printf("<- %i \n\n", printf("Precision *: %.*s, %.*s, %.*s,%*.*s", -1, s1, 0, s2, 23, s3, 8, 7, s4));
	ft_printf("\033[0;36m");
	ft_printf("<- %i \n", ft_printf("Duplicate flags: %---i, %---9s", -20, s2));
  	printf("<- %i \n\n", printf("Duplicate flags: %---i, %---9s", -20, s2));


	ft_printf("\033[1;31m");
	ft_printf("R ");
	ft_printf("\033[1;32m");
	ft_printf("A ");
	ft_printf("\033[1;33m");
	ft_printf("I ");
	ft_printf("\033[1;34m");
	ft_printf("N ");
	ft_printf("\033[1;35m");
	ft_printf("B ");
	ft_printf("\033[1;36m");
	ft_printf("O ");
	ft_printf("\033[1;31m");
	ft_printf("W ");
	ft_printf("\033[1;32m");
	ft_printf("!\n");
	 while (1) {}

	return 0;
}