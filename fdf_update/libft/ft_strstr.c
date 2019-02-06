/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:43:30 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/14 15:23:17 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if (!(i = ft_strlen(needle)))
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle && !(ft_memcmp(haystack, needle, i)))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
