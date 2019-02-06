/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:17:42 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/14 14:05:28 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	while (*s && len != 0)
	{
		r[i] = s[start];
		i++;
		start++;
		len--;
	}
	r[i] = '\0';
	return (r);
}
