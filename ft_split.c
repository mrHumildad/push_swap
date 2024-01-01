/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:57:19 by mnotaro           #+#    #+#             */
/*   Updated: 2023/11/19 17:24:15 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	wc(const char *s, char x)
{
	int	words;
	int	isword;
	int	i;

	i = 0;
	words = 0;
	isword = 0;
	while (s[i] && s[i] == x)
		i++;
	while (s[i])
	{
		if (s[i] != x)
		{
			if (isword == 0)
			{
				words += 1;
				isword = 1;
			}
		}
		else
			isword = 0;
		i++;
	}
	return (words);
}

static int	wlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

void	freeall(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		i++;
	}
	while (i >= 0)
		free(res[i--]);
	free(res);
}

static char	**justfornormi(char const *s, char c, char **res)
{
	int	wi;

	wi = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			res[wi] = (char *)ft_calloc(sizeof(char), wlen(s, c) + 1);
			if (!res[wi])
			{
				freeall(res);
				return (NULL);
			}
			ft_strlcpy(res[wi], (char *)s, wlen(s, c) + 1);
			wi++;
			while (*s && *s != c)
				s++;
		}
	}
	res[wi] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)ft_calloc(sizeof(char *), wc(s, c) + 1);
	if (!res)
		return (NULL);
	res = justfornormi(s, c, res);
	return (res);
}
