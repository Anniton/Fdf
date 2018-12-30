/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 10:47:18 by aquan             #+#    #+#             */
/*   Updated: 2018/12/29 10:48:12 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"

int	key_hook(int key, t_param *e)
{
	ft_putnbr(key);
	if (key == KEY_ESC)
	{
		free(e);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
