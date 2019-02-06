/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:52:14 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/14 15:25:40 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hays, const char *needle, size_t n)
{
	size_t i;

	if (!(i = ft_strlen(needle)))
		return ((char*)hays);
	while (*hays && n-- >= i)
	{
		if (*hays == *needle && !(ft_memcmp(hays, needle, i)))
			return ((char*)hays);
		hays++;
	}
	return (NULL);
}
