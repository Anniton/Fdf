/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:21:40 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/14 11:49:02 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (-1);
	if (!ft_strncmp(s1, s2, n))
		return (1);
	else
		return (0);
}
