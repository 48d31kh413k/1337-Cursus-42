#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
# define TRUE 1
# define FALSE 0
/* static char	bzero_test(size_t len)
{
	void	*a;
	void	*b;
	int		diff;

	a = malloc(sizeof(unsigned char) * (len));
	if (a == NULL)
		return ('\0');
	b = malloc(sizeof(unsigned char) * (len));
	if (b == NULL)
		return ('\0');

	ft_bzero(a, len);
	bzero(b, len);
	diff = memcmp(a, b, len);
	free(a);
	free(b);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}
*/
static char	atoi_test(const char *str)
{
	if (ft_atoi(str) == atoi(str))
		return ('Y');
	else
		return ('N');
}

static void	my_free(void *a, void *b)
{
	free(a);
	free(b);
}

static char	calloc_test(size_t count, size_t size)
{
	int		diff;
	void	*a;
	void	*b;

	a = ft_calloc(count, size);
	b = calloc(count, size);
	diff = memcmp(a, b, count * size);
	my_free(a, b);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

static char	test_alnum(int flag, int c)
{
	char	OK;
	char	NG;

	OK = 'Y';
	NG = 'N';
	if (flag == TRUE)
	{
		if (ft_isalnum(c))
			return (OK);
		else
			return (NG);
	}
	else
	{
		if (!ft_isalnum(c))
			return (OK);
		else
			return (NG);
	}
}

static char	isalpha_test(int flag, int c)
{
	char	OK;
	char	NG;

	OK = 'Y';
	NG = 'N';
	if (flag == TRUE)
	{
		if (ft_isalpha(c))
			return (OK);
		else
			return (NG);
	}
	else
	{
		if (!ft_isalpha(c))
			return (OK);
		else
			return (NG);
	}
}

static char	isascii_test(int flag, int c)
{
	char	OK;
	char	NG;

	OK = 'Y';
	NG = 'N';
	if (flag == TRUE)
	{
		if (ft_isascii(c))
			return (OK);
		else
			return (NG);
	}
	else
	{
		if (!ft_isascii(c))
			return (OK);
		else
			return (NG);
	}
}

static char	isdigit_test(int flag, int c)
{
	char	OK;
	char	NG;

	OK = 'Y';
	NG = 'N';
	if (flag == TRUE)
	{
		if (ft_isdigit(c))
			return (OK);
		else
			return (NG);
	}
	else
	{
		if (!ft_isdigit(c))
			return (OK);
		else
			return (NG);
	}
}

static char	isprint_test(int flag, int c)
{
	char	OK;
	char	NG;

	OK = 'Y';
	NG = 'N';
	if (flag == TRUE)
	{
		if (ft_isprint(c))
			return (OK);
		else
			return (NG);
	}
	else
	{
		if (!ft_isprint(c))
			return (OK);
		else
			return (NG);
	}
}

int main()
{
	char	*test_atoi;
	//char	*test_bzero;
	char	*test_calloc;
	char	*alnum_test;
	char	*test_isalpha;
	char	*test_isascii;
	char	*test_isdigit;
	char	*test_isprint;
	int	i;

	test_atoi = (char *)malloc(sizeof(char) * 19);
	//test_bzero = (char *)malloc(sizeof(char) * 4);
	alnum_test = (char *)malloc(sizeof(char) * 10);
	test_calloc = (char *)malloc(sizeof(char) * 4);
	test_isalpha = (char *)malloc(sizeof(char) * 6);
	test_isascii = (char *)malloc(sizeof(char) * 8);
	test_isdigit = (char *)malloc(sizeof(char) * 6);
	test_isprint = (char *)malloc(sizeof(char) * 11);
	test_atoi[0] = atoi_test("42");
	test_atoi[1] = atoi_test("1289439");
	test_atoi[2] = atoi_test("-66847");
	test_atoi[3] = atoi_test("2147483647");
	test_atoi[4] = atoi_test("-2147483648");
	test_atoi[5] = atoi_test("0");
	test_atoi[6] = atoi_test("    	42");
	test_atoi[7] = atoi_test("  1289439");
	test_atoi[8] = atoi_test("      		-66847");
	test_atoi[9] = atoi_test("	   	2147483647");
	test_atoi[10] = atoi_test("		    -2147483648");
	test_atoi[11] = atoi_test("  		  	0");
	test_atoi[12] = atoi_test("    	+42");
	test_atoi[13] = atoi_test("  +--1289439");
	test_atoi[14] = atoi_test("      		+-66847");
	test_atoi[15] = atoi_test("	   	+2147483647");
	test_atoi[16] = atoi_test("		    +-2147483648");
	test_atoi[17] = atoi_test("  		  	+0");
	test_atoi[18] = '\0';
	/* test_bzero[0] = bzero_test(10);
	test_bzero[1] = bzero_test(42);
	test_bzero[2] = bzero_test(0);
	test_bzero[3] = '\0'; */
	test_calloc[0] = calloc_test(100, sizeof(int));
	test_calloc[1] = calloc_test(42, sizeof(unsigned char));
	test_calloc[2] = calloc_test(333, sizeof(long));
	test_calloc[3] = '\0';
	alnum_test[0] = test_alnum(TRUE, '1');
	alnum_test[1] = test_alnum(TRUE, '0');
	alnum_test[2] = test_alnum(TRUE, '7');
	alnum_test[3] = test_alnum(TRUE, 'x');
	alnum_test[4] = test_alnum(TRUE, 'A');
	alnum_test[5] = test_alnum(TRUE, 'r');
	alnum_test[6] = test_alnum(TRUE, 'T');
	alnum_test[7] = test_alnum(FALSE, '@');
	alnum_test[8] = test_alnum(FALSE, '!');
	alnum_test[9] = test_alnum(FALSE, ' ');
	alnum_test[10] = '\0';
	test_isalpha[0] = isalpha_test(TRUE, 'a');
	test_isalpha[1] = isalpha_test(TRUE, 'Y');
	test_isalpha[2] = isalpha_test(TRUE, 'Z');
	test_isalpha[3] = isalpha_test(FALSE, '!');
	test_isalpha[4] = isalpha_test(FALSE, '9');
	test_isalpha[5] = '\0';
	test_isascii[0] = isascii_test(TRUE, 'a');
	test_isascii[1] = isascii_test(TRUE, 'Y');
	test_isascii[2] = isascii_test(TRUE, 'Z');
	test_isascii[3] = isascii_test(TRUE, '!');
	test_isascii[4] = isascii_test(TRUE, '9');
	test_isascii[5] = isascii_test(FALSE, -1);
	test_isascii[6] = isascii_test(FALSE, 128);
	test_isascii[7] = '\0';
	test_isdigit[0] = isdigit_test(TRUE, '1');
	test_isdigit[1] = isdigit_test(TRUE, '0');
	test_isdigit[2] = isdigit_test(TRUE, '7');
	test_isdigit[3] = isdigit_test(FALSE, '#');
	test_isdigit[4] = isdigit_test(FALSE, 'a');
	test_isdigit[5] = '\0';
	test_isprint[0] = isprint_test(TRUE, '1');
	test_isprint[1] = isprint_test(TRUE, '0');
	test_isprint[2] = isprint_test(TRUE, '7');
	test_isprint[3] = isprint_test(TRUE, '#');
	test_isprint[4] = isprint_test(TRUE, 'a');
	test_isprint[5] = isprint_test(TRUE, 'T');
	test_isprint[6] = isprint_test(FALSE, 127);
	test_isprint[7] = isprint_test(FALSE, 23);
	test_isprint[8] = isprint_test(FALSE, 0);
	test_isprint[9] = isprint_test(FALSE, 128);
	test_isprint[10] = '\0';
	printf("\n********** LIBFT TESTER **********\n\n");
	printf(" --------- \n");
	printf("| ft_atoi |\n");
	printf(" --------- \n");
	for(i = 0; i < 18; ++i)
		printf("test [%d] = %c \n", i, test_atoi[i]);
	printf("\n");	
	/*printf("ft_bzero \n");
	for(i = 0; i < 3; ++i)
		printf("test [%d] = %c \n", i , test_bzero[i]); */
	printf(" ----------- \n");
	printf("| ft_calloc |\n");
	printf(" ----------- \n");
	for(i = 0; i < 3; ++i)
		printf("test [%d] = %c \n", i , test_calloc[i]);
	printf("\n");
	printf(" ------------ \n");
	printf("| ft_isalnum |\n");
	printf(" ------------ \n");
	for( i = 0; i < 10; ++i)
		printf("test [%d] = %c \n", i , alnum_test[i]);
	printf("\n");
	printf(" ------------ \n");
	printf("| ft_islapha |\n");
	printf(" ------------\n");
	for( i = 0; i < 5; ++i)
		printf("test [%d] = %c \n", i , test_isalpha[i]);
	printf("\n");
	printf(" ------------ \n");
	printf("| ft_isascii |\n");
	printf(" ------------ \n");
	for(i = 0; i < 7; ++i)
		printf("test [%d] = %c \n", i, test_isascii[i]);
	printf("\n");
	printf(" ------------ \n");
	printf("| ft_isdigit |\n");
	printf(" ------------ \n");
	for(i = 0; i < 5; ++i)
		printf("test [%d] = %c \n", i, test_isdigit[i]);
	printf("\n");
	printf(" ------------ \n");
	printf("| ft_isprint |\n");
	printf(" ------------ \n");
	for(i = 0; i < 9; ++i)
		printf("test [%d] = %c \n", i, test_isprint[i]);
	
	return (0);
}
