/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:59:57 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/13 13:05:47 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int					i;
	unsigned int		s;
	char				*nb;

	i = 1;
	s = (n > 0) ? n : -n;
	if (n < 0)
		i++;
	while (s /= 10)
		i++;
	s = (n > 0) ? n : -n;
	nb = ft_strnew(i);
	if (nb == NULL)
		return (NULL);
	nb[0] = (n < 0) ? '-' : '0';
	while (s)
	{
		i--;
		nb[i] = s % 10 + '0';
		s = s / 10;
	}
	return (nb);
}
