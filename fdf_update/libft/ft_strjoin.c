/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:25:26 by loucarpe          #+#    #+#             */
/*   Updated: 2019/02/06 22:03:49 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_memset(str, '\0',(ft_strlen(s1) + ft_strlen(s2) + 1));
	str = ft_strcpy(str, (char*)s1);
	str = ft_strcat(str, (char*)s2);
	return (str);
}
