#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[i])
	{
		new[i] = s2[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
