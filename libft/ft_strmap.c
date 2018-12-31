/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:27:48 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/14 11:36:38 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	new = (char *)malloc(sizeof(*new) * i + 1);
	if (new == NULL)
		return (NULL);
	while (*s != '\0')
	{
		*new = f(*s);
		s++;
		new++;
	}
	*new = '\0';
	return (new - i);
}
