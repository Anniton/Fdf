/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:21:55 by aquan             #+#    #+#             */
/*   Updated: 2019/01/09 12:48:51 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_iso_press(int key, t_struct *start)
{

	ft_putnbr(key);
	if (key == 83)
		afficher(start);
	if (key == 84)
		afficher_pc(start);
	return (0);
}

