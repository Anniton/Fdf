/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:49:42 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/26 13:36:13 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(*new) * len + 1)))
		return (NULL);
	while (*s1 != '\0')
		*new++ = *s1++;
	while (*s2 != '\0')
		*new++ = *s2++;
	*new = '\0';
	return (new - len);
}
