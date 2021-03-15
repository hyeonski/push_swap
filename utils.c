#include "utils.h"

void	*alloc_int(int data)
{
	int		*p;

	p = (int *)malloc(sizeof(int));
	if (p == NULL)
		return (NULL);
	*p = data;
	return ((void *)p);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((unsigned char)s2[i] != (unsigned char)s1[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_str_digit(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_str_int_range(char *str)
{
	int	len;
	int	ret;

	ret = 0;
	len = ft_strlen(str);
	if (len > 11)
		return (0);
	if (len >= 10)
	{
		if (len == 11)
			if (*str != '-')
				return (0);
		if (*str == '-')
			ret = ft_strcmp("-2147483648", str);
		else
			ret = ft_strcmp("2147483647", str);
		if (ret < 0)
			return (0);
	}
	return (1);
}

int	cmp_element(int *a, int *b)
{
	return (*a - *b);
}
