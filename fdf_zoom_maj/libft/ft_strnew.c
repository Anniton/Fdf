/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 08:06:35 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/14 14:20:19 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*r;
	size_t	i;

	i = 0;
	r = (char*)malloc(sizeof(char) * size + 1);
	if (!r)
		return (NULL);
	while (i <= size)
	{
		r[i] = '\0';
		i++;
	}
	return (r);
}
