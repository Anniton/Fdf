/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:43:22 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/14 14:35:16 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*r;

	i = ft_strlen(s);
	r = (char *)s;
	while (i >= 0)
	{
		if (r[i] == c)
			return (&r[i]);
		i--;
	}
	return (NULL);
}
