/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:37:55 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/26 10:17:02 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char *ret;

	if (!(ret = ft_strjoin(s1, s2)))
		return (NULL);
	ft_strdel((char**)&s1);
	return (ret);
}
