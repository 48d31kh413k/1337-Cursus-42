#include "libft.h"

static int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*int_to_char(char *str, int nb, int nb_len)
{
	while (nb > 0)
	{
		str[nb_len] = 48 + (nb % 10);
		nb /= 10;
		nb_len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		nb_len;

	nb = n;
	nb_len = len(nb);
	str = (char *)malloc(nb_len + 1);
	if (!str)
		return (0);
	str[nb_len--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	str = int_to_char(str, nb, nb_len);
	return (str);
}
