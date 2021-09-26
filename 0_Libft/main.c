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

char	itoa_test(int n, const char *expected)
{
	char	*created;
	int		diff;

	created = ft_itoa(n);
	diff = 0;
	if (!(created == NULL && expected == NULL))
		diff = strcmp(created, expected);
	free(created);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

static char	memchr_test(void *s, int c, size_t n)
{
	if (ft_memchr(s, c, n) == memchr(s, c, n))
		return ('Y');
	else
		return ('N');
}
int j = 0;
static char	memcmp_test(const void *s1, const void *s2, size_t n)
{
	int c = ft_memcmp(s1, s2, n);
    int e = memcmp(s1, s2, n);
    if ((c < 0 && e < 0) || (c > 0 && e >0) || (c == 0 && e == 0))
        return ('Y');
    else
        return ('N');
}

static char	memcpy_test(const void *src, size_t n)
{
	void	*a;
	void	*b;
	int		diff;

	a = malloc(sizeof(unsigned char) * n);
	if (a == NULL)
		return ('\0');
	b = malloc(sizeof(unsigned char) * n);
	if (b == NULL)
		return ('\0');

	ft_memcpy(a, src, n);
	memcpy(b, src, n);
	diff = memcmp(a, b, n);
	free(a);
	free(b);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}


static char	memmove_test(const void *src, size_t n)
{
	void	*a;
	void	*b;
	int		diff;

	a = malloc(sizeof(unsigned char) * n);
	if (a == NULL)
		return ('\0');
	b = malloc(sizeof(unsigned char) * n);
	if (b == NULL)
		return ('\0');

	ft_memmove(a, src, n);
	memmove(b, src, n);
	diff = memcmp(a, b, n);
	free(a);
	free(b);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

static char	memmove_test_overrap(const void *src, size_t n, int start, const void *expect)
{
	int		diff;
	void	*tmp;

	tmp = (void *)src;
	ft_memmove(tmp + start, src, n);
	diff = memcmp(src, expect, n);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

static char memmove_test_same(void)
{
	char	str[] = "same";
	char	*ret;

	ret = ft_memmove(str, str, 1);
	if (ret == str)
		return ('Y');
	else
		return ('N');
}

static char memmove_test_null(void)
{
	char	*ret;

	ret = ft_memmove(NULL, NULL, 1);
	if (ret == NULL)
		return ('Y');
	else
		return ('N');
}

static char	memset_test(int c, size_t len)
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

	ft_memset(a, c, len);
	memset(b, c, len);
	diff = memcmp(a, b, len);
	free(a);
	free(b);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
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
	char	*test_itoa;
	char	*test_memchr;
	char	*test_memcmp;
	char	*test_memcpy;
	char	*test_memmove;
	char	*test_memset;
	char	*str;
	char	s1[] = "Born 2 code";
	char	s2[] = "Future is Loading";
	char	s3[] = "Lorem ipsum dolor sit amet";
	char	s4[] = "Aenean porttitor sit amet mauris quis sodales.";
	char	s5[] = "Aenean eleifend nibh ac dui elementum consectetur.";
	int	array[] = {33, 42, 100, 9999, 1031, -339382, 222222222};
	int	array1[] = {22, -5736, 8873, 283790, -44837, 0, 5574, 42};
	int	array2[] = {22, -5736, 8873, 283790, -44837, 0, 5574, 42};
	int	array3[] = {3345, -99182, 67638, 3345, -1111, 67839};
	int	array4[] = {3345, -99182, 67638, 2222, 37, 9802};
	int		array5[] = {33, 42, 100, 9999, 1031, -339382, 222222222};
	int	num;
	int	num1 = 42;
	int	num2 = 42;
	int	i;
	int	j = 0;
	int	k = 0;

	test_atoi = (char *)malloc(sizeof(char) * 19);
	//test_bzero = (char *)malloc(sizeof(char) * 4);
	alnum_test = (char *)malloc(sizeof(char) * 10);
	test_calloc = (char *)malloc(sizeof(char) * 4);
	test_isalpha = (char *)malloc(sizeof(char) * 6);
	test_isascii = (char *)malloc(sizeof(char) * 8);
	test_isdigit = (char *)malloc(sizeof(char) * 6);
	test_isprint = (char *)malloc(sizeof(char) * 11);
	test_itoa = (char *)malloc(sizeof(char) * 7);
	test_memchr = (char *)malloc(sizeof(char) * 9);
	test_memcmp = (char *)malloc(sizeof(char) * 18);
	test_memcpy = (char *)malloc(sizeof(char) * 5);
	test_memmove = (char *)malloc(sizeof(char) * 14);
	test_memset = (char *)malloc(sizeof(char) * 4);
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
	test_itoa[0] = itoa_test(42, "42");
	test_itoa[1] = itoa_test(374621, "374621");
	test_itoa[2] = itoa_test(-223876, "-223876");
	test_itoa[3] = itoa_test(2147483647, "2147483647");
	test_itoa[4] = itoa_test(-2147483647, "-2147483647");
	test_itoa[5] = itoa_test(0, "0");
	test_itoa[6] = '\0';
	test_memchr[0] = memchr_test(s1, 'B', sizeof(s1));
	test_memchr[1] = memchr_test(s1, '2', 6);
	test_memchr[2] = memchr_test(s1, 'o', 100);
	test_memchr[3] = memchr_test(s1, 'd', 0);
	test_memchr[4] = memchr_test(s1, '#', 200);
	test_memchr[5] = memchr_test(s2, 'k', 29);
	test_memchr[6] = memchr_test(s2, 'i', 17);
	test_memchr[7] = memchr_test(s2, '*', 33);
	test_memchr[8] = '\0';
	test_memcmp[0] = memcmp_test(s3, s3, sizeof(s3));
	test_memcmp[1] = memcmp_test(s3, s3, 100);
	test_memcmp[2] = memcmp_test(s3, s3, 0);
	test_memcmp[3] = memcmp_test(s4, s3, 3);
	test_memcmp[4] = memcmp_test(s4, s5, sizeof(s5));
	test_memcmp[5] = memcmp_test(s4, s5, 5);
	test_memcmp[6] = memcmp_test(s4, s5, 8);
	test_memcmp[7] = memcmp_test(s4, s5, 9);
	test_memcmp[8] = memcmp_test(s4, s5, 0);
	test_memcmp[9] = memcmp_test("simply", "simple", 6);
	test_memcmp[10] = memcmp_test("1337: Benguerir", "1337: Khouribga", 11);
	test_memcmp[11] = memcmp_test("42 Network", "42 School", 15);
	test_memcmp[12] = memcmp_test("42 FUTURE IS LOADING", "42 BORN2CODE", 100);
	test_memcmp[13] = memcmp_test(&num1, &num2, sizeof(num1));
	num1 = 42;
	num2 = 33;
	test_memcmp[14] = memcmp_test(&num1, &num2, sizeof(num1));
	num1 = -687394;
	num2 = 857768;;
	test_memcmp[15] = memcmp_test(&num1, &num2, sizeof(num1));
	test_memcmp[16] = memcmp_test(array1, array2, sizeof(array1));
	test_memcmp[17] = memcmp_test(array3, array4, sizeof(array3));
	test_memcmp[18] = '\0';
	str = strdup("Simply the best");
	test_memcpy[0] = memcpy_test(str, strlen(str) + 1);
	free(str);
	str = strdup("");
	test_memcpy[1] = memcpy_test(str, strlen(str) + 1);
	free(str);
	num = 42;
	test_memcpy[2] = memcpy_test(&num, sizeof(num));
	num = 0;
	test_memcpy[3] = memcpy_test(&num, sizeof(num));
	test_memcpy[4] = memcpy_test(&array5, sizeof(array5)/sizeof(array5[0]));
	test_memcpy[5] = '\0';
	str = strdup("Time is money");
	test_memmove[0] = memmove_test(str, strlen(str) + 1);
	free(str);
	str = strdup("Live the life to the fullest");
	test_memmove[1] = memmove_test(str, strlen(str) + 1);
	free(str);
	str = strdup("Ma  	r vi    n 		!!");
	test_memmove[2] = memmove_test(str, strlen(str) + 1);
	free(str);
	str = strdup("0123456789");
	test_memmove[3] = memmove_test(str, 5);
	free(str);
	str = strdup("0123456789");
	test_memmove[4] = memmove_test(str, 0);
	free(str);	
	num = 42;
	test_memmove[5] = memmove_test(&num, sizeof(num));
	num = 99999999;
	test_memmove[6] = memmove_test(&num, sizeof(num));
	num = -274672;
	test_memmove[7] = memmove_test(&num, sizeof(num));
	test_memmove[8] = memmove_test(&array, sizeof(array));	
	str = strdup("01234567890123456789");
	test_memmove[9] = memmove_test_overrap(str, 5, 3, "01201234890123456789");
	free(str);
	str = strdup("01234567890123456789");
	test_memmove[10] = memmove_test_overrap(str, 7, 5, "01234012345623456789");
	free(str);
	test_memmove[11] = memmove_test_same();
	test_memmove[12] = memmove_test_null();
	test_memmove[13] = '\0';
	test_memset[0] = memset_test('@', 10);
	test_memset[1] = memset_test('!', 20);
	test_memset[2] = memset_test('0', 0);
	test_memset[3] = '\0';
	printf(ANSI_BLUE "\n********** LIBFT TESTER **********\n\n");
	printf(" --------- \n");
	printf("| ft_atoi |\n");
	printf(" --------- \n");
	for(i = 0; i < 18; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_atoi[i]);
	if (test_atoi[i >= 0 && i < 18] == 'Y')
	{
		printf(ANSI_GREEN "ft_atoi : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_atoi : KO\n");
	k++;
	printf("\n");	
	/*	j++;
	 printf("ft_bzero \n");
	for(i = 0; i < 3; ++i)
		printf("test [%d] = %c \n", i , test_bzero[i]); */
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_calloc |\n");
	printf(" ----------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i , test_calloc[i]);
	if (test_calloc[i >= 0 && i < 3] == 'Y')
	{
		printf(ANSI_GREEN "ft_calloc : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_calloc : KO\n");
	k++;
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_isalnum |\n");
	printf(" ------------ \n");
	for( i = 0; i < 10; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i , alnum_test[i]);
	if (alnum_test[i >= 0 && i < 10] == 'Y')
	{
		printf(ANSI_GREEN "ft_isalnum : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_isalnum : KO\n");
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_islapha |\n");
	printf(" ------------\n");
	for( i = 0; i < 5; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i , test_isalpha[i]);
	if (test_isalpha[i >= 0 && i < 5] == 'Y')
	{
		printf(ANSI_GREEN "ft_isalpha : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_isalpa : KO\n");
	k++;
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_isascii |\n");
	printf(" ------------ \n");
	for(i = 0; i < 7; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_isascii[i]);
	if (test_isascii[i >= 0 && i < 7] == 'Y')
	{
		printf(ANSI_GREEN "ft_isascii : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_isascii : KO\n");
	k++;
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_isdigit |\n");
	printf(" ------------ \n");
	for(i = 0; i < 5; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_isdigit[i]);
	if (test_isdigit[i >= 0 && i < 5] == 'Y')
	{
		printf(ANSI_GREEN "ft_isdigit : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_isdigit : KO\n");
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_isprint |\n");
	printf(" ------------ \n");
	for(i = 0; i < 9; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_isprint[i]);
	if (test_isprint[i >= 0 && i < 9] == 'Y')
	{
		printf(ANSI_GREEN "ft_isprint : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_isprint : KO\n");
	k++;		
	printf("\n");
	printf(ANSI_BLUE " --------- \n");
	printf("| ft_itoa |\n");
	printf(" --------- \n");
	for(i = 0; i < 6; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_itoa[i]);
	if (test_itoa[i >= 0 && i < 6] == 'Y')
	{
		printf(ANSI_GREEN "ft_isitoa : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_isitoa : KO\n");
	k++;		
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_memchr |\n");
	printf(" ----------- \n");
	for(i = 0; i < 8; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_memchr[i]);
	if (test_memchr[i >= 0 && i < 8] == 'Y')
	{
		printf(ANSI_GREEN "ft_ismemchr : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_ismemchr : KO\n");
	k++;
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_memcmp |\n");
	printf(" ----------- \n");
	for(i = 0; i < 18; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_memcmp[i]);
	if (test_memcmp[i >= 0 && i < 18] == 'Y')
	{
		printf(ANSI_GREEN "ft_ismemcmp : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_ismemcmp : KO\n");
	k++;
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_memcpy |\n");
	printf(" ----------- \n");
	for(i = 0; i < 5; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_memcpy[i]);
	if (test_memcpy[i >= 0 && i < 5] == 'Y')
	{
		printf(ANSI_GREEN "ft_ismemcpy : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_ismemcpy : KO\n");
	k++;
	printf("\n");	
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_memmove |\n");
	printf(" ------------ \n");
	for(i = 0; i < 13; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_memmove[i]);
	if (test_memmove[i >= 0 && i < 13] == 'Y')
	{
		printf(ANSI_GREEN "ft_ismemmove : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_ismemmove : KO\n");
	k++;	
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_memset |\n");
	printf(" ----------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i , test_memset[i]);
	if (test_calloc[i >= 0 && i < 3] == 'Y')
	{
		printf(ANSI_GREEN "ft_memset : OK\n");
		j++;
	}
	else
		printf(ANSI_RED "ft_memset : KO\n");
	k++;
	printf("\n");
	/* printf(ANSI_BLUE " --------------- \n");
	printf("| ft_putchar_fd |\n");
	printf(" --------------- \n");
	printf(ANSI_MAGENTA "\\\\\\\\!!1337!!////\n");
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
	j++;
	k++;
	printf("\n"); */
	

	if (j == k)
		printf(ANSI_GREEN "LIBFT ==> OK\n");
	else
	 	printf(ANSI_RED "LIBFT ==> KO\n Functions = %d/%d\n", j, k);
	printf(" %d functions", k);
	return (0);
}
