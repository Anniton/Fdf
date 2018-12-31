/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:38:50 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/05 14:44:35 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int i;
	int res;
	int sign;

	i = 0;
	res = 0;
	sign = 0;
	while (nptr[i] != '\0' && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	if (sign == -1)
		return (-res);
	return (res);
}
