/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:54:19 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/10 17:10:07 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*new;

	new = (char *)malloc(sizeof(*new) * size);
	if (new == NULL)
		return (NULL);
	return (ft_memset(new, '\0', size));
}
