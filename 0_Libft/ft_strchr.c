#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if ((char)c == '\0')
		return (0);
	while (str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (0);
}
