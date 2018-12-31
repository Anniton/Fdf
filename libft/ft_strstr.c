/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:25:04 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/13 12:52:40 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule, const char *aig)
{
	char	*m;
	size_t	i;
	size_t	j;

	m = (char *)meule;
	i = 0;
	j = 0;
	if (*aig == '\0')
		return (m);
	while (m[i] != '\0')
	{
		while (m[i + j] == aig[j])
		{
			j++;
			if (j == ft_strlen(aig))
				return (m + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
