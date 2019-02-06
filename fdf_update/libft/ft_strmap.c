/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:07:50 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/14 14:09:50 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*r;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	r = malloc(sizeof(*r) * (i + 1));
	if (!r)
		return (NULL);
	while (*s)
	{
		*r = f(*s);
		r++;
		s++;
	}
	*r = '\0';
	return (r - i);
}
