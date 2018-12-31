/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:40:45 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/26 10:17:50 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char const *s1, unsigned int go, size_t len)
{
	char *ret;

	if (!s1 || !go || !len)
		return (NULL);
	if (!(ret = ft_strsub(s1, go, len)))
		return (NULL);
	ft_strdel((char**)&s1);
	return (ret);
}
