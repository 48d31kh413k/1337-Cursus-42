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

void ft_bzero1(void * s, size_t n)
{
  char * c = s; // Can't work with void *s directly.
  size_t i;
  for (i = 0; i < n; ++i)
    c[i] = '\0';
}
static char	bzero_test(size_t len)
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
	ft_bzero1(b, len);
	diff = memcmp(a, b, len);
	free(a);
	free(b);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

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

static char	split_test(char const *s, char c, char *expected[])
{
	char	**created;
	int		diff;
	int		i;

	created = ft_split(s, c);
	diff = 0;
	i = 0;
	while (created[i] != NULL || expected[i] != NULL)
	{
		diff = strcmp(created[i], expected[i]);
		if (diff != 0)
			return ('N');
		i++;
	}
	return ('Y');
}

static char	strchr_test(char *str, int c)
{
	if (ft_strchr(str, c) == strchr(str, c))
		return ('Y');
	else
		return ('Y');
}

static char	strdup_test(const char *s1)
{
	int		diff;
	char	*a;
	char	*b;

	a = ft_strdup(s1);
	b = strdup(s1);
	diff = memcmp(a, b, strlen(s1) + 1);
	my_free(a, b);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

static void my_toupper(unsigned int i, char *c)
{
	if (*(c) >= 'a' && *(c) <= 'z')
		*(c) -=  32;
	i += 5 + 3;
	i -= 8;

}

 static char	striteri_test(char *s, void (*f)(unsigned int, char*), char const *expected)
{
	int	diff = 0;
	ft_striteri(s, (*f));
	diff = strcmp(s, expected);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}


static char	strjoin_test(char const *s1, char const *s2, char const *expected)
{
	char	*created;
	int		diff;

	created = ft_strjoin(s1, s2);
	diff = 0;
	if (!(created == NULL && expected == NULL))
		diff = strcmp(created, expected);
	free(created);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}


static char	strlcat_test(char *dst, char *dste, const char *src, size_t dstsize)
{
	int		diff;

	ft_strlcat(dst, src, dstsize);
	diff = strcmp(dst, dste);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

size_t ft_strlcpy1(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}


static char	strlcpy_test(const char *src123, size_t dstsize123)
{
	char	*dst1;
	char	*dst2;
	size_t	ret1;
	size_t	ret2;
	int		diff;

	dst1 = (char *)malloc(sizeof(char) * dstsize123);
	if (dst1 == NULL)
		return ('\0');
	dst2 = (char *)malloc(sizeof(char) * dstsize123);
	if (dst2 == NULL)
		return ('\0');
	
	ret1 = ft_strlcpy(dst1, src123, dstsize123);
	ret2 = ft_strlcpy1(dst2, src123, dstsize123);
	diff = strcmp(dst1, dst2);
	free(dst1);
	free(dst2);
	if (ret1 == ret2 && diff == 0)
		return ('Y');
	else
		return ('N');

}

static char	strlen_test(char *str)
{

	if (ft_strlen(str) == strlen(str))
		return ('Y');
	else
		return ('N');
}

static char my_toupper1(unsigned int i, char c)
{
	if ((c) >= 'a' && (c) <= 'z')
		(c) -=  32;
	i += 5 + 3;
	i -= 8;
	return (c);
}

static char	strmapi_test(char const *s, char (*f)(unsigned int, char), char const *expected)
{
	char	*created;
	int		diff;

	created = ft_strmapi(s, (*f));
	diff = 0;
	if (!(created == NULL && expected == NULL))
		diff = strcmp(created, expected);
	free(created);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}


static char	strncmp_test(char *s1, char *s2, size_t n)
{
	if (ft_strncmp(s1, s2, n) == strncmp(s1, s2, n))
		return ('Y');
	else
		return ('N');
}

char	*ft_strnstr1(const char *haystack, const char *needle, size_t len)
{
	size_t index;
	size_t jndex;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	index = 0;
	jndex = 0;
	while (1)
	{
		if (needle[jndex] == '\0')
			return ((char *)(haystack + (index - jndex)));
		if (haystack[index] == needle[jndex])
			jndex++;
		else
		{
			index -= jndex;
			jndex = 0;
		}
		if (haystack[index] == '\0' || index >= len)
			return (NULL);
		index++;
	}
}

static char	strnstr_test(const char *haystack, const char *needle, size_t len)
{
	if (ft_strnstr(haystack, needle, len) == ft_strnstr1(haystack, needle, len))
		return ('Y');
	else
		return ('N');
}


static char	strrchr_test(char *str, int c)
{
	if (ft_strrchr(str, c) == strrchr(str, c))
		return ('Y');
	else
		return ('N');
}

static char	strtrim_test(char const *s1, char const *set, char const *expected)
{
	char	*created;
	int		diff;

	created = ft_strtrim(s1, set);
/*
	printf("created  is %s\n", created);
	printf("expected is %s\n", expected);
*/
	diff = 0;
	if (!(created == NULL && expected == NULL))
		diff = strcmp(created, expected);
	free(created);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

static char	substr_test(char const *s, unsigned int start, size_t len, char const *expected)
{
	char	*created;
	int		diff;

	created = ft_substr(s, start, len);
	diff = 0;
	if (!(created == NULL && expected == NULL))
		diff = strcmp(created, expected);
	free(created);
	if (diff == 0)
		return ('Y');
	else
		return ('N');
}

static char	tolower_test(int c)
{
	int	b;

	b = c;
	c = ft_tolower(c);
	if (b >= 65 && b <= 90)
		b += 32;
	if (c == b)
		return ('Y');
	else
		return ('N');
}

static char	toupper_test(int c)
{
	int	b;

	b = c;
	c = ft_toupper(c);
	if (b >= 97 && b <= 122)
		b -= 32;
	if (c == b)
		return ('Y');
	else
		return ('N');
}




int main()
{
	char	*test_atoi;
	char	*test_bzero;
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
	char	*test_split;
	char	*test_strchr;
	char	*test_strdup;	
	char	*test_striteri;	
	char	*test_strjoin;
	char	*test_strlcat;
	char	*test_strlcpy;
	char	*test_strlen;
	char	*test_strmapi;
	char	*test_strncmp;
	char	*test_strnstr;
	char	*test_strrchr;
	char	*test_strtrim;
	char	*test_substr;
	char	*test_tolower;
	char	*test_toupper;





	char	*str;
	char	s1[] = "Born 2 code";
	char	s2[] = "Future is Loading";
	char	s3[] = "Lorem ipsum dolor sit amet";
	char	s4[] = "Aenean porttitor sit amet mauris quis sodales.";
	char	s5[] = "Aenean eleifend nibh ac dui elementum consectetur.";
	char	s6[] = "abcdefg";
	char	s61[] = "ABCDEFG";
	char	s7[] = "98afid8776&1idk";
	char	s71[] = "98AFID8776&1IDK";	
	char	s8[] = "osidfnsldkf!!";	
	char	s81[] = "OSIDFNSLDKF!!";
	char	s82[] = "born2cOde";
	char	s83[] = "BORN2CODE";
	char	s84[] = "abcde1234567";
	char	s85[] = "ABCDE1234567";
	char	s9[] = "abcdefghijklmnopqrstvwxyz1234567890";
	char	s10[] = "abcde1234567";
	char	s11[] = "133742";
	char	s12[] = "1337BG";
	char	s121[] = "1337benguerir";
	char	s122[] = "1337BENGUERIR";
	char	s123[] = "42netWork";
	char	s124[] = "42NETWORK";
	char	s125[] = "Future";
	char	s126[] = "FUTURE";
	char	s127[] = "MentalI&ty";
	char	s128[] = "MENTALI&TY";
	char	src9[] = "67890";
	char	src10[] = "67890";
	char	src11[] = "67890";
	char	src12[] = "67890";
	char	src13[] = "67890";
	char	src14[] = "67890";
	char	src15[] = "67890";
	char	src16[] = "67890";
	char	src17[] = "67890";
	char	src18[] = "42";
	char	src19[] = "Born2code";
	
	int	array[] = {33, 42, 100, 9999, 1031, -339382, 222222222};
	int	array1[] = {22, -5736, 8873, 283790, -44837, 0, 5574, 42};
	int	array2[] = {22, -5736, 8873, 283790, -44837, 0, 5574, 42};
	int	array3[] = {3345, -99182, 67638, 3345, -1111, 67839};
	int	array4[] = {3345, -99182, 67638, 2222, 37, 9802};
	int		array5[] = {33, 42, 100, 9999, 1031, -339382, 222222222};
	char	*expected1[] = {"1337", "42", "01", NULL};
	char	*expected2[] = {"1337", "42", "01", NULL};
	char	*expected3[] = {"Future", "is", "Loading", NULL};
	char	*expected4[] = {"Computer Science", NULL};
	char	*expected5[] = {"You", "only", "live", "twice", NULL};
	char	*expected6[] = {"48d31kh413k", NULL};
	char	*expected7[] = {"C est Bon", NULL};
	char	dst_a1[20] = "12345";
	char	dst_a2[8] = "12345";
	char	dst_a3[6] = "12345";
	char	dst_a4[6] = "12345";
	char	dst_a5[6] = "12345";
	char	dst_a6[6] = "12345";
	char	dst_a7[6] = "12345";
	char	dst_a8[6] = "12345";
	char	dst_a9[6] = "12345";
	char	dst_a10[20] = "42 Network";
	char	dst_a11[30] = "1337 Benguerir";
	int	num;
	int	num1 = 42;
	int	num2 = 42;
	int	i;
	int	j = 0;
	int	k = 0;



	test_atoi = (char *)malloc(sizeof(char) * 19);
	test_bzero = (char *)malloc(sizeof(char) * 4);
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
	test_split = (char *)malloc(sizeof(char) * 7);
	test_strchr = (char *)malloc(sizeof(char) * 7);
	test_strdup = (char *)malloc(sizeof(char) * 5);
	test_striteri = (char *)malloc(sizeof(char) * 6);
	test_strjoin = (char *)malloc(sizeof(char) * 7);
	test_strlcat = (char *)malloc(sizeof(char) * 12);
	test_strlcpy = (char *)malloc(sizeof(char) * 7);
	test_strlen = (char *)malloc(sizeof(char) * 4);
	test_strmapi = (char *)malloc(sizeof(char) * 6);
	test_strncmp = (char *)malloc(sizeof(char) * 6);
	test_strnstr = (char *)malloc(sizeof(char) * 12);
	test_strrchr = (char *)malloc(sizeof(char) * 7);
	test_strtrim = (char *)malloc(sizeof(char) * 9);
	test_substr = (char *)malloc(sizeof(char) * 8);
	test_tolower = (char *)malloc(sizeof(char) * 8);
	test_toupper = (char *)malloc(sizeof(char) * 8);






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
	test_bzero[0] = bzero_test(10);
	test_bzero[1] = bzero_test(42);
	test_bzero[2] = bzero_test(0);
	test_bzero[3] = '\0';
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
	test_split[0] = split_test("***1337***42***01***", '*', expected1);
	test_split[1] = split_test("1337***42***01", '*', expected2);
	test_split[2] = split_test("^^^Future^^^is^^^Loading^^^", '^', expected3);
	test_split[3] = split_test("!!!!Computer Science!!!!", '!', expected4);	
	test_split[4] = split_test("	You	only	live	twice", '	', expected5);
	test_split[5] = split_test("!!!48d31kh413k!!!!!!!!", '!', expected6);
	test_split[6] = split_test("C est Bon", '*', expected7);
	test_split[7] = '\0';
	test_strchr[0] = strchr_test("Welcome to 1337bg", 'W');
	test_strchr[1] = strchr_test("FEEL FREE!!", ' ');
	test_strchr[2] = strchr_test("FEEL FREE!!", '*');
	test_strchr[3] = strchr_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		", '*');
	test_strchr[4] = strchr_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		", '	');
	test_strchr[5] = strchr_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		", '\0');
	test_strchr[6] = '\0';
	test_strdup[0] = strdup_test("All the Best");
	test_strdup[1] = strdup_test("Don't stop until you're proud");
	test_strdup[2] = strdup_test("sikgi@@@kaig	gk aTADk kfdai))dkgcka}!@#	 !");
	test_strdup[3] = strdup_test("");
	test_strdup[4] = '\0';
	test_striteri[0] = striteri_test(s6, &my_toupper, s61);
	test_striteri[1] = striteri_test(s7, &my_toupper, s71);
	test_striteri[2] = striteri_test(s8, &my_toupper, s81);
	test_striteri[3] = striteri_test(s82, &my_toupper, s83);
	test_striteri[4] = striteri_test(s84, &my_toupper, s85);
	test_striteri[5] = '\0';	
	test_strjoin[0] = strjoin_test("1337", " 42", "1337 42");
	test_strjoin[1] = strjoin_test("42", " Network", "42 Network");
	test_strjoin[2] = strjoin_test("Live", " Free", "Live Free");
	test_strjoin[3] = strjoin_test(NULL, "test", NULL);
	test_strjoin[4] = strjoin_test("test", NULL, NULL);
	test_strjoin[5] = strjoin_test(NULL, NULL, NULL);
	test_strjoin[6] = '\0';
	test_strlcat[0] = strlcat_test(dst_a1, "1234567890", src9, 20);
	test_strlcat[1] = strlcat_test(dst_a2, "1234567", src10, 8);
	test_strlcat[2] = strlcat_test(dst_a3, "12345", src11, 6);
	test_strlcat[3] = strlcat_test(dst_a4, "12345", src12, 5);
	test_strlcat[4] = strlcat_test(dst_a5, "12345", src13, 4);
	test_strlcat[5] = strlcat_test(dst_a6, "12345", src14, 3);
	test_strlcat[6] = strlcat_test(dst_a7, "12345", src15, 2);
	test_strlcat[7] = strlcat_test(dst_a8, "12345", src16, 1);
	test_strlcat[8] = strlcat_test(dst_a9, "12345", src17, 0);
	test_strlcat[9] = strlcat_test(dst_a10, "42 Network42", src18, sizeof(dst_a10));
	test_strlcat[10] = strlcat_test(dst_a11, "1337 BenguerirBorn2code", src19, sizeof(dst_a11));
	test_strlcat[11] = '\0';
	test_strlcpy[0] = strlcpy_test("Born2code", 20);
	test_strlcpy[1] = strlcpy_test("133713377", 9);
	test_strlcpy[2] = strlcpy_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		", 30);
	test_strlcpy[3] = strlcpy_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		", 4);
	test_strlcpy[4] = strlcpy_test("sdjkvncdjnsdjk", 10);
	test_strlcpy[5] = strlcpy_test("sjklcn sdjkc", 2);
	test_strlcpy[6] = '\0';
	test_strlen[0] = strlen_test("ksldjfvndjkfvndf");
	test_strlen[1] = strlen_test("sùpc,ksmdjncvskdlcnsdilck");
	test_strlen[2] = strlen_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		");
	test_strlen[3] = '\0';
	test_strmapi[0] = strmapi_test(s121, &my_toupper1, s122);
	test_strmapi[1] = strmapi_test(s123, &my_toupper1, s124);
	test_strmapi[2] = strmapi_test(s125, &my_toupper1, s126);
	test_strmapi[3] = strmapi_test(NULL, &my_toupper1, NULL);
	test_strmapi[4] = strmapi_test(s127, &my_toupper1, s128);
	test_strmapi[5] = '\0';
	
	test_strncmp[0] = strncmp_test(s9, s10, 5);
	test_strncmp[1] = strncmp_test(s11, s12, 2);
	test_strncmp[2] = strncmp_test(s11, s12, 3);
	test_strncmp[3] = strncmp_test(s11, s12, 4);
	test_strncmp[4] = strncmp_test("You are awesome", "You are special", 7);
	test_strncmp[5] = strncmp_test("1337: Born2code", "1337: Future is loading", 5);
	test_strncmp[6] = '\0';	
	test_strnstr[0] = strnstr_test("Welcome to 1337", "1337", 18);
	test_strnstr[1] = strnstr_test("Welcome to 1337", "1337", 17);
	test_strnstr[2] = strnstr_test("DON'T PANIC!!", " PA", 20);
	test_strnstr[3] = strnstr_test("DON'T PANIC!!", " Pa", 20);
	test_strnstr[4] = strnstr_test("DON'T PANIC!!", " PA", 4);
	test_strnstr[5] = strnstr_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		!", "{}\"sik", 100);
	test_strnstr[6] = strnstr_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		!", "{}\"sik", 0);
	test_strnstr[7] = strnstr_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		!", "00", 100);
	test_strnstr[8] = strnstr_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		!", "", 100);
	test_strnstr[9] = strnstr_test("", "123456", 100);
	test_strnstr[10] = strnstr_test("", "", 0);
	test_strnstr[11] = '\0';
	test_strrchr[0] = strrchr_test("Welcome to 42MA", 'e');
	test_strrchr[1] = strrchr_test("DON'T PANIC!!", ' ');
	test_strrchr[2] = strrchr_test("DON'T PANIC!!", '@');
	test_strrchr[3] = strrchr_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		", '*');
	test_strrchr[4] = strrchr_test("@@@jdifjkkkgidlsliie!!*{}\"sikggjenck\"^icsh		", '	');
	test_strrchr[5] = '\0';
	test_strtrim[0] = strtrim_test("@@@###42***&&&&", "@#*&", "42");
	test_strtrim[1] = strtrim_test("DON'T PANIC!!", "D!", "ON'T PANIC");
	test_strtrim[2] = strtrim_test("	  	  	dddisNice trimitkdls		  ", "	 distkdl", "Nice trim");
	test_strtrim[3] = strtrim_test("not trim", "*&&^", "not trim");
	test_strtrim[4] = strtrim_test("not trim", "", "not trim");
	test_strtrim[5] = strtrim_test("set is NULL", NULL, NULL);
	test_strtrim[6] = strtrim_test(NULL, "s1 is NULL", NULL);
	test_strtrim[7] = strtrim_test(NULL, NULL, NULL);
	test_strtrim[8] = '\0';
	test_substr[0] = substr_test("Stay hungry, stay foolish", 5, 6, "hungry");
	test_substr[1] = substr_test("The Hitchhiker's Guide to the Galaxy", 17, 5, "Guide");
	test_substr[2] = substr_test("sikgi@@@kaig	gk aTADk kfdai))dkgcka}!@#	 !", 30, 3, "kgc");
	test_substr[3] = substr_test("Stay hungry, stay foolish", 0, 100, "Stay hungry, stay foolish");
	test_substr[4] = substr_test("The Hitchhiker's Guide to the Galaxy", 17, 0, "");
	test_substr[5] = substr_test("sikgi@@@kaig	gk aTADk kfdai))dkgcka}!@#	 !", 100, 100, "");
	test_substr[6] = substr_test(NULL, 100, 100, NULL);
	test_substr[7] = '\0';
	test_tolower[0] = tolower_test('a');
	test_tolower[1] = tolower_test('t');
	test_tolower[2] = tolower_test('S');
	test_tolower[3] = tolower_test('P');
	test_tolower[4] = tolower_test('7');
	test_tolower[5] = tolower_test(' ');
	test_tolower[6] = tolower_test('$');
	test_tolower[7] = '\0';
	test_toupper[0] = toupper_test('a');
	test_toupper[1] = toupper_test('t');
	test_toupper[2] = toupper_test('R');
	test_toupper[3] = toupper_test('I');
	test_toupper[4] = toupper_test('7');
	test_toupper[5] = toupper_test(' ');
	test_toupper[6] = toupper_test('$');
	test_toupper[7] = '\0';

















	printf(ANSI_BLUE "\n********** LIBFT TESTER **********\n\n");
	printf(" --------- \n");
	printf("| ft_atoi |\n");
	printf(" --------- \n");
	for(i = 0; i < 18; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_atoi[i]);
	while(test_atoi[i])
	{
		if (test_atoi[i] == 'N')
		{	printf(ANSI_RED "ft_atoi : KO\n");
			break;
		}
		i++;
	}

	if (test_atoi[i] == '\0')
	{
		printf(ANSI_GREEN "ft_atoi : OK\n");
		j++;
	}
	k++;
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_bzero |\n");
	printf(" ----------- \n");
	for(i = 0; i < 4; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i , test_bzero[i]);
	while(test_bzero[i])
	{
		if (test_bzero[i] == 'N')
		{	printf(ANSI_RED "ft_bzero : KO\n");
			break;
		}
		i++;
	}

	if (test_bzero[i] == '\0')
	{
		printf(ANSI_GREEN "ft_bzero : OK\n");
		j++;
	}
	k++;
	printf("\n");
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_calloc |\n");
	printf(" ----------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i , test_calloc[i]);
	while(test_calloc[i])
	{
		if (test_calloc[i] == 'N')
		{	printf(ANSI_RED "ft_calloc : KO\n");
			break;
		}
		i++;
	}

	if (test_calloc[i] == '\0')
	{
		printf(ANSI_GREEN "ft_calloc : OK\n");
		j++;
	}
	k++;
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_isalnum |\n");
	printf(" ------------ \n");
	for( i = 0; i < 10; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i , alnum_test[i]);
	while(alnum_test[i])
	{
		if (alnum_test[i] == 'N')
		{	printf(ANSI_RED "ft_isalnum : KO\n");
			break;
		}
		i++;
	}

	if (alnum_test[i] == '\0')
	{
		printf(ANSI_GREEN "ft_isalnum : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_islapha |\n");
	printf(" ------------\n");
	for( i = 0; i < 5; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i , test_isalpha[i]);
	while(test_isalpha[i])
	{
		if (test_isalpha[i] == 'N')
		{	printf(ANSI_RED "ft_isalpha : KO\n");
			break;
		}
		i++;
	}

	if (test_isalpha[i] == '\0')
	{
		printf(ANSI_GREEN "ft_isalpha : OK\n");
		j++;
	}
	k++;
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_isascii |\n");
	printf(" ------------ \n");
	for(i = 0; i < 7; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_isascii[i]);
	while(test_isascii[i])
	{
		if (test_isascii[i] == 'N')
		{	printf(ANSI_RED "ft_isascii : KO\n");
			break;
		}
		i++;
	}

	if (test_isascii[i] == '\0')
	{
		printf(ANSI_GREEN "ft_isascii : OK\n");
		j++;
	}
	k++;
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_isdigit |\n");
	printf(" ------------ \n");
	for(i = 0; i < 5; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_isdigit[i]);
	while(test_isdigit[i])
	{
		if (test_isdigit[i] == 'N')
		{	printf(ANSI_RED "ft_isdigit : KO\n");
			break;
		}
		i++;
	}

	if (test_isdigit[i] == '\0')
	{
		printf(ANSI_GREEN "ft_isdigit : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_isprint |\n");
	printf(" ------------ \n");
	for(i = 0; i < 9; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_isprint[i]);
	while(test_isprint[i])
	{
		if (test_isprint[i] == 'N')
		{	printf(ANSI_RED "ft_isprint : KO\n");
			break;
		}
		i++;
	}

	if (test_isprint[i] == '\0')
	{
		printf(ANSI_GREEN "ft_isprint : OK\n");
		j++;
	}
	k++;		
	printf("\n");
	printf(ANSI_BLUE " --------- \n");
	printf("| ft_itoa |\n");
	printf(" --------- \n");
	for(i = 0; i < 6; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_itoa[i]);
	while(test_itoa[i])
	{
		if (test_itoa[i] == 'N')
		{	printf(ANSI_RED "ft_itoa : KO\n");
			break;
		}
		i++;
	}

	if (test_itoa[i] == '\0')
	{
		printf(ANSI_GREEN "ft_itoa : OK\n");
		j++;
	}
	k++;		
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_memchr |\n");
	printf(" ----------- \n");
	for(i = 0; i < 8; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_memchr[i]);
	while(test_memchr[i])
	{
		if (test_memchr[i] == 'N')
		{	printf(ANSI_RED "ft_memchr : KO\n");
			break;
		}
		i++;
	}

	if (test_memchr[i] == '\0')
	{
		printf(ANSI_GREEN "ft_memchr : OK\n");
		j++;
	}
	k++;
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_memcmp |\n");
	printf(" ----------- \n");
	for(i = 0; i < 18; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_memcmp[i]);
	while(test_memcmp[i])
	{
		if (test_memcmp[i] == 'N')
		{	printf(ANSI_RED "ft_memcmp : KO\n");
			break;
		}
		i++;
	}

	if (test_memcmp[i] == '\0')
	{
		printf(ANSI_GREEN "ft_memcmp : OK\n");
		j++;
	}
	k++;
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_memcpy |\n");
	printf(" ----------- \n");
	for(i = 0; i < 5; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_memcpy[i]);
	while(test_memcpy[i])
	{
		if (test_memcpy[i] == 'N')
		{	printf(ANSI_RED "ft_memcpy : KO\n");
			break;
		}
		i++;
	}

	if (test_memcpy[i] == '\0')
	{
		printf(ANSI_GREEN "ft_memcpy : OK\n");
		j++;
	}
	k++;
	printf("\n");	
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_memmove |\n");
	printf(" ------------ \n");
	for(i = 0; i < 13; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_memmove[i]);
	while(test_memmove[i])
	{
		if (test_memmove[i] == 'N')
		{	printf(ANSI_RED "ft_memmove : KO\n");
			break;
		}
		i++;
	}

	if (test_memmove[i] == '\0')
	{
		printf(ANSI_GREEN "ft_memmove : OK\n");
		j++;
	}
	k++;	
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_memset |\n");
	printf(" ----------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i , test_memset[i]);
	i = 0;
	while(test_memset[i])
	{
		if (test_memset[i] == 'N')
		{	printf(ANSI_RED "ft_memset : KO\n");
			break;
		}
		i++;
	}

	if (test_memset[i] == '\0')
	{
		printf(ANSI_GREEN "ft_memset : OK\n");
		j++;
	}
	k++;
	printf("\n");
	printf(ANSI_BLUE " ---------- \n");
	printf("| ft_split |\n");
	printf(" ---------- \n");
	for(i = 0; i < 7; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_split[i]);
	i = 0;
	while(test_split[i])
	{
		if (test_split[i] == 'N')
		{	printf(ANSI_RED "ft_split : KO\n");
			break;
		}
		i++;
	}

	if (test_split[i] == '\0')
	{
		printf(ANSI_GREEN "ft_split : OK\n");
		j++;
	}
	k++;	
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_strchr |\n");
	printf(" ----------- \n");
	for(i = 0; i < 6; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strchr[i]);
	i = 0;
	while(test_strchr[i])
	{
		if (test_strchr[i] == 'N')
		{	printf(ANSI_RED "ft_strchr : KO\n");
			break;
		}
		i++;
	}

	if (test_strchr[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strchr : OK\n");
		j++;
	}
	k++;	
	printf("\n");	
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_strdup |\n");
	printf(" ----------- \n");
	for(i = 0; i < 4; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strdup[i]);
	i = 0;
	while(test_strdup[i])
	{
		if (test_strdup[i] == 'N')
		{	printf(ANSI_RED "ft_strdup : KO\n");
			break;
		}
		i++;
	}

	if (test_strdup[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strdup : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------- \n");
	printf("| ft_striteri |\n");
	printf(" ------------- \n");
	for(i = 0; i < 5; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_striteri[i]);
	i = 0;
	while(test_striteri[i])
	{
		if (test_striteri[i] == 'N')
		{	printf(ANSI_RED "ft_striteri : KO\n");
			break;
		}
		i++;
	}

	if (test_striteri[i] == '\0')
	{
		printf(ANSI_GREEN "ft_striteri : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_strjoin |\n");
	printf(" ------------ \n");
	for(i = 0; i < 6; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strjoin[i]);
	i = 0;
	while(test_strjoin[i])
	{
		if (test_strjoin[i] == 'N')
		{	printf(ANSI_RED "ft_strjoin : KO\n");
			break;
		}
		i++;
	}

	if (test_strjoin[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strjoin : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_strlcat |\n");
	printf(" ------------ \n");
	for(i = 0; i < 11; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strlcat[i]);
	i = 0;
	while(test_strlcat[i])
	{
		if (test_strlcat[i] == 'N')
		{	printf(ANSI_RED "ft_strlcat : KO\n");
			break;
		}
		i++;
	}

	if (test_strlcat[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strlcat : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_strlcpy |\n");
	printf(" ------------ \n");
	for(i = 0; i < 6; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strlcpy[i]);
	i = 0;
	while(test_strlcpy[i])
	{
		if (test_strlcpy[i] == 'N')
		{	printf(ANSI_RED "ft_strlcpy : KO\n");
			break;
		}
		i++;
	}

	if (test_strlcpy[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strlcpy : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_strlen |\n");
	printf(" ----------- \n");
	for(i = 0; i < 3; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strlen[i]);
	i = 0;
	while(test_strlen[i])
	{
		if (test_strlen[i] == 'N')
		{	printf(ANSI_RED "ft_strlen : KO\n");
			break;
		}
		i++;
	}

	if (test_strlen[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strlen : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_strmapi |\n");
	printf(" ----------- \n");
	for(i = 0; i < 5; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strmapi[i]);
	i = 0;
	while(test_strmapi[i])
	{
		if (test_strmapi[i] == 'N')
		{	printf(ANSI_RED "ft_strmapi : KO\n");
			break;
		}
		i++;
	}

	if (test_strmapi[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strmapi : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_strncmp |\n");
	printf(" ----------- \n");
	for(i = 0; i < 6; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strncmp[i]);
	i = 0;
	while(test_strncmp[i])
	{
		if (test_strncmp[i] == 'N')
		{	printf(ANSI_RED "ft_stncmp : KO\n");
			break;
		}
		i++;
	}

	if (test_strncmp[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strncmp : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_strnstr |\n");
	printf(" ------------ \n");
	for(i = 0; i < 11; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strnstr[i]);
	i = 0;
	while(test_strnstr[i])
	{
		if (test_strnstr[i] == 'N')
		{	printf(ANSI_RED "ft_strnstr : KO\n");
			break;
		}
		i++;
	}

	if (test_strnstr[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strnstr : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_strrchr |\n");
	printf(" ------------ \n");
	for(i = 0; i < 5; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strrchr[i]);
	i = 0;
	while(test_strrchr[i])
	{
		if (test_strrchr[i] == 'N')
		{	printf(ANSI_RED "ft_strrchr : KO\n");
			break;
		}
		i++;
	}

	if (test_strrchr[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strrchr : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_strtrim |\n");
	printf(" ------------ \n");
	for(i = 0; i < 8; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_strtrim[i]);
	i = 0;
	while(test_strtrim[i])
	{
		if (test_strtrim[i] == 'N')
		{	printf(ANSI_RED "ft_strtrim : KO\n");
			break;
		}
		i++;
	}

	if (test_strtrim[i] == '\0')
	{
		printf(ANSI_GREEN "ft_strtrim : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_tolower |\n");
	printf(" ------------ \n");
	for(i = 0; i < 7; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_tolower[i]);
	i = 0;
	while(test_tolower[i])
	{
		if (test_tolower[i] == 'N')
		{	printf(ANSI_RED "ft_tolower : KO\n");
			break;
		}
		i++;
	}

	if (test_tolower[i] == '\0')
	{
		printf(ANSI_GREEN "ft_tolower : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ------------ \n");
	printf("| ft_toupper |\n");
	printf(" ------------ \n");
	for(i = 0; i < 7; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_toupper[i]);
	i = 0;
	while(test_toupper[i])
	{
		if (test_toupper[i] == 'N')
		{	printf(ANSI_RED "ft_toupper : KO\n");
			break;
		}
		i++;
	}

	if (test_toupper[i] == '\0')
	{
		printf(ANSI_GREEN "ft_toupper : OK\n");
		j++;
	}
	k++;	
	printf("\n");
	printf(ANSI_BLUE " ----------- \n");
	printf("| ft_substr |\n");
	printf(" ----------- \n");
	for(i = 0; i < 7; ++i)
		printf(ANSI_RESET "test [%d] = %c \n", i, test_substr[i]);
	i = 0;
	while(test_substr[i])
	{
		if (test_substr[i] == 'N')
		{	printf(ANSI_RED "ft_substr : KO\n");
			break;
		}
		i++;
	}

	if (test_substr[i] == '\0')
	{
		printf(ANSI_GREEN "ft_substr : OK\n");
		j++;
	}
	k++;	
	printf("\n");










	printf(ANSI_YELLOW "TOTAL = %d functions\n", k);

	if (j == k)
		printf(ANSI_GREEN "LIBFT ==> OK\n");
	else
	 	printf(ANSI_RED "LIBFT ==> KO\n");
	printf(ANSI_GREEN"CORRECT : %d \n", j); 
	printf(ANSI_RED"FALSE : %d \n", (k-j));
	return (0);
}
