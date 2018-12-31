/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:22:36 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/15 08:40:22 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*new;
	size_t	i;

	i = 0;
	if (n < ft_strlen(s))
		new = (char *)malloc(sizeof(*new) * n + 1);
	else
		new = (char *)malloc(sizeof(*new) * ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	while (i < n && s)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
