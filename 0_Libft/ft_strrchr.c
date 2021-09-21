#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		length;

	length = ft_strlen(s);
	str = (char *)s;
	if ((char)c == '\0')
		return (0);
	while (length > 0)
	{
		if (str[length] == (char)c)
			return (str + length);
		length--;
	}
	return (0);
}
