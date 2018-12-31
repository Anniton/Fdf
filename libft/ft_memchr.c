/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 08:22:22 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/14 10:04:45 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*l;

	i = 0;
	l = (unsigned char *)s;
	while (i < n)
	{
		if (l[i] == (unsigned char)c)
			return (&l[i]);
		i++;
	}
	return (NULL);
}
