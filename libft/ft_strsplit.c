/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:36:26 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/19 15:54:55 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	if (s[0] != c && s[0] != '\0')
		j = 1;
	else
		j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			if (s[i + 1] != c && s[i + 1] != '\0')
				j++;
		i++;
	}
	return (j);
}

static char	*ft_mini_strdup(char const *s, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	dest = (char*)malloc(sizeof(*dest) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(*tab) * (ft_words(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			tab[j] = ft_mini_strdup(&s[i], c);
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
