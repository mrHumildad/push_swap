#include "push_swap.h"

static void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		*(char *)str = '\0';
		str++;
		i++;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*res;

	res = malloc(nitems * size);
	if (!res)
		return (0);
	ft_bzero(res, nitems * size);
	return (res);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size < 1)
		return (len);
	while (src[i] != '\0' && i < size -1)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (len);
}
