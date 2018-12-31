/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:17:59 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/14 11:48:14 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (-1);
	if (!ft_strcmp(s1, s2))
		return (1);
	else
		return (0);
}