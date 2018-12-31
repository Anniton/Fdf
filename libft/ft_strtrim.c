/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:22:39 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/14 08:48:16 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int d;
	unsigned int f;

	if (!s)
		return (NULL);
	if (!*s)
		return ((char *)s);
	d = 0;
	f = ft_strlen(s) - 1;
	while (s[d] == ' ' || s[d] == '\t' || s[d] == '\n')
		d++;
	if (d == ft_strlen(s))
		return (ft_strsub(s, d, f));
	while (s[f] == ' ' || s[f] == '\t' || s[f] == '\n')
		f--;
	return (ft_strsub(s, d, (f - d + 1)));
}
