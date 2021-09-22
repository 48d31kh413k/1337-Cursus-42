#include "libft.h"

static int	check_sep(char const a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

static int	count_word(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_sep(str[i], c))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_sep(str[i], c))
			i++;
	}
	return (count);
}

static int	len_sep(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !check_sep(str[i], c))
		i++;
	return (i);
}

static char	*string(char const *str, char c)
{
	int		length_string;
	int		i;
	char	*word;

	i = 0;
	length_string = len_sep(str, c);
	word = (char *)malloc(sizeof(char) * (length_string + 1));
	while (i < length_string)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	while (*s != '\0')
	{
		while (*s != '\0' && check_sep(*s, c))
			s++;
		if (*s != '\0')
		{
			array[i] = string(s, c);
			i++;
		}
		while (*s && !check_sep(*s, c))
			s++;
	}
	array[i] = '\0';
	return (array);
}
