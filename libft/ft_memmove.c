/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 07:34:34 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/14 09:26:16 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)src;
	if (!n || s == d)
		return (dest);
	else if (s > d)
		ft_memcpy(d, s, n);
	else
		while (n--)
			d[n] = s[n];
	return (d);
}
