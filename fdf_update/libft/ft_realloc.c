/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loucarpe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 09:56:06 by loucarpe          #+#    #+#             */
/*   Updated: 2018/11/21 14:10:57 by loucarpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_realloc(char *buff, size_t size)
{
	char	*tmp;

	tmp = ft_strdup(buff);
	if (!(buff = (char *)malloc(sizeof(char) * (size + 1))))
		return ;
	ft_strcpy(buff, tmp);
	free(tmp);
}
