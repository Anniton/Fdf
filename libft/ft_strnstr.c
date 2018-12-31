/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:46:56 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/11 09:42:50 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule, const char *aiguille, size_t len)
{
	char	*m;
	size_t	i;
	size_t	j;

	m = (char *)meule;
	i = 0;
	j = 0;
	if (*aiguille == '\0')
		return (m);
	while (m[i] != '\0' && i < len)
	{
		while (m[i + j] == aiguille[j] && i + j < len)
		{
			j++;
			if (j == ft_strlen(aiguille))
				return (m + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
