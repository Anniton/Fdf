/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:41:28 by loucarpe          #+#    #+#             */
/*   Updated: 2019/02/08 21:56:03 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!s || (c < 0 && c > 127))
		return (NULL);
	tmp = (char*)s;
	if (c == '\0')
		return (tmp + ft_strlen(tmp));
	while (tmp[i])
	{
		if (tmp[i] == c)
		{
			tmp = tmp + i;
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

