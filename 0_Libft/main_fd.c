#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
# define TRUE 1
# define FALSE 0
# define ANSI_RED "\x1b[31m" 
# define ANSI_GREEN "\x1b[32m" 
# define ANSI_YELLOW "\x1b[33m" 
# define ANSI_BLUE "\x1b[34m" 
# define ANSI_MAGENTA "\x1b[35m" 
# define ANSI_CYAN "\x1b[36m" 
# define ANSI_RESET  "\x1b[0m"
# define STDOUT 1




int main()
{
	int	k = 0;
	long int		n;
	char	s1[] = "1337bg";
	char	s2[] = "42 Network";
	char	s3[] = "Live the life to the fullest";
	char	s[] = " ---------------";
	char	s4[] = "| ft_putendl_fd |";
	char	s5[] = "| ft_putnbr_fd |";
	char	s6[] = "| ft_putstr_fd |";
	printf(ANSI_BLUE "\n --------------- \n");
	printf("| test_putchar_fd |\n");
	printf(" ----------------- \n");
	printf(ANSI_GREEN "\\\\\\\\!!1337!!////\n");
	ft_putchar_fd(' ', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('\n', STDOUT);
	ft_putchar_fd('|', STDOUT);
	ft_putchar_fd(' ', STDOUT);
	ft_putchar_fd('f', STDOUT);
	ft_putchar_fd('t', STDOUT);
	ft_putchar_fd('_', STDOUT);
	ft_putchar_fd('p', STDOUT);
	ft_putchar_fd('u', STDOUT);
	ft_putchar_fd('t', STDOUT);
	ft_putchar_fd('c', STDOUT);
	ft_putchar_fd('h', STDOUT);
	ft_putchar_fd('a', STDOUT);
	ft_putchar_fd('r', STDOUT);
	ft_putchar_fd('_', STDOUT);
	ft_putchar_fd('f', STDOUT);
	ft_putchar_fd('d', STDOUT);
	ft_putchar_fd(' ', STDOUT);
	ft_putchar_fd('|', STDOUT);
	ft_putchar_fd('\n', STDOUT);
	ft_putchar_fd(' ', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('-', STDOUT);
	ft_putchar_fd('\n', STDOUT);
	ft_putchar_fd('\\', STDOUT);
	ft_putchar_fd('\\', STDOUT);
	ft_putchar_fd('\\', STDOUT);
	ft_putchar_fd('\\', STDOUT);
	ft_putchar_fd('!', STDOUT);
	ft_putchar_fd('!', STDOUT);
	ft_putchar_fd('1', STDOUT);
	ft_putchar_fd('3', STDOUT);
	ft_putchar_fd('3', STDOUT);
	ft_putchar_fd('7', STDOUT);
	ft_putchar_fd('!', STDOUT);
	ft_putchar_fd('!', STDOUT);
	ft_putchar_fd('/', STDOUT);
	ft_putchar_fd('/', STDOUT);
	ft_putchar_fd('/', STDOUT);
	ft_putchar_fd('/', STDOUT);
	ft_putchar_fd('\n', STDOUT);
	ft_putchar_fd('\n', STDOUT);

	k++;
	printf(ANSI_RESET"\n");
	printf(ANSI_BLUE " ----------------- \n");
	printf("| test_putendl_fd |\n");
	printf(" ----------------- \n");
	ft_putendl_fd(s, STDOUT);
	ft_putendl_fd(s4, STDOUT);
	ft_putendl_fd(s, STDOUT);
	printf(ANSI_GREEN "%s\n", s1);
	ft_putendl_fd(s1, STDOUT);
	printf(ANSI_MAGENTA "%s\n", s2);
	ft_putendl_fd(s2, STDOUT);
	printf(ANSI_MAGENTA "%s\n", s3);
	ft_putendl_fd(s3, STDOUT);
	ft_putchar_fd('\n', STDOUT);

	k++;
	printf(ANSI_RESET"\n");
	printf(ANSI_BLUE " ----------------- \n");
	printf("| test_putnbr_fd |\n");
	printf(" ---------------- \n");
	ft_putendl_fd(s, STDOUT);
	ft_putendl_fd(s5, STDOUT);
	ft_putendl_fd(s, STDOUT);

	n = 42;
	printf(ANSI_MAGENTA "\n%ld", n);
	ft_putnbr_fd(n, STDOUT);
	ft_putchar_fd('\n', STDOUT);

	n = 33333;
	printf(ANSI_MAGENTA "\n%ld", n);
	ft_putnbr_fd(n, STDOUT);
	ft_putchar_fd('\n', STDOUT);

	n = -1458746;
	printf(ANSI_MAGENTA "\n%ld", n);
	ft_putnbr_fd(n, STDOUT);
	ft_putchar_fd('\n', STDOUT);

	n = 0;
	printf(ANSI_MAGENTA "\n%ld", n);
	ft_putnbr_fd(n, STDOUT);
	ft_putchar_fd('\n', STDOUT);

	n = 2147483647;
	printf(ANSI_MAGENTA "\n%ld", n);
	ft_putnbr_fd(n, STDOUT);
	ft_putchar_fd('\n', STDOUT);

	n = -2147483647;
	printf(ANSI_MAGENTA "\n%ld\n", n);
	ft_putnbr_fd(n, STDOUT);	
	ft_putchar_fd('\n', STDOUT);
	ft_putchar_fd('\n', STDOUT);

	k++;
	printf(ANSI_RESET"\n");
	printf(ANSI_BLUE " ----------------- \n");
	printf("| test_putstr_fd |\n");
	printf(" ---------------- \n");
	ft_putendl_fd(s, STDOUT);
	ft_putendl_fd(s6, STDOUT);
	ft_putendl_fd(s, STDOUT);
	printf(ANSI_MAGENTA "\n%s", s1);
	ft_putstr_fd(s1, STDOUT);
	ft_putchar_fd('\n', STDOUT);

	printf(ANSI_MAGENTA "\n%s", s2);
	ft_putstr_fd(s2, STDOUT);
	ft_putchar_fd('\n', STDOUT);

	printf(ANSI_MAGENTA "\n%s", s3);
	ft_putstr_fd(s3, STDOUT);
	ft_putchar_fd('\n', STDOUT);

	k++;
	printf(ANSI_RESET"\n");
	printf(ANSI_YELLOW "\nTOTAL = %d functions\n", k);
	return (0);
}
