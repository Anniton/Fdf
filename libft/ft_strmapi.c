/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 08:46:47 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/19 15:43:12 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*r;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	r = malloc(sizeof(*r) * (i + 1));
	if (!r)
		return (NULL);
	while (*s)
	{
		*r = f(j, *s);
		r++;
		s++;
		j++;
	}
	*r = '\0';
	return (r - i);
}
