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

	printf(ANSI_BLUE " --------------- \n");
	printf("| ft_putchar_fd |\n");
	printf(" --------------- \n");
	printf(ANSI_MAGENTA "\\\\\\\\!!1337!!////");
	printf(ANSI_GREEN"\n");
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
	k++;
	printf(ANSI_RESET"\n");
	printf(ANSI_BLUE " --------------- \n");
	printf("| ft_putendl_fd |\n");
	printf(" --------------- \n");
	printf(ANSI_MAGENTA "%s", s1);
	printf(ANSI_GREEN"\n");
	ft_putendl_fd(s1, STDOUT);
	printf(ANSI_MAGENTA "%s", s2);
	printf(ANSI_GREEN"\n");
	ft_putendl_fd(s2, STDOUT);
	printf(ANSI_MAGENTA "%s", s3);
	printf(ANSI_GREEN"\n");
	ft_putendl_fd(s3, STDOUT);
	k++;
	printf(ANSI_RESET"\n");
	printf(ANSI_BLUE " --------------- \n");
	printf("| ft_putnbr_fd |\n");
	printf(" --------------- \n");
	n = 42;
	printf(ANSI_MAGENTA "\n%ld", n);
	printf(ANSI_GREEN"\n");
	ft_putnbr_fd(n, STDOUT);

	n = 33333;
	printf(ANSI_MAGENTA "\n%ld", n);
	printf(ANSI_GREEN"\n");
	ft_putnbr_fd(n, STDOUT);

	n = -1458746;
	printf(ANSI_MAGENTA "\n%ld", n);
	printf(ANSI_GREEN"\n");
	ft_putnbr_fd(n, STDOUT);

	n = 0;
	printf(ANSI_MAGENTA "\n%ld", n);
	printf(ANSI_GREEN"\n");
	ft_putnbr_fd(n, STDOUT);

	n = 2147483647;
	printf(ANSI_MAGENTA "\n%ld", n);
	printf(ANSI_GREEN"\n");
	ft_putnbr_fd(n, STDOUT);

	n = -2147483647;
	printf(ANSI_MAGENTA "\n%ld", n);
	printf(ANSI_GREEN"\n");
	ft_putnbr_fd(n, STDOUT);	
	k++;
	printf(ANSI_RESET"\n");
	printf(ANSI_BLUE " --------------- \n");
	printf("| ft_putstr_fd |\n");
	printf(" --------------- \n");
	printf(ANSI_MAGENTA "\n%s", s1);
	printf(ANSI_GREEN"\n");
	ft_putstr_fd(s1, STDOUT);
	printf(ANSI_MAGENTA "\n%s", s2);
	printf(ANSI_GREEN"\n");
	ft_putstr_fd(s2, STDOUT);
	printf(ANSI_MAGENTA "\n%s", s3);
	printf(ANSI_GREEN"\n");
	ft_putstr_fd(s3, STDOUT);
	k++;
	printf(ANSI_RESET"\n");

	printf(ANSI_YELLOW "TOTAL = %d functions\n", k);
	return (0);
}
