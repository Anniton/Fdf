/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:24:51 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/26 10:16:32 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	find_it(char s, const char *charset)
{
	while (*charset)
	{
		if (!(*charset - s))
			return (1);
		charset++;
	}
	return (0);
}

int			ft_strcspn(const char *s, const char *charset)
{
	int i;

	i = 0;
	while (s[i] && !(find_it(s[i], charset)))
		i++;
	if (!s[i])
		return (-1);
	return (i);
}
