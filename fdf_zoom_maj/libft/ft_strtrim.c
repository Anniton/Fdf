/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:34:34 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/15 08:55:14 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*r;
	int		i;
	int		j;
	int		l;

	if (!s)
		return (NULL);
	if (!*s)
		return ((char*)s);
	l = ft_strlen(s);
	j = l - 1;
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	while (s[j] == '\t' || s[j] == '\n' || s[j] == ' ')
		j--;
	if (!(r = (char *)malloc(sizeof(char) * ((i == l ? l + 1 : j - i + 2)))))
		return (NULL);
	l = 0;
	while (i <= j)
		r[l++] = s[i++];
	r[l] = '\0';
	return (r);
}
