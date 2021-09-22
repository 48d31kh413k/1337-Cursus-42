#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new || !s)
		return (NULL);
	while (s[start + i] && i < len && start < ft_strlen((char *)s))
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
