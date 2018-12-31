/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:27:00 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/14 09:32:06 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	size_t	length;

	length = ft_strlen(s);
	r = (char *)s;
	if (c == '\0')
		return ((char *)s + length);
	r = (r + length) - 1;
	while (length > 0)
	{
		if (*r == c)
			return (r);
		r--;
		length--;
	}
	return (NULL);
}
