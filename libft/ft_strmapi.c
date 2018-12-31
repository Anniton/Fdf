/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:07:14 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/14 11:37:31 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	size_t			i;
	unsigned int	j;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	new = (char *)malloc(sizeof(*new) * i + 1);
	if (new == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		new[j] = f(j, s[j]);
		j++;
	}
	new[j] = '\0';
	return (new);
}
