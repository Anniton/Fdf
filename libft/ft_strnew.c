/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 08:20:54 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/14 13:30:27 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(sizeof(*new) * size + 1);
	if (new == NULL)
		return (NULL);
	while (i <= size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
